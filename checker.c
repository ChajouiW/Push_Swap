/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:49:21 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/13 15:23:45 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_list **a, t_list **b, char **op)
{
	write(2, "Error\n", 6);
	ft_lstclear(a);
	ft_lstclear(b);
	free(*op);
	exit(1);
}

void	do_swap(char **op, t_list **a, t_list **b)
{
	if (strncmp(*op, "sa\n", 3) == 0)
		swap(a);
	else if (strncmp(*op, "sb\n", 3) == 0)
		swap(b);
	else if (strncmp(*op, "ss\n", 3) == 0)
	{
		swap(a);
		swap(b);
	}
	else
		ft_exit(a, b, op);
}

void	do_rotation(char **op, t_list **a, t_list **b)
{
	if (strncmp(*op, "ra\n", 3) == 0)
		rotate(a);
	else if (strncmp(*op, "rb\n", 3) == 0)
		rotate(b);
	else if (strncmp(*op, "rr\n", 3) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (strncmp(*op, "rra\n", 4) == 0)
		rrotate(a);
	else if (strncmp(*op, "rrb\n", 4) == 0)
		rrotate(b);
	else if (strncmp(*op, "rrr\n", 4) == 0)
	{
		rrotate(a);
		rrotate(b);
	}
	else
		ft_exit(a, b, op);
}

void	do_op(char **op, t_list **a, t_list **b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = *a;
	head_b = *b;
	if (!op || !*op)
		return ;
	if (**op == 's')
		do_swap(op, a, b);
	else if (**op == 'r')
		do_rotation(op, a, b);
	else if (strncmp(*op, "pa\n", 3) == 0)
		push(b, a);
	else if (strncmp(*op, "pb\n", 3) == 0)
		push(a, b);
	else
		ft_exit(a, b, op);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	handle_input(&a, av);
	line = get_next_line(0);
	while (line)
	{
		do_op(&line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (sorted_stack(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a);
	ft_lstclear(&b);
}
