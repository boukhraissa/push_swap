/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:31:13 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 20:56:56 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static t_node	*append_node(t_node *list, long value)
{
	t_node		*new;
	t_node		*tmp;

	new = create_node(value);
	if (!new)
		return (NULL);
	if (!list)
		return (new);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}

t_node	**storage_list(char **str)
{
	t_node		**head;
	t_node		*list;
	int			i;

	head = init_list_head();
	if (!head)
		return (NULL);
	list = NULL;
	i = 0;
	while (str[i])
	{
		list = append_node(list, ft_atoi(str[i]));
		if (!list)
		{
			free_list(*head);
			free(head);
			return (NULL);
		}
		if (!*head)
			*head = list;
		i++;
	}
	return (head);
}
