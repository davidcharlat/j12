#include <unistd.h>
#include "libft.h"

int print_1file_fr_end (char *file, int num);
int print_1file_fr_start (char *file, int num);
int print_files_fr_end (char *file, int num);
int print_files_fr_start (char *file, int num);

int	print_1file (char *av3, char *av2)
{
	int atoi;
	
	atoi = ft_atoi (av2);
	if (atoi < 0)		
		print_1file_fr_end (av3, atoi);
	else if (av2[0] != '+')
		print_1file_fr_end (av3, -atoi);
	else
		print_1file_fr_start (av3, atoi);
	return (0);
}

int	 print_files (int ac, char **av)
{
	int		i;
	int		atoi;
		
	i = 3;
	atoi = ft_atoi (av[2]);
	if (atoi < 0 || av[2][0] != '+')
	{
		if (atoi > 0)
			atoi = -atoi;
		while (i < ac)
		{
			print_files_fr_end (av[i++], atoi);
			if (i < ac)
				write (1, "\n", 1);
		}
		return (0);
	}
	while (i < ac)
		{
			print_files_fr_start (av[i++], atoi);
			if (i < ac)
				write (1, "\n", 1);
		}
	return (0);
}

int	main (int ac, char **av)
{
	int		atoi;
		
	atoi = ft_atoi (av[2]);
	if (ac < 4 || ft_strcmp (av[1], "-c") || (atoi == 0  && (ft_strcmp (av[2], "0") 
				&& ft_strcmp (av[2], "+0") && ft_strcmp (av[2], "-0"))))
		return (write (2, "no imput file or option '-c' and '[+]NUM'\n", 42));
	if (ac == 4)
		return (print_1file (av[3], av[2]));
	if (!ft_strcmp (av[2], "0") || !ft_strcmp (av[2], "-0"))
		return (0);
	return (print_files (ac, av));
}
