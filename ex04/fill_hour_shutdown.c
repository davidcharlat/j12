#include <utmp.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "include.h"

void	fill_hour_shutdown (int tmp, struct utmp login,  char line[77])
{
	int		i;
	char	down[] = "down ";
	
	tmp = tmp - __timezone + 3600 * __daylight;
	line [56] = '-';
	line [60] = ':';
	line [62] = (tmp / 60 % 10) + '0';
	line [61] = (tmp / 600 % 6) + '0';
	line [59] = (tmp / 3600 % 24) % 10 + '0';
	line [58] = (tmp / 3600 % 24) / 10 + '0';
	if (ft_strcmp("reboot", login.ut_user))
	{
		i = 0;
		while (i < 5)
			line [i + 58] = down[i++];
	}
}
