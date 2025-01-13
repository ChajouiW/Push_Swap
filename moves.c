/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:52:08 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/10 16:49:27 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **a)
{
	t_list	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void	rrotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	last = ft_lstlast(*stack);
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = (*stack);
	*stack = last;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	last = ft_lstlast(*stack);
	last->next = tmp;
	*stack = (*stack)->next;
	tmp->next = NULL;
}

void	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (!src || !(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dst, tmp);
}
/*void	move(t_list **a, t_list **b)
{
	t_list	*min_node;

	if (!a || !(*a))
		return ;
	min_node = find_min(*a);
	while (*a != min_node)
	{
		if (min_node->above_median)
			rotate(a);
		else
			rrotate(a);
	}
	push(a, b, 'b');
}*/
