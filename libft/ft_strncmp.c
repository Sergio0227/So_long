/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:23:15 by sandre-a          #+#    #+#             */
/*   Updated: 2024/02/21 14:30:51 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p1 == 0 && *p2 == 0)
			return (0);
		else if (*p1 == 0)
			return (-1);
		else if (*p2 == 0)
			return (1);
		if (*p1 != *p2)
		{
			if (*p1 > *p2)
				return (1);
			if (*p1 < *p2)
				return (-1);
		}
		p1++;
		p2++;
		n--;
	}
	return (0);
}
