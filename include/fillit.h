/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:06:05 by conoel            #+#    #+#             */
/*   Updated: 2019/01/11 12:49:02 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h> // Pour le printf

#define MAX_FILE 546

char	***load_data(char *path);
char	*fillit(char ***data);

size_t		ft_strlen(char *s);
char	*ft_memdup(char *str, size_t size);

#endif