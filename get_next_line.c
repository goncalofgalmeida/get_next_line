/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:06:45 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/11/20 10:44:24 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' || buf[i] == '\0')
	{
		i++;
	}
	
	
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*buf;
	char			*line;
	int				i;

	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	stash = (char *)malloc(BUFFER_SIZE * sizeof(char)); //alterar o malloc
	if (fd < 0 || !buf || !stash)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE) //alterar esta condicao
	{
		read(fd, buf, BUFFER_SIZE);
		if (stash[i] == '\n' || stash[i] == '\0')
			return (i);
		i++;
	}	
}
