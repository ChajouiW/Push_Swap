/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:42:54 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/10 16:46:19 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	swap(a);
	write (1, "sa\n", 3);
}

void	rrb(t_list **b)
{
	rrotate(b);
	write(1, "rrb\n", 4);
}

void	rra(t_list **a)
{
	rrotate(a);
	write(1, "rra\n", 4);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
