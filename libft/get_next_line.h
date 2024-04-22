/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:36:42 by sandre-a          #+#    #+#             */
/*   Updated: 2024/04/15 18:48:17 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				init_stash(t_list **stash, int fd);
int					found_nl(t_list *stash);
void				append(t_list **stash, char *buffer);
int					len_to_nl(t_list *stash);
char				*extract_line(t_list *stash);
void				copy_str(t_list *stash, char *str);
t_list				*get_last_node(t_list *stash);
void				clean(t_list **stash);
void				dealloc(t_list **stash, t_list *clean_node, char *buffer);

#endif