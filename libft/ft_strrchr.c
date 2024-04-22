/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:06:47 by sandre-a          #+#    #+#             */
/*   Updated: 2024/04/22 22:46:16 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		size;
	char	*p;

	p = (char *)s;
	size = ft_strlen(p);
	while (*p)
		p++;
	while (size >= 0)
	{
		if (*p == (unsigned char)c)
			return (p);
		p--;
		size--;
	}
	return (NULL);
}
