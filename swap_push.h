/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:24:01 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/10 21:26:30 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_PUSH_H
# define SWAP_PUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./ft_printf/ft_printf.h"

typedef struct t_list
{
	long			value;
	int				index;
	struct t_list	*next;
}	t_node;

void	push_swap(t_node **stack_a, t_node **stack_b);
void	sort2_num(t_node **stack_a, char c);
void	sort3_num(t_node **stack_a);
void	sort5_num(t_node **stack_a, t_node **stack_b);

void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_b, t_node **stack_a);
void	rrr(t_node **stack_a, t_node **stack_b);
void	rrb(t_node **stack_b, int p);
void	rra(t_node **stack_b, int p);
void	rr(t_node **stack_a, t_node **stack_b);
void	rb(t_node **stack_b, int p);
void	ra(t_node **stack_b, int p);
void	ss(t_node **stack_a, t_node **stack_b);
void	sb(t_node **stack_b);
void	sa(t_node **stack_a);

void	free_split(char **str);
void	free_list(t_node *head);

char	**add_str(char **av);
int		check_sort(t_node **stack_a);
t_node	*create_node(long value);
t_node	*get_last_node(t_node *stack);
int		get_pos(t_node *stack, int target_index);
void	index_list(t_node **stack_a);
t_node	**init_list_head(void);
int		list_size(t_node **stack_a);
long	max_index(t_node **stack_a);
int		pos_max_index(t_node **stack_a);
t_node	**storage_list(char **str);
int		check_sort(t_node **stack_a);
long	found_min(t_node **stack_a);
int		found_indexmin(t_node	**stack_a);

int		check_duplicates(t_node *head);
int		error_str(char **str);
int		is_digit(char **str);
int		check_string(char **av);
int		check_integer(t_node *head);

int		ft_isdigit(int c);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *str);
char	**ft_split(char *s, char c);
char	*ft_strchr(const char *str, int chr);

#endif