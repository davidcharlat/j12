#include <unistd.h>

int	replace_buf (char buf[16], char precbuf[16])
{
	int	i;
	
	i = 0;
	while (i < 16)
		precbuf[i] = buf[i++];
	return (0);
}

int	print_err (int errnocpy, char *pb_src)
{
	write (2, "hexdump: ", 9);
	while (*pb_src)
		write (2, (pb_src++), 1);
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

int	ft_putchar_non_printable(char c)
{	
	if ((c > 31) && (c < 127))
		return (write (1, &c, 1) - 1);
	return (write (1, ".", 1) - 1);
}

int	ft_putchar_hexbase(unsigned char nbr)
{
	char	base[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

	write (1, &(base[nbr / 16]), 1);
	write (1, &(base[nbr % 16]), 1);
	return (0);
}

int	ft_put8nbr_hexbase(int nbr)
{
	char	result[9] = {'0'};
	char	base[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	int 	cursor;

	cursor = 0;
	while (cursor < 9)
	{
		result[cursor] = base[(nbr % 16)];
		nbr = (nbr / 16);
		cursor++;
	}
	cursor = 8;
	while (cursor > 0)
	{
		cursor--;
		write (1, &(result[cursor]), 1);
	}
	return (0);
}
