#ifndef INCLUDE_H
# define INCLUDE_H

void	fill_time (int tmp,	char line[77]);
int		ft_strcmp (char *str1, char *str2);
void	fill_line_logout (struct utmp login, struct utmp logout, char line[77]);
void	fill_line_gone (struct utmp login, char line[77]);
void	fill_w_begins (int tmp, char line[77]);
int		size_line (char line[77]);

#endif
