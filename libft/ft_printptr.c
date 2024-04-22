/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:50 by sandre-a          #+#    #+#             */
/*   Updated: 2024/03/26 16:08:11 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_address(char *buffer)
{
	int	i;
	int	count;

	count = 2;
	i = 0;
	while (buffer[i] == '0')
		i++;
	write(1, "0x", 2);
	while (buffer[i] != 0)
	{
		write(1, &buffer[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_printptr(void *ptr)
{
	unsigned char	byte;
	char			buffer[17];
	char			*hex_chars;
	int				index;
	int				i;

	index = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = sizeof((unsigned long long)ptr) - 1;
	hex_chars = ft_strdup("0123456789abcdef");
	while (i >= 0)
	{
		byte = ((unsigned long long)ptr >> (i * 8)) & 0xFF;
		buffer[index++] = hex_chars[byte >> 4];
		buffer[index++] = hex_chars[byte & 0x0F];
		i--;
	}
	buffer[index++] = 0;
	i = print_address(buffer);
	free(hex_chars);
	return (i);
}
