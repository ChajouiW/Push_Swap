/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:43:12 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/14 15:04:02 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_list **a, t_list **set)
{
	long	min_data;
	t_list	*stack;
	t_list	*target;
	t_list	*b;

	b = *set;
	while (b)
	{
		min_data = LONG_MAX;
		stack = *a;
		while (stack)
		{
			if (stack->data > b->data && stack->data < min_data)
			{
				min_data = stack->data;
				target = stack;
			}
			stack = stack->next;
		}
		if (min_data == LONG_MAX)
			b->target = find_min(*a);
		else
			b->target = target;
		b = b->next;
	}
}

t_list	*cheapest(t_list *stack)
{
	t_list	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->cost < cheapest->cost)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_list	*cost_for_cheapest(t_list *a, t_list *b, int size1, int size2)
{
	t_list	*stack;
	int		cost1;
	int		cost2;

	indexing(a);
	indexing(b);
	stack = b;
	while (stack)
	{
		if (stack->above_median)
			cost2 = stack->index;
		else
			cost2 = size2 - stack->index;
		if (stack->target->above_median)
			cost1 = stack->target->index;
		else
			cost1 = size1 - stack->target->index;
		if ((stack->above_median && stack->target->above_median)
			|| (!stack->above_median && !stack->target->above_median))
			stack->cost = ft_max(cost1, cost2);
		else
			stack->cost = cost1 + cost2;
		stack = stack->next;
	}
	return (cheapest(b));
}

t_list	*prepare_stack(t_list **a, t_list **b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	set_target(a, b);
	return (cost_for_cheapest(*a, *b, size_a, size_b));
}
