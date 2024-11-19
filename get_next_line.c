/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:06:45 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/11/19 16:55:36 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		stash[BUFFER_SIZE];
	char			*line;
	int				i;

	i = 0;
	while (i < (BUFFER_SIZE / 5))
	{
		read(fd, stash, 5);
		if (stash[i] == '\n')
			return (i);
		i++;
	}	
}
