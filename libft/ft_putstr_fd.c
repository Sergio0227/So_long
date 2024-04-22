/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:06:02 by sandre-a          #+#    #+#             */
/*   Updated: 2024/02/28 19:06:07 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	count = 0;
	while (*s)
	{
		write (fd, s, 1);
		s++;
		count++;
	}
	return (count);
}
