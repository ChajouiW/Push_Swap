/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:51:47 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/12 16:42:23 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*bool	sorted_stack(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}
*/
t_list	*find_min(t_list *stack)
{
	t_list	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (min_node->data > stack->data)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

void	indexing(t_list	*stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

t_list	*find_max(t_list *stack)
{
	t_list	*max;

	max = stack;
	while (stack)
	{
		if (max->data < stack->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_list **a)
{
	t_list	*max;

	max = find_max(*a);
	if (max == *a)
		ra(a);
	else if (max == (*a)->next)
		rra(a);
	if (sorted_stack(*a) == false)
		sa(a);
}
