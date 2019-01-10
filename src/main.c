/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:05:58 by conoel            #+#    #+#             */
/*   Updated: 2019/01/10 18:26:29 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		main(int argc, char **argv)
{
	char	data[26][4][5];

	if (argc != 2)
	{
		write(2, "usage : ./fillit [file name]\n", 29);
		return (0);
	}
	data = load_data(argc, argv);
	//data = fillit();
	ft_print(data);
}