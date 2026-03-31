/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbaou <rlabbaou@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:19:50 by rlabbaou          #+#    #+#             */
/*   Updated: 2026/03/31 18:47:44 by rlabbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char    *get_next_line(int fd) 
{
    static char *stash = NULL;
    char    *buffer = NULL;
    int     buffer_size = 6;
    int     n_read = 1;
	char	*temp = NULL;
	if (fd < 0)
		return (NULL);
//  read and append
    buffer = malloc(buffer_size + 1); 
	if (!buffer)
        return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return(free(buffer), NULL);
		stash[0] = '\0';
    }
	while (n_read > 0) 
    {   
		n_read = read(fd, buffer, buffer_size);
		if (n_read <= 0)
			return(free(buffer), free(stash), NULL);
		buffer[n_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
		if (ft_strchr(stash, '\n'))
			break;
	}
	free(buffer);
	buffer = NULL;
// extract one line
    char    *extracted =    NULL;
    char    *rest = NULL;
    size_t i = 0;
    size_t pos = 0;
    size_t len = 0;
	char	*temp_pos;
	
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i])
        i++;
    extracted = malloc(i + 1);
    if (!extracted)
        return(free(stash), NULL);
    ft_strlcpy(extracted, stash, i + 1);
    //extracted[i] = '\0';
    pos = i;
    while (stash[i++])
        len++;
    rest = malloc(len + 1);
    if (!rest)
        return(free(extracted), free(stash), NULL);
    temp_pos = stash + pos;
    ft_strlcpy(rest, temp_pos, len + 1);
    free(stash);
	stash = rest;
	return (extracted);

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
