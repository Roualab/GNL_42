/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbaou <rlabbaou@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:19:44 by rlabbaou          #+#    #+#             */
/*   Updated: 2025/12/20 23:24:32 by rlabbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *s)
{
	if (!s)
		return;
	write(1, s, ft_strlen(s));
}

/*#include <stdio.h>
int main()
{
	char	*s = "hello"; 
	ft_putstr_fd(s,1);
}*/
