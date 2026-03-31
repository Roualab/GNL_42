/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbaou <rlabbaou@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:55:03 by rlabbaou          #+#    #+#             */
/*   Updated: 2026/02/22 20:21:18 by rlabbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strcopy(char *dst, char *src)
{
	int i;

	i = 0;
	
	if (!src || !dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*#include <stdio.h>
int main()
{
char src[20] = "hello there";
char dest[20];
printf("%s\n", ft_strlcpy(dest, src, 15));
}*/
