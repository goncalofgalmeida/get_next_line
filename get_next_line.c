/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:06:45 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/11/29 15:21:23 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*p;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < nmemb)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}

int	ft_has_newline(char * str)
{
	if (!str)
		return (0);
	if (ft_strchr(str, '\n') == NULL)
		return (0);
	else
		return (1);
}

char	*ft_fill_stash(char *stash, char *str)
{
	//realocar a memoria do stash
	//concat str ao stash
	if (!stash)
		ft_strjoin("", str);
	else
		ft_strjoin(stash, str);
	return (stash);
}

char	*ft_fill_line(char *stash, char *line)
{
	int	i;

	i = 0;
	while (stash[i] != '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;

	if (fd < 0)
		return (NULL);
	buf = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_has_newline(buf))
	{
		read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		stash = ft_fill_stash(buf, stash);
	}
	line = NULL;
	line = ft_fill_line(stash, line);
	//limpar o stash para recomecar a partir do \n
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
		//line = get_next_line(fd);
		line = 0;
	}
	free(line);
	close(fd);
	return (0);
}
