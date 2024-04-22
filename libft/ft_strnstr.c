/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:32:35 by sandre-a          #+#    #+#             */
/*   Updated: 2024/04/22 22:41:13 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t		size;

	l = little;
	b = big;
	if (!*l)
		return ((char *)big);
	while (*b && len > 0)
	{
		size = len;
		while (*b && *l && *b == *l && len > 0)
		{
			b++;
			l++;
			len--;
		}
		if (!*l)
			return ((char *)b - (l - little));
		b -= (size - len) - 1;
		l = little;
		len = size - 1;
	}
	return (NULL);
}
