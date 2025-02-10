/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:21:22 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 20:47:59 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	rra(t_node **stack_a, int p)
{
	t_node	*last;
	t_node	*second_to_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	second_to_last = NULL;
	while (last->next)
	{
		second_to_last = last;
		last = last->next;
	}
	last->next = *stack_a;
	second_to_last->next = NULL;
	*stack_a = last;
	if (p == 1)
		ft_printf("rra\n");
}
