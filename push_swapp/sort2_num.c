/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:58:20 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/06 00:54:50 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	sort2_num(t_node **stack_a, char c)
{
	if (check_sort(stack_a) == 1)
		return ;
	else
	{
		if (c == 'a')
			sa(stack_a);
		else
			sb(stack_a);
	}
}
