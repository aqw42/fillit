/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:43:55 by conoel            #+#    #+#             */
/*   Updated: 2019/01/14 13:29:29 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_putstr(char *str, int size)
{
	int i;
	int j;

	j = 0;
	i = size;
	while (i--)
	{
		write(1, &str[j], size);
		write(1, "\n", 1);
		j += size;
	}
	return ;
}

static void	ft_puthead(char *buff, int size)
{
	int i;

	i = 0;
	ft_strcat(buff, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\
\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\
\n\n\n\n\n\n\n\n\n\n\n\n        /'-");
	while (i++ < size)
	{
		if (i == size / 2)
			ft_strcat(buff, "*FI");
		else if (i == size / 2 + 1)
			ft_strcat(buff, "L L");
		else if (i == size / 2 + 2)
			ft_strcat(buff, "IT*");
		else
			ft_strcat(buff, "---");
	}
	ft_strcat(buff, "'\\\n");
}

static void	ft_putcolor(char *buff, char c)
{
	int i;

	ft_strcat(buff, "\033[30m");
	if (c % 6 == 0)
		ft_strcat(buff, "\033[41m ");
	else if (c % 6 == 1)
		ft_strcat(buff, "\033[42m ");
	else if (c % 6 == 2)
		ft_strcat(buff, "\033[43m ");
	else if (c % 6 == 3)
		ft_strcat(buff, "\033[44m ");
	else if (c % 6 == 4)
		ft_strcat(buff, "\033[45m ");
	else if (c % 6 == 5)
		ft_strcat(buff, "\033[46m ");
	i = ft_strlen(buff);
	buff[i] = c;
	buff[i + 1] = '\0';
	ft_strcat(buff, " \033[0m");
}

static void	ft_putbody(char *buff, char *str, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		ft_strcat(buff, "        || ");
		while (++j < size)
		{
			if (str[j + (i * size)] != '.')
				ft_putcolor(buff, str[j + (i * size)]);
			else
				ft_strcat(buff, "   ");
		}
		ft_strcat(buff, "||\n");
	}
}

void		ft_putstr_visual(char *str, int size)
{
	int		i;
	char	buff[10000];

	ft_memset(buff, 10000, '\0');
	ft_puthead(buff, size);
	i = 0;
	ft_putbody(buff, str, size);
	ft_strcat(buff, "        \\.-");
	while (i++ < size)
		ft_strcat(buff, "---");
	ft_strcat(buff, "./\n");
	write(1, buff, ft_strlen(buff));
	return ;
}
