/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:44:19 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 20:52:30 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

int	list_size(t_node **stack_a)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (i);
	tmp = *stack_a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
