/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:06:45 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/12/07 00:42:38 by g24force         ###   ########.fr       */
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
	while (i < nmemb * size)
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

char	*ft_fill_stash(char *stash, char *buf)
{
	char	*updated_stash;

	if (!stash)
		return(ft_strjoin("", buf));
	if (!buf || buf[0] == '\0')
		return(stash );
	updated_stash = ft_strjoin(stash, buf);
	free(stash);
	return(updated_stash);
}

char	*ft_fill_line(char *stash, char *line)
{
	int	i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = (char *)calloc((i + 2),sizeof(char)); //espaco para o nl e nul
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] = '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clear_stash(char *stash)
{
	char	*nl_position;
	char	*new_stash;

	if (!stash)
		return (NULL);
	nl_position = ft_strchr(stash, '\n');
	if (!nl_position || *(nl_position + 1) == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(nl_position + 1);
	
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int			c_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	c_read = 1;
	while (c_read > 0 && !ft_has_newline(stash))
	{
		c_read = read(fd, buf, BUFFER_SIZE);
		if (c_read < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[c_read] = '\0';
		stash = ft_fill_stash(stash, buf);
	}
	free(buf);
	if (!stash || *stash == '\0')
	{
		free(stash);
		return (NULL);
	}
	line = ft_fill_line(stash, line);
	stash = ft_clear_stash(stash);	
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
		//line = 0;
	}
	free(line);
	close(fd);
	return (0);
}
