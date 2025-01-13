/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:30 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/13 20:59:08 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lkmala(t_list **a, t_list **b, t_list *cheapest)
{
	if (*a != cheapest->target)
	{
		while (*a != cheapest->target)
		{
			if (cheapest->target->above_median)
				ra(a);
			else
				rra(a);
		}
	}
	if (*b != cheapest)
	{
		while (*b != cheapest)
		{
			if (cheapest->above_median)
				rb(b);
			else
				rrb(b);
		}
	}
}

void	push_to_a(t_list **a, t_list **b, t_list *cheapest)
{
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*a != cheapest->target && *b != cheapest)
			rr(a, b);
	}
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		while (*a != cheapest->target && *b != cheapest)
			rrr(a, b);
	}
//	indexing(*a);
//	indexing(*b);
	lkmala(a, b, cheapest);
	pa(b, a);
}

void	finish_sorting(t_list **a)
{
	indexing(*a);
	while (*a != find_min(*a))
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stack(t_list **a, t_list **b)
{
	int	len_a;
	int	target_i;

	len_a = ft_lstsize(*a);
	if (len_a < 3 && !sorted_stack(*a))
		sa(a);
	while (len_a > 3 && !sorted_stack(*a))
	{
		target_i = (len_a) / 3;
		sorted_index(*a);
		while (target_i < (*a)->sorted_index && !sorted_stack(*a))
			ra(a);
		if (!sorted_stack(*a))
			pb(a, b);
		len_a = ft_lstsize(*a);
	}
	if (len_a == 3 && !sorted_stack(*a))
		sort_three(a);
	while (*b)
		push_to_a(a, b, prepare_stack(a, b));
	if (!sorted_stack(*a))
		finish_sorting(a);
}
