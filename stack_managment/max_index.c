/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:46:04 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 20:52:36 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

long	max_index(t_node **stack_a)
{
	long	max_index;
	t_node	*tmp;

	max_index = 1;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (max_index);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	return (max_index);
}
