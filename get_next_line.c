/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:06:45 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/11/27 16:05:13 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' || buf[i] != '\0')
	{
		i++;
	}
	
}

int	check_buf()
{
	
}

char	*fill_line_buffer(int fd, char *remain, char *buf)
{
	int		chars_read;

	while (chars_read = read(fd, buf, BUFFER_SIZE))
	{
		
	}
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;

	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE);
	line = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	line = fill_line_buffer(fd, remain, buf);
	free(buf);
	set_line()
	return (line);
}

int	main(void)
{
	int 	fd = open("test.txt", O_RDONLY);
	char 	*line;

	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
