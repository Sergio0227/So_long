/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:31:36 by sandre-a          #+#    #+#             */
/*   Updated: 2024/03/13 18:31:31 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_hex(unsigned int num, char specifier);
int	ft_putunsigned_fd(unsigned int n, int fd);
int	ft_printptr(void *ptr);

#endif
