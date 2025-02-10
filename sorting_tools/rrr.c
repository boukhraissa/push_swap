/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:21:29 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 20:48:03 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next || !stack_b \
	|| !*stack_b || !(*stack_b)->next)
		return ;
	rrb(stack_b, 0);
	rra(stack_a, 0);
	ft_printf("rrr\n");
}
