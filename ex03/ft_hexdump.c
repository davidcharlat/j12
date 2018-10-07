#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "libft.h"

int	print_err (int errnocpy, char *pb_src);
int	ft_putchar_non_printable(char c);
int	ft_putchar_hexbase(unsigned char nbr);
int	ft_put8nbr_hexbase(int nbr);
int	replace_buf (char buf[16], char precbuf[16]);
	
int	cmp_buf (char buf[16], char precbuf[16])
{
	int	i;
	
	i = 0;
	while (i < 16)
	{
		if (buf[i] != precbuf[i])
			return (-1);
		i++;
	}
	return (0);
}

int	print_line (char buf[16], char precbuf[2][16], int buflevel, int count)
{
	int i;
	
	if (!cmp_buf (buf, precbuf[0]) && !cmp_buf (buf, precbuf[1]))
		return (0);
	replace_buf (precbuf[1], precbuf[0]);
	if (!cmp_buf (buf, precbuf[1]))
		return (write (1, "*\n", 2) - 1);
	replace_buf (buf, precbuf[1]);
	i = 0;
	ft_put8nbr_hexbase (count);
	write (1, "  ", 2);
	while (i < buflevel)
	{
		ft_putchar_hexbase ((unsigned char)buf[i]);
		write (1, " ", 1);
		if (i++ == 7)
			write (1, " ",1);
	}
	write (1, "                                                ", 49 - 3 * i);                
	if (i < 8)
		write (1, " ",1);
	write (1, "|", 1);
	while (i > 0)
		ft_putchar_non_printable (buf[buflevel - i--]);
	return (write (1, "|\n", 2));
}

int	print_end (char buf[16], char precbuf[2][16], int buflevel, int i1)
{
	if (!buflevel && !i1)
		return (0);
	print_line (buf, precbuf, buflevel, i1);
	ft_put8nbr_hexbase (i1 + buflevel);
	return (1);
}


int	print_hex_files (int ac, char **av, int *buflevel, char buf[16])
{
	int		fd;
	int		i[2] = {0};
	char	precbuf[2][16] = {0};
	
	i[0] = 2;
	while (i[0] < ac)
	{
		errno = 0;
		fd = open (av[i[0]++], O_RDONLY);
		if (errno)
			print_err (errno, av[i[0] - 1]);
		else
		{
			*buflevel = *buflevel + read (fd, buf + *buflevel, 16 - *buflevel);
			while (*buflevel == 16)
			{
				print_line (buf, precbuf, 16, i[1]);
				*buflevel = read (fd, buf, 16);
				i[1] += 16;
			}
			close (fd);
		}
	}	
	return (print_end (buf, precbuf, *buflevel, i[1]));
}

int	main (int ac, char **av)
{
	char	buf[16];
	int		buflevel;
	char	precbuf[2][16] = {0};
	int		count;

	count = 0;
	buflevel = 0;
	if (ft_strcmp (av[1], "-C"))
		return (write (2, "no imput file or option '-C'\n", 29));
	if (ac == 2)
	{
		buflevel = read (0, buf, 16);
		while (buflevel == 16)
		{
			print_line (buf, precbuf, 16, count);
			buflevel = read (0, buf, 16);
			count += 16;
		}
		print_end (buf, precbuf, buflevel, count);
		write (1, "\n", 1);
		return (0);
	}
	print_hex_files (ac, av, &buflevel, buf);
	write (1, "\n", 1);
	return (0);
}
