/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:58:38 by sandre-a          #+#    #+#             */
/*   Updated: 2024/03/01 19:42:57 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	calc_sub(char *str, char c)
{
	int	i;
	int	num_strings;

	if (!*str || !str)
		return (0);
	i = 0;
	num_strings = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i])
			i++;
		num_strings++;
	}
	i--;
	if (str[i] == c)
		num_strings--;
	return (num_strings);
}

static int	*count_str_length(int number_of_str, char *str, char c)
{
	int	*length;
	int	i;

	i = 0;
	length = malloc(sizeof(int) * number_of_str);
	while (*str)
	{
		length[i] = 0;
		while (*str == c)
			str++;
		while (*str != c && *str)
		{
			length[i]++;
			str++;
		}
		length[i]++;
		i++;
		if (i == number_of_str)
			break ;
		str++;
	}
	return (length);
}

static void	fill_strs(char **ppstr, char *str, char c, int *length)
{
	int	i;
	int	y;

	i = 0;
	while (ppstr[i] != 0)
	{
		y = 0;
		while (y < length[i] - 1)
		{
			while (*str == c)
				str++;
			ppstr[i][y] = *str;
			str++;
			y++;
		}
		ppstr[i][y] = 0;
		i++;
	}
}

static void	alloc_str(char **ppstr, int size, int *length)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ppstr[i] = malloc(sizeof(char) * length[i]);
		i++;
	}
	ppstr[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**ppstr;
	int		size;
	int		*length;

	size = calc_sub((char *)s, c);
	ppstr = malloc(sizeof(char *) * (size + 1));
	if (size == 0)
	{
		ppstr[0] = NULL;
		return (ppstr);
	}
	length = count_str_length(size, (char *) s, c);
	alloc_str(ppstr, size, length);
	fill_strs(ppstr, (char *) s, c, length);
	free(length);
	return (ppstr);
}
