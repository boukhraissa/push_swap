/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:23:44 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/08 21:02:24 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static long	found_max(t_node **stack_a)
{
	long	max;
	t_node	*tmp;

	max = LONG_MIN;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	tmp = *stack_a;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

static int	found_indexmax(t_node **stack_a)
{
	int		i;
	t_node	*tmp;
	long	max;

	i = 1;
	max = found_max(stack_a);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value == max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	sort3_num(t_node **stack_a)
{
	int	max;

	max = found_indexmax(stack_a);
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (check_sort(stack_a))
		return ;
	if (max == 1)
		ra(stack_a, 1);
	else if (max == 2)
		rra(stack_a, 1);
	if (found_indexmin(stack_a) == 2)
		sa(stack_a);
}
