#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 4096

int	test_star (char *pb_src)
{
	int test;
	
	test = 0;
	while (*pb_src)
	{
		if (*(pb_src++) == '*')
			test = 1;
	}
	return (test);
}

int	print_err (int errnocpy, char *pb_src)
{
	int		star;
	
	star = test_star (pb_src);
	write (2, "cat: ", 5);
	if (star)
		write (2, "'", 1);
	while (*pb_src)
		write (2, (pb_src++), 1);
	if (star)
		write (2, "'", 1);
	write (2, ": ", 2);
	if (errnocpy == 2)
		write (2, "No such file or directory\n", 26);
	if (errnocpy == 12)
		write (2, "Not enought memory\n", 19);
	if (errnocpy == 13)
		write (2, "Permission denied\n", 18);
	if (errnocpy == 21)
		write (2, "Is a directory\n", 15);
	if (errnocpy == 27)
		write (2, "File too large\n", 15);
	return (1);
}

int	main (int ac, char **av)
{
	int		fd;
	char	buf[BUFSIZE];
	int		ret;
	int		i;

	i = 0;
	while (ac > ++i)
	{
		errno = 0;
		ret = 1;
		fd = open (av[i], O_RDONLY);
		if (errno)
			(print_err (errno, av[i]));
		else
		{
			while (ret = read (fd, buf, BUFSIZE))
			{
				if (errno)
					return (print_err (errno, av[i]));
				write (1, buf, ret);
			}
			close (fd);
		}
	}
	return (0);
}
