/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:09:50 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/06 02:10:04 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

long	found_min(t_node **stack_a)
{
	long	min;
	t_node	*tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	tmp = *stack_a;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}
