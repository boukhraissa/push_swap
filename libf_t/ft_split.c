/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:45:42 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/05 22:48:37 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static char	**split_help(const char *s)
{
	char	**p;

	p = (char **)malloc(sizeof(char *) * 2);
	if (*s == '\0')
		p[0] = NULL;
	else
	{
		p[0] = ft_strdup((char *)s);
		if (!p[0])
		{
			free(p);
			return (NULL);
		}
	}
	p[1] = NULL;
	return (p);
}

static int	count_word(char const *s, char sp)
{
	int	i;
	int	count;
	int	check_word;

	i = 0;
	count = 0;
	while (s[i])
	{
		check_word = 0;
		while (s[i] && s[i] == sp)
			i++;
		while (s[i] && s[i] != sp)
		{
			if (check_word == 0)
			{
				count++;
				check_word = 1;
			}
			i++;
		}
	}
	return (count);
}

static int	rmp(char *ar, const char *s, int start, char sp)
{
	int	j;

	j = 0;
	while (s[start + j] && s[start + j] != sp)
	{
		ar[j] = s[start + j];
		j++;
	}
	ar[j] = '\0';
	return (start + j);
}

static char	**full_ar_words(char **ar, char const *str, char sp, int cw)
{
	int	index;
	int	i;
	int	j;

	i = 0;
	index = 0;
	while (index < cw)
	{
		while (str[i] && str[i] == sp)
			i++;
		j = 0;
		while (str[i + j] && str[i + j] != sp)
			j++;
		ar[index] = malloc (j +1);
		if (!ar)
		{
			while (*ar != NULL)
				free(*(ar)++);
			return (free(ar), NULL);
		}
		i = rmp (ar[index], str, i, sp);
		index++;
	}
	ar[index] = 0;
	return (ar);
}

char	**ft_split(char *s, char c)
{
	char	**p;
	int		count;

	if (!s)
		return (0);
	if (c == '\0')
		return (split_help(s));
	count = count_word((char *)s, c);
	p = (char **)malloc(sizeof(char *) * (count + 1));
	if (!p)
		return (0);
	return (full_ar_words(p, s, c, count));
}
