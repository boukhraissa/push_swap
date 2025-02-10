/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:20:54 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/05 23:23:06 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	ra(t_node **stack_a, int p)
{
	t_node	*first_a;
	t_node	*last_a;
	t_node	*tmp;

	tmp = *stack_a;
	if (!*stack_a || !(*stack_a)->next)
		return ;
	first_a = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	last_a = tmp;
	*stack_a = first_a->next;
	last_a->next = first_a;
	first_a->next = NULL;
	if (p == 1)
		ft_printf("ra\n");
}
