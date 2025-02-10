/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:21:11 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/05 23:23:21 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	rb(t_node **stack_b, int p)
{
	t_node	*first_b;
	t_node	*last_b;
	t_node	*tmp;

	tmp = *stack_b;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	first_b = *stack_b;
	while (tmp->next)
		tmp = tmp->next;
	last_b = tmp;
	*stack_b = first_b->next;
	last_b->next = first_b;
	first_b->next = NULL;
	if (p == 1)
		ft_printf("rb\n");
}
