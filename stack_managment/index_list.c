/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:37:10 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 20:52:07 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static long	find_next_min(t_node *stack, long prev_min)
{
	long	min;
	t_node	*current;

	min = LONG_MAX;
	current = stack;
	while (current)
	{
		if (current->value < min && current->value > prev_min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

static void	get_index(t_node *stack, long value, int index)
{
	t_node		*temp;

	temp = stack;
	while (temp)
	{
		if (temp->value == value)
			temp->index = index;
		temp = temp->next;
	}
}

void	index_list(t_node **stack_a)
{
	int		size;
	int		index;
	long	min;
	long	prev_min;

	size = list_size(stack_a);
	if (size == 0)
		return ;
	index = 0;
	prev_min = LONG_MIN;
	while (index < size)
	{
		min = find_next_min(*stack_a, prev_min);
		get_index(*stack_a, min, index);
		prev_min = min;
		index++;
	}
}
