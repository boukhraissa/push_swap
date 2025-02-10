/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:29:07 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 20:52:27 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

t_node	**init_list_head(void)
{
	t_node	**head;

	head = (t_node **)malloc(sizeof(t_node *));
	if (!head)
		return (NULL);
	*head = NULL;
	return (head);
}
