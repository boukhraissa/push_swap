/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:10:57 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 19:05:49 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static void	help_function(t_node **stack_a, t_node **stack_b)
{
	sort3_num(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

void	sort5_num(t_node **stack_a, t_node **stack_b)
{
	if (found_indexmin(stack_a) == 2)
		ra(stack_a, 1);
	while (list_size(stack_a) != 3)
	{
		if (found_indexmin(stack_a) < list_size(stack_a) / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
		if ((*stack_a)->value == found_min(stack_a))
			pb(stack_a, stack_b);
	}
	help_function(stack_a, stack_b);
}
