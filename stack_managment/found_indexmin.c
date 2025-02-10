/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_indexmin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:09:05 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/06 02:09:16 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

int	found_indexmin(t_node **stack_a)
{
	int		i;
	t_node	*tmp;
	long	min;

	i = 1;
	min = found_min(stack_a);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value == min)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
