/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:31:50 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 20:48:26 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

int	check_sort(t_node **stack_a)
{
	t_node	*tmp;

	if (!stack_a || !*stack_a)
		return (1);
	if (!(*stack_a)->next)
		return (1);
	tmp = *stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
