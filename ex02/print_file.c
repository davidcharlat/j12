#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 4096

int	print_err (int errnocpy, char *pb_src);

int print_1file_fr_start (char *file, int num)
{
	int		ret;
	int		fd;
	char	buf[BUFSIZE];
	
	errno = 0;
	ret = 1;
	if (num == 0)
		num = 1;
	fd = open (file, O_RDONLY);
	if (errno)
		return (print_err (errno, file));
	lseek (fd, num - 1, SEEK_SET);
	while (ret = read (fd, buf, BUFSIZE))
	{
		if (errno)
			return (print_err (errno, file));
		write (1, buf, ret);
	}
	close (fd);
	return (0);
}

int	print_files_fr_start (char *file, int num)
{
	char	*cpyfile;
	
	cpyfile = file;
	write (1, "==> ", 4);
	while (*cpyfile)
		write (1, (cpyfile++), 1);
	write (1, " <==\n", 5);
	return (print_1file_fr_start (file, num));
}

int print_1file_fr_end (char *file, int num)
{
	int		ret;
	int		fd;
	char	buf[BUFSIZE];
	
	errno = 0;
	ret = 1;
	fd = open (file, O_RDONLY);
	if (errno)
		return (print_err (errno, file));
	lseek (fd, num, SEEK_END);
	while (ret = read (fd, buf, BUFSIZE))
	{
		if (errno)
			return (print_err (errno, file));
		write (1, buf, ret);
	}
	close (fd);
	return (0);
}

int	print_files_fr_end (char *file, int num)
{
	char	*cpyfile;

	cpyfile = file;
	write (1, "==> ", 4);
	while (*cpyfile)
		write (1, (cpyfile++), 1);
	write (1, " <==\n", 5);
	return (print_1file_fr_end (file, num));
}
