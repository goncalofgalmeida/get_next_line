/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:06:45 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/11/28 17:33:21 by g24force         ###   ########.fr       */
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


char	*get_next_line(int fd)
{
	char	*s
	//verificar se está tudo bem com o fd
	if (fd < 0)
		return (NULL);
	//ler os 5 bytes do file e passar para o stash
	//ler a variavel buf e ver se tem um \n
		//se não, ler os 5 bytes seguintes
	//se tiver \n, copiar o conteúdo do stash para uma variavel, mas só até ao ao \n
	//retornar a string
}