/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:11:02 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/14 16:07:26 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "get_next_line_bonus.h"
# include <string.h>

typedef struct s_list
{
	long			data;
	bool			above_median;
	int				index;
	int				sorted_index;
	int				cost;
	struct s_list	*target;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstlast(t_list *lst);
t_list	*find_min(t_list *stack);
t_list	*prepare_stack(t_list **a, t_list **b);
t_list	*ft_lstnew(int content);

void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

void	sa(t_list **a);
void	rrb(t_list **b);
void	rra(t_list **a);
void	rb(t_list **b);
void	ra(t_list **a);
void	rrr(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	pa(t_list **src, t_list **dst);
void	pb(t_list **src, t_list **dst);

bool	sorted_stack(t_list *stack);

void	sorted_index(t_list *stack);
void	indexing(t_list	*stack);
void	handle_input(t_list **stack, char **av);
void	sort_three(t_list **a);
void	sort_stack(t_list **a, t_list **b);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		is_valid(char **s);
int		ft_lstsize(t_list *lst);

char	**ft_split(char const *s, char c);

long	ft_atoi(const char *str);

void	push(t_list **src, t_list **dst);
void	rrotate(t_list **stack);
void	rotate(t_list **stack);
void	swap(t_list **a);

#endif
