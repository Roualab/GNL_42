/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbaou <rlabbaou@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:19:50 by rlabbaou          #+#    #+#             */
/*   Updated: 2026/03/31 19:52:42 by rlabbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static char *read_to_stash(int fd, char *stash)
{
    char    *buffer;
    int     n_read;
	char	*temp;
    buffer = malloc(BUFFER_SIZE + 1); 
	if (!buffer)
        return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return(free(buffer), NULL);
		stash[0] = '\0';
    }
    n_read = 1;
	while (n_read > 0 && !ft_strchr(stash, '\n')) 
    {   
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read < 0)
			return(free(buffer), free(stash), NULL);
		buffer[n_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
	}
    return (free (buffer), buffer = NULL, stash);
}

char    *get_next_line(int fd)
{
    static char *stash;
    char    *extracted;
    char    *rest;
    size_t i;
    size_t pos;
    size_t len;
    i = 0;
    pos = 0;
    len = 0;

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
        return(free(stash), NULL);
    ft_strlcpy(extracted, stash, i + 1);
    pos = i;
    while (stash[i++])
        len++;
    rest = malloc(len + 1);
    if (!rest)
        return(free(extracted), free(stash), NULL);
    ft_strlcpy(rest, stash + pos, len + 1);
	return (free(stash), stash = rest, extracted);
}


#include <stdio.h>
#include <fcntl.h>
int main()
{
    int fd;
    char *line = NULL;
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (printf("%s", "not found"));
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
    	 free(line);
	}
    close(fd);
}
