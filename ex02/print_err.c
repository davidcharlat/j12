#include <unistd.h>

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
	write (2, "tail: can't open '", 18);
	while (*pb_src)
		write (2, (pb_src++), 1);
	write (2, "' in reading mode: ", 19);
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
