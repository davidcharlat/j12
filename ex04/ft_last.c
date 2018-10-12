#include <utmp.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include "include.h"

int		print_wtmp_begins (int fd)
{
	struct	utmp 	wtmp;
	int				result;
	char			line[77] = "wtmp begins        "
		"                                                          ";
	result = read (fd, &wtmp, sizeof(struct utmp));
	if(result == 0)
		return (result);
	fill_w_begins ((int)wtmp.ut_time, line);
	write (1, "\n", 1);
	write (1, line, size_line (line));
	write (1, "\n", 1);
	return (0);
}

int		print_user (struct	utmp wtmp, int fd)
{
	int				decal;
	struct	utmp 	tmp;
	char			line[77] = "                   "
		"                                                          ";
	
	decal = 0;
	while (read (fd, &tmp, sizeof(struct utmp)))	
	{
		decal = decal + sizeof(struct utmp);
		if (!ft_strcmp(tmp.ut_line, wtmp.ut_line)
			&& !ft_strcmp(tmp.ut_user, wtmp.ut_user) && wtmp.ut_type != 2)
		{
			lseek (fd, -decal, SEEK_CUR);
			fill_line_logout (wtmp, tmp, line);
			write (1, line, size_line (line));
			return (write (1, "\n", 1));
		}
	}
	lseek (fd, -decal, SEEK_CUR);
	fill_line_gone (wtmp, line);
	write (1, line, size_line (line));
	return (write (1, "\n", 1));
}

int		process_reboot (int fd)
{
	struct	utmp	wtmp;
	int				result;

	result = read (fd, &wtmp, sizeof(struct utmp));
	if(result == 0)
		return (result);
	if (wtmp.ut_type == 2)
		print_user(wtmp, fd);
	return (result);
}

int		process_user (int fd)
{
	struct	utmp	wtmp;
	int				result;

	result = read (fd, &wtmp, sizeof(struct utmp));
	if(result <= 0)
		return (result);
	if (wtmp.ut_type == 7)
		print_user(wtmp, fd);
	return (result);
}

int		main()
{
	int	fd;
	int from_end;
	int	size_wtmp;
	
	tzset();
	size_wtmp = 0;
	fd = open(_PATH_WTMP, O_RDONLY);
	while (read (fd, &from_end, 1))
		size_wtmp++;
	from_end = 0;
	while (from_end >= -size_wtmp && process_user(fd) >= 0)
	{
		from_end = from_end - sizeof(struct utmp);
		lseek (fd, from_end, SEEK_END);
	}
    while (process_reboot(fd));
    lseek (fd, 0, SEEK_SET);
	print_wtmp_begins (fd);
	close(fd);
	return (0);
}
