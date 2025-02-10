/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:23:26 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 21:13:04 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static void	free_from_leaks(t_node **a, t_node **b, char **l, int w)
{
	if (b)
	{
		free_list(*b);
		free(b);
	}
	if (a)
	{
		free_list(*a);
		free(a);
	}
	if (l)
		free_split(l);
	if (w == 1)
		write(2, "Error\n", 6);
}

int	main(int ac, char **av)
{
	char	**str_split;
	t_node	**list_a;
	t_node	**stack_b;

	if (ac <= 1)
		return (0);
	if (error_str(av) == 0)
		return (write(2, "Error\n", 6), 1);
	str_split = add_str(av);
	if (!str_split)
		return (write(2, "Error\n", 6), 1);
	if (is_digit(str_split) == 0 || check_string(str_split) == 1)
		return (free_split(str_split), write(2, "Error\n", 6), 1);
	list_a = storage_list(str_split);
	if (!list_a)
		return (free_split(str_split), write(2, "Error\n", 6), 1);
	if (check_duplicates(*list_a) == 1 || check_integer(*list_a) == 0)
		return (free_from_leaks(list_a, NULL, str_split, 1), 1);
	if (check_sort(list_a) != 0)
		return (free_split(str_split), free(list_a), free_list(*list_a), 0);
	stack_b = init_list_head();
	if (!stack_b)
		return (free_from_leaks(list_a, NULL, str_split, 1), 1);
	push_swap(list_a, stack_b);
	return (free_from_leaks(list_a, stack_b, str_split, 0), 0);
}
