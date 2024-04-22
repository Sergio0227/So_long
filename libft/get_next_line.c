/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:36:22 by sandre-a          #+#    #+#             */
/*   Updated: 2024/04/15 14:57:43 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	init_stash(&stash, fd);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	clean(&stash);
	return (line);
}

void	init_stash(t_list **stash, int fd)
{
	int		counter;
	char	*buffer;

	while (!found_nl(*stash))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		counter = read(fd, buffer, BUFFER_SIZE);
		if (counter <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[counter] = 0;
		append(stash, buffer);
	}
}

int	found_nl(t_list *stash)
{
	int	i;

	while (stash)
	{
		i = 0;
		while (stash->content[i] && i < BUFFER_SIZE)
		{
			if (stash->content[i] == '\n')
				return (1);
			i++;
		}
		stash = stash->next;
	}
	return (0);
}

void	append(t_list **stash, char *buffer)
{
	t_list	*new;
	t_list	*last;

	last = get_last_node(*stash);
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	if (!last)
		*stash = new;
	else
		last->next = new;
	new->content = buffer;
	new->next = NULL;
}

char	*extract_line(t_list *stash)
{
	int		length;
	char	*line;

	if (!stash)
		return (NULL);
	length = len_to_nl(stash);
	line = malloc(sizeof(char) * (length + 1));
	if (!line)
		return (NULL);
	copy_str(stash, line);
	return (line);
}
