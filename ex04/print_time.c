#include <unistd.h>
#include <time.h>

void	fill_day_str_time (int yd[6], char strtime[77])
{
	int		d;
	int		bi;
	
	bi = 0;
	if ((yd[0] - 1968) % 4 == 0)
		bi = 1;
	if (yd[1] < 31)
		d = yd[1] + 1;
	else if (yd[1] < 59 + bi)
		d = yd[1] - 30;
	else if (yd[1] < 212 + bi)
		d = ((yd[1] - 59 - bi) % 61) % 31 + 1;
	else
		d = ((yd[1] - 212 - bi) % 61) % 31 + 1;
	if (d > 9)
		strtime[47] = (d / 10) + '0';
	strtime[48] = (d % 10) + '0';
}

void	fill_month_str_time (int yd[6], char strtime[77])
{
	int		m;
	int		bi;
	int		i;
	char	month[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
		"Aug", "Sep", "Oct", "Nov", "Dec"};	
	
	i = 0;
	bi = 0;
	if ((yd[0] - 1968) % 4 == 0)
		bi = 1;
	if (yd[1] < 31)
		m = 0;
	else if (yd[1] < 59 + bi)
		m = 1;
	else if (yd[1] < 212 + bi)
		m = 2 + ((yd[1] - 59 - bi) / 61) * 2 + ((yd[1] - 59 - bi) % 61) / 31;
	else
		m = 7 + ((yd[1] - 212 - bi) / 61) * 2 + ((yd[1] - 212 - bi) % 61) / 31;
	while (month[m][i])
		strtime[i + 43] = month[m][i++];
}

void	str_ydhmsd (int ydhmsd[6], char strtime[77])
{
	int		i;
	char	day[7][4] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
	
	i = 0;
	while (day[ydhmsd[5]][i])
		strtime[i + 39] = day[ydhmsd[5]][i++];
	fill_month_str_time (ydhmsd, strtime);
	fill_day_str_time (ydhmsd, strtime);
	strtime[50] = (ydhmsd[2] / 10) + '0';
	strtime[51] = (ydhmsd[2] % 10) + '0';
	strtime[52] = ':';
	strtime[53] = (ydhmsd[3] / 10) + '0';
	strtime[54] = (ydhmsd[3] % 10) + '0';
}

void	fill_time (int tmp, char strtime[77])
{
	int		ydhmsd[6] = {0};
	int		y4y;
	
	tmp = tmp - __timezone + 3600 * __daylight;
	ydhmsd[5] = (tmp / 86400 + 3) % 7;
	ydhmsd[4] = tmp % 60;
	ydhmsd[3] = (tmp / 60) % 60;
	ydhmsd[2] = (tmp / 3600) % 24;
	y4y = tmp / 126230400;
	if ((tmp % 126230400) / 86400 < 730)
	{
		ydhmsd[0] = y4y * 4 + (tmp % 126230400) / 31536000 + 1970;
		ydhmsd[1] = ((tmp % 126230400) / 86400) % 365;
	}
	else if (((tmp % 126230400) / 86400) < 1096)
	{
		ydhmsd[0] = y4y * 4 + 1972;
		ydhmsd[1] = ((tmp % 126230400) / 86400) - 730;
	}
	else
	{
		ydhmsd[0] = y4y * 4 + 1973;
		ydhmsd[1] = ((tmp % 126230400) / 86400) - 1096;
	}
	str_ydhmsd (ydhmsd, strtime);
}
