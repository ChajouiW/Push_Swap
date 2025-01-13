/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:11:02 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/12 18:33:06 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "get_next_line.h"
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

void	sort_stack(t_list **a, t_list **b);

void	sa(t_list **a);
void	rrb(t_list **b);
void	rra(t_list **a);
void	rb(t_list **b);
void	ra(t_list **a);
void	rrr(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	pa(t_list **src, t_list **dst);
void	pb(t_list **src, t_list **dst);

void	sorted_index(t_list *stack);

bool	sorted_stack(t_list *stack);
void	sort_three(t_list **a);
//void	sort_stack(t_list **a, t_list **b);
t_list	*ft_lstlast(t_list *lst);
t_list	*find_min(t_list *stack);
t_list	*prepare_stack(t_list **a, t_list **b);
void	indexing(t_list	*stack);
void	handle_input(t_list **stack, char **av);
void	sort_stack(t_list **a, t_list **b);
int		is_valid(char **s);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
char	**ft_split(char const *s, char c);
//void    move(t_list **a, t_list **b);
void	push(t_list **src, t_list **dst);
void	rrotate(t_list **stack);
void	rotate(t_list **stack);
void	swap(t_list **a);
long	ft_atoi(const char *str);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstnew(int content);

#endif
