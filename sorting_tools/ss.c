/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:21:38 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 20:48:08 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	ss(t_node **stack_a, t_node **stack_b)
{
	t_node	*first_a;
	t_node	*second_a;
	t_node	*first_b;
	t_node	*second_b;

	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	first_a = *stack_a;
	second_a = (*stack_a)->next;
	first_a->next = second_a->next;
	second_a->next = first_a;
	*stack_a = second_a;
	first_b = *stack_b;
	second_b = (*stack_b)->next;
	first_b->next = second_b->next;
	second_b->next = first_b;
	*stack_b = second_b;
	ft_printf("ss\n");
}
