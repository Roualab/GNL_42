/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbaou <rlabbaou@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:34:14 by rlabbaou          #+#    #+#             */
/*   Updated: 2025/12/14 15:59:18 by rlabbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	void	*ptr;
	size_t	length;

	length = ft_strlen(s);
	ptr = (char *) malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, length + 1);
	return (ptr);
}
