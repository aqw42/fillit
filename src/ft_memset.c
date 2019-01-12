/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:36:06 by conoel            #+#    #+#             */
/*   Updated: 2019/01/12 14:28:44 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/fillit.h"

void	ft_memset(char *s, size_t size, char c)
{
	while (size--)
		*s++ = c;
	*s = '\0';
}