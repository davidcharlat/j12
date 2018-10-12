#include <utmp.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "include.h"

void	fill_endline_logout (int tmp1, int tmp2, char line[77])
{
	int	d;
	int	step;

	d = (tmp2 - tmp1) / 60 / 1440;
	step = (d + 9998) / 9999 + (d + 9989) / 9999 + (d + 9899) / 9999 + (d + 8999) / 9999;
	if (step < 5)
	{
		line[61 + step] = d / 100 % 10 + '0';
		line[62 + step] = d / 100 % 10 + '0';
		line[63 + step] = d / 10 % 10 + '0';
		line[64 + step] = d % 10 + '0';
		line[65 + step] = '+';
		line[66 + step] = ((tmp2 - tmp1) / 3600 % 24) / 10 + '0';
		line[67 + step] = ((tmp2 - tmp1) / 3600 % 24) % 10 + '0';
		line[68 + step] = ':';
		line[69 + step] = ((tmp2 - tmp1) / 600 % 6) + '0';
		line[70 + step] = (tmp2 - tmp1) / 60 % 10 + '0';
		line[71 + step] = ')';
		line[63] = ' ';
		line[64] = '(';
		if (d == 0)
			line[64] = ' ';
		if (d == 0)	
			line[65] = '(';
	}
}

void	fill_line_logout (struct utmp login, struct utmp logout, char line[77])
{
	int i;
	int tmp;
	
	tmp = logout.ut_time - __timezone + 3600 * __daylight;
	i = 0;
	while (i < 8 && login.ut_user[i])
		line [i] = login.ut_user[i++];
	i = 0;
	while (i < 12 && login.ut_line[i])
		line [i + 9] = login.ut_line[i++];
	i = 0;
	while (i < 16 && login.ut_id[i])
		line [i + 22] = login.ut_id[i++];
	fill_time ((int32_t)login.ut_time, line);
	fill_endline_logout ((int)login.ut_time, (int)logout.ut_time, line);
	line [56] = '-';
	line [60] = ':';
	line [62] = (tmp / 60 % 10) + '0';
	line [61] = (tmp / 600 % 6) + '0';
	line [59] = (tmp / 3600 % 24) % 10 + '0';
	line [58] = (tmp / 3600 % 24) / 10 + '0';
}

void	fill_endline_reboot (struct utmp login, char line[77])
{
	int		i;
	char	reboot[] = "system boot";
	char	reboot_gone[] = "still running";
	
	i = 0;
	while (i < 11)
		line [i + 9] = reboot[i++];
	i = 0;
	while (i < 16 && login.ut_host[i])
		line [i + 22] = login.ut_host[i++];
	fill_time ((int32_t)login.ut_time, line);
	i = 0;
	while (i < 13)
		line [i + 58] = reboot_gone[i++];
}

void	fill_line_gone (struct utmp login, char line[77])
{
	int		i;
	char	user_gone[] = "gone - no logout"; 
	
	i = 0;
	while (i < 8 && login.ut_user[i])
		line [i] = login.ut_user[i++];
	i = 0;
	if (login.ut_type == 7)
	{
		while (i < 12 && login.ut_line[i])
			line [i + 9] = login.ut_line[i++];
		i = 0;
		while (i < 16 && login.ut_id[i])
			line [i + 22] = login.ut_id[i++];
		fill_time ((int32_t)login.ut_time, line);
		i = 0;
		while (i < 17)
			line [i + 59] = user_gone[i++];
	}
	else if (login.ut_type == 2)
		fill_endline_reboot(login, line);
}
