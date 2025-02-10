/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:45:07 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 20:40:34 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static int	check_character(int c)
{
	if ((c >= '!' && c <= '*') || c == '.' || c == ',' || c == '/' || c >= ':')
		return (1);
	return (0);
}

int	check_spaces(const char *str)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str != ' ')
			return (1);
		str++;
	}
	return (0);
}

int	error_str(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		if (check_spaces(str[i]) == 0)
			return (0);
		j = 0;
		while (str[i][j])
		{
			if (check_character(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '+' || str[i][j] == '-')
			j++;
		if (!str[i][j] || str[i][j] == ' ')
			return (0);
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) || str[i][j] == '+' \
			|| str[i][j] == '-' || str[i][j] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_integer(t_node *head)
{
	t_node	*current;

	current = head;
	while (current)
	{
		if (current->value < -2147483648 || current->value > 2147483647)
			return (0);
		current = current->next;
	}
	return (1);
}
