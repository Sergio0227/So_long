/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:45:30 by sandre-a          #+#    #+#             */
/*   Updated: 2024/02/21 12:58:57 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	character;

	p = (unsigned char *) s;
	character = (unsigned char ) c;
	while (n)
	{
		if (*p == character)
			return (p);
		p++;
		n--;
	}
	return (NULL);
}
