/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:10:56 by sandre-a          #+#    #+#             */
/*   Updated: 2024/03/22 20:34:20 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	select_case(char specifier, char *hex)
{
	int	count;

	count = 0;
	while (*hex == '0')
		hex++;
	while (*hex != 0)
	{
		if (specifier == 'X')
			ft_putchar_fd(*hex, 1);
		else
			ft_putchar_fd(ft_tolower(*hex), 1);
		count++;
		hex++;
	}
	if (count == 0)
	{
		count++;
		write(1, "0", 1);
	}
	return (count);
}

int	ft_print_hex(unsigned int num, char specifier)
{
	char	*hex;
	char	*hex_chars;
	int		i;
	int		nibble;

	hex = malloc(9);
	hex[8] = 0;
	hex_chars = ft_strdup("0123456789ABCDEF");
	i = 7;
	while (i >= 0)
	{
		nibble = (num >> (i * 4)) & 0xF;
		hex[7 - i] = hex_chars[nibble];
		i--;
	}
	i = select_case(specifier, hex);
	free(hex);
	free(hex_chars);
	return (i);
}
