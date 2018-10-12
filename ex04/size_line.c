int	size_line (char line[77])
{
	int i;
	
	i = 75;
	while (line[i] == ' ')
		i--;
	return (i + 1);
}
