/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_max_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:46:48 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 20:53:18 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

int	pos_max_index(t_node **stack_a)
{
	int		position;
	t_node	*tmp;
	long	max;

	position = 1;
	max = max_index(stack_a);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index == max)
			return (position);
		position++;
		tmp = tmp->next;
	}
	return (0);
}
