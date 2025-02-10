/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:23:40 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 21:00:33 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static void	handle_push_cases(t_node **stack_a, t_node **stack_b,
	t_node *last_a, t_node *last_b)
{
	if ((*stack_a)->index - 1 == (*stack_b)->index)
		pa(stack_b, stack_a);
	else if ((*stack_a)->index - 1 == last_b->index)
	{
		rrb(stack_b, 1);
		pa(stack_b, stack_a);
	}
	else if (last_a->index == max_index(stack_a) || \
			last_a->index < (*stack_b)->index)
	{
		pa(stack_b, stack_a);
		ra(stack_a, 1);
	}
	else if (last_a->index < last_b->index)
	{
		rrb(stack_b, 1);
		pa(stack_b, stack_a);
		ra(stack_a, 1);
	}
}

void	push_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*last_a;
	t_node	*last_b;
	int		size_b;
	int		pos;

	while (*stack_b)
	{
		last_a = get_last_node(*stack_a);
		last_b = get_last_node(*stack_b);
		size_b = list_size(stack_b);
		handle_push_cases(stack_a, stack_b, last_a, last_b);
		if (*stack_b)
		{
			pos = get_pos(*stack_b, (*stack_a)->index - 1);
			if ((*stack_a)->index - 1 == last_a->index)
				rra(stack_a, 1);
			else if (pos <= size_b / 2)
				rb(stack_b, 1);
			else
				rrb(stack_b, 1);
		}
	}
	ra(stack_a, 1);
	while (check_sort(stack_a) == 0)
		rra(stack_a, 1);
}

static void	handle_chunks(t_node **stack_a, t_node **stack_b, int size)
{
	int	p1;
	int	p2;

	p2 = 0;
	p1 = 0;
	while (size != 3)
	{
		p1 = p2 + size / 6;
		p2 += size / 3;
		while (list_size(stack_b) < p2)
		{
			if ((*stack_a)->index >= p2 && stack_b && \
			*stack_b && (*stack_b)->index < p1)
				rr(stack_a, stack_b);
			else if (stack_b && *stack_b && (*stack_b)->index < p1)
				rb(stack_b, 1);
			if ((*stack_a)->index >= p2)
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b);
		}
		size = list_size(stack_a);
	}
}

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	int	size;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	size = list_size(stack_a);
	index_list(stack_a);
	if (size == 2)
		sort2_num(stack_a, 'a');
	else if (size == 3)
		sort3_num(stack_a);
	else if (size == 4 || size == 5)
		sort5_num(stack_a, stack_b);
	else
	{
		handle_chunks(stack_a, stack_b, size);
		sort3_num(stack_a);
		push_to_a(stack_a, stack_b);
	}
}
