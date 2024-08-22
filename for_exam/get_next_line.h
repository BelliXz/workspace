/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:35:50 by paradari          #+#    #+#             */
/*   Updated: 2024/02/17 20:33:20 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_collect_char(char *current, char *buffer);
char	*ft_read_line(char *current, int fd);
char	*ft_collect_line(char *current);
char	*ft_cut_oldline(char *current);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr(const char *s, int c);
void	*ft_calloc(size_t n, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_free_two(void *ptr1, void *ptr2);

#endif
