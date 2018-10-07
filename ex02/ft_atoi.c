int	check_atoi_str (char *str)
{
	if ((*str > '9' || *str < '0') && *str != '+' && *str != '-')
		return (0);
	str++;
	while (*str)
	{
		if (*str < '0' || *str >'9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	len;
	int	i;
	int	power;
	int	sign;	
	
	sign = 1;
	i = 0;
	power = 1;
	nbr = 0;
	len = 0;	
	while (*(str + len) != '\0')
		len++;
	while ((i < len) && (sign == 1) && (*(str + len - 1 - i) != '+'))
	{
		if ((*(str + len - 1 - i) != '-'))
		{	
			nbr = nbr + (*(str + len - 1 - i) - 48) * power;
			power *= 10;
			i++;
		}
		else
		   	sign = -1;
	}
	return (nbr * sign * check_atoi_str(str));
}

