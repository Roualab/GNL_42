/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbaou <rlabbaou@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 19:52:43 by rlabbaou          #+#    #+#             */
/*   Updated: 2026/04/04 19:55:04 by rlabbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	int		n_read;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (free(buffer), NULL);
		stash[0] = '\0';
	}
	n_read = 1;
	while (n_read > 0 && !ft_strchr(stash, '\n'))
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read < 0)
			return (free(buffer), free(stash), NULL);
		buffer[n_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		(free(stash), stash = temp);
	}
	return (free(buffer), buffer = NULL, stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*extracted;
	char		*rest;
	size_t		i;

	i = 0;
	if (fd < 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash || stash[0] == '\0')
		return (free(stash), stash = NULL, NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i])
		i++;
	extracted = malloc(i + 1);
	if (!extracted)
		return (free(stash), NULL);
	ft_strlcpy(extracted, stash, i + 1);
	rest = malloc(ft_strlen(stash + i) + 1);
	if (!rest)
		return (free(extracted), free(stash), NULL);
	ft_strlcpy(rest, stash + i, ft_strlen(stash + i) + 1);
	return (free(stash), stash = rest, extracted);
}
