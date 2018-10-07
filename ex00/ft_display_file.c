#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 128 

int	main (int ac, char **av)
{
	int		fd;
	char	buf[BUFSIZE];
	int		ret;
	
	if (ac < 2)
		return (write (2, "File name missing.\n", 19));
	if (ac > 2)
		return (write (2, "Too many arguments.\n", 20));
	fd = open (av[1], O_RDONLY);
	if (fd == -1)
		return (write (2, "open() failed\n", 14));
	while (ret = read (fd, buf, BUFSIZE))
		write (1, buf, ret);
	return (close (fd));
}
