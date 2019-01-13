/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:10:48 by conoel            #+#    #+#             */
/*   Updated: 2019/01/13 13:38:14 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_tetri(char *tetri, int pos)
{
	if (tetri[pos] == '1')
	{
		tetri[pos] = '#';
		return (is_tetri(tetri, pos + 1) + is_tetri(tetri, pos - 1)
				+ is_tetri(tetri, pos + 5) + is_tetri(tetri, pos - 5) + 1);
	}
	return (0);
}

static int	is_tetri_main(char *tetri)
{
	int i;

	i = 0;
	while (i < 21)
	{
		if (tetri[i] == '#')
			tetri[i] = '1';
		i++;
	}
	i = 0;
	while (i < 21)
	{
		if (tetri[i] == '1')
			return (is_tetri(tetri, i));
		i++;
	}
	return (0);
}

int			count_minos(t_index *ind, char *buffer)
{
	int		count;

	ind->j = 0;
	while (ind->j++ < 4)
	{
		ind->k = 0;
		count = 0;
		while (ind->k++ < 4)
		{
			if (buffer[ind->i] != '.' && buffer[ind->i] != '#')
				return (0);
			buffer[ind->i++] == '#' ? count++ : 0;
		}
		if (buffer[ind->i++] != '\n')
			return (0);
	}
	if ((buffer[ind->i] != '\n' && buffer[ind->i + 1] != '\0') ||
		(buffer[ind->i] == '\n' && buffer[++ind->i] == '\0') || count != 4)
		return (0);
	return (1);
}

int			is_valid(char *buffer)
{
	t_index ind;

	ind.i = 0;
	while (buffer[ind.i] != '\0')
	{
		if (is_tetri_main(&buffer[ind.i]) != 4)
			return (0);
		if (count_minos(&ind, buffer) == 0)
			return (0);
/*		while (ind.j++ < 4)
		{
			ind.k = 0;
			while (ind.k++ < 4)
			{
				if (buffer[ind.i] != '.' && buffer[ind.i] != '#')
					return (0);
				buffer[ind.i++] == '#' ? count++ : 0;
			}
			if (buffer[ind.i++] != '\n')
				return (0);
		}
		if ((buffer[ind.i] != '\n' && buffer[ind.i + 1] != '\0') ||
(buffer[ind.i] == '\n' && buffer[++ind.i] == '\0') || count != 4)
			return (0); */
	}
	return (1);
}
