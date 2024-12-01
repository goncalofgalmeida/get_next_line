/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:07:20 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/12/01 13:19:30 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h> //posso manter isto por causa do SIZE_MAX?

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}				t_list;


size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
//size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
//char	*ft_substr(char const *s, unsigned int start, size_t len);
//size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

char	*get_next_line(int fd);

#endif