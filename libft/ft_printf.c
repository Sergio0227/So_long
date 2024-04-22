/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:49:02 by sandre-a          #+#    #+#             */
/*   Updated: 2024/03/13 18:27:50 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar_fd(va_arg(ap, int), 1);
	else if (specifier == 's')
		count += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (specifier == 'd')
		count += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (specifier == 'p')
		count += ft_printptr(va_arg(ap, void *));
	else if (specifier == 'i')
		count += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (specifier == 'u')
		count += ft_putunsigned_fd(va_arg(ap, int), 1);
	else if (specifier == 'x')
		count += ft_print_hex((long)va_arg(ap, unsigned int), specifier);
	else if (specifier == 'X')
		count += ft_print_hex((long)va_arg(ap, unsigned int), specifier);
	else if (specifier == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write (1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
