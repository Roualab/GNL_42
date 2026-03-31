/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbaou <rlabbaou@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:59:08 by rlabbaou          #+#    #+#             */
/*   Updated: 2025/12/22 19:57:19 by rlabbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	join_size;

	if (!s1 || !s2)
		return (NULL);
	join_size = (ft_strlen(s1) + ft_strlen(s2) + 1);
	join = (char *)malloc(sizeof(char) * join_size);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	ft_strlcat(join, s2, join_size);
	return (join);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strjoin("hi", "girl"));
	printf("%s\n", ft_strjoin("hi", ""));
	printf("%s\n", ft_strjoin("", ""));
}*/
