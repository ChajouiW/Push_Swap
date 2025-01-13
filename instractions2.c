/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:40:15 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/13 15:24:34 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	pa(t_list **src, t_list **dst)
{
	push(src, dst);
	write(1, "pa\n", 3);
}

void	pb(t_list **src, t_list **dst)
{
	push(src, dst);
	write(1, "pb\n", 3);
}
