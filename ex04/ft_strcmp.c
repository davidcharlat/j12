int	ft_strcmp(char *s1, char *s2)
{
	int cursor;

	cursor = 0;
	while (*(s1 + cursor) != '\0' && *(s1 + cursor) == *(s2 + cursor))
			cursor++;
	return ((char)*(s1+cursor)-(char)*(s2+cursor));
}
