/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbaou <rlabbaou@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:14:13 by rlabbaou          #+#    #+#             */
/*   Updated: 2026/02/23 16:54:32 by rlabbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif
char	*get_next_line(int fd);
//void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strdup(char *s);
size_t	ft_strlen(const char *s);
int	    ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	ft_putstr(char *s);
char	*ft_strcopy(char *dst, char *src);

#endif
