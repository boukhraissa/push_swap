/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:47:22 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/05 22:48:40 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

char	*ft_strchr(const char *str, int chr)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)chr)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)chr)
		return ((char *)(str + i));
	return (NULL);
}
