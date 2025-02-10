/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:41:26 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 20:28:47 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static int	count_words(char **av)
{
	char	**tmp;
	int		total;
	int		i;
	int		j;

	total = 0;
	i = 1;
	while (av[i])
	{
		if (!ft_strchr(av[i], ' '))
			total++;
		else
		{
			tmp = ft_split(av[i], ' ');
			j = 0;
			while (tmp[j])
				j++;
			total += j;
			free_split(tmp);
		}
		i++;
	}
	return (total);
}

static char	**process_argument(char *arg, char **str)
{
	char	**tmp;
	int		j;

	if (!ft_strchr(arg, ' '))
	{
		*str = ft_strdup(arg);
		return (str + 1);
	}
	tmp = ft_split(arg, ' ');
	j = 0;
	while (tmp[j])
	{
		*str = ft_strdup(tmp[j]);
		if (!*str)
			return (NULL);
		str++;
		j++;
	}
	free_split(tmp);
	return (str);
}

char	**add_str(char **av)
{
	char	**str;
	char	**current;
	int		i;
	int		count;

	count = count_words(av);
	str = malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	current = str;
	i = 1;
	while (av[i])
	{
		current = process_argument(av[i], current);
		if (!current)
			return (free_split(str), NULL);
		i++;
	}
	*current = NULL;
	return (str);
}
