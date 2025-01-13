/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:13:21 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/13 15:24:10 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicated(t_list *s, long n)
{
	while (s)
	{
		if (s->data == n)
			return (1);
		s = s->next;
	}
	return (0);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_error(t_list	**stack, char **s)
{
	write(2, "Error\n", 6);
	ft_free(s);
	ft_lstclear(stack);
	exit(1);
}

void	handle_input(t_list **stack, char **av)
{
	int		i;
	char	**s;
	long	new;
	int		j;

	i = 1;
	while (av[i])
	{
		s = ft_split(av[i], ' ');
		if (!s)
			ft_error(stack, s);
		if (!is_valid(s))
			ft_error(stack, s);
		j = 0;
		while (s[j])
		{
			new = ft_atoi(s[j]);
			if (duplicated(*stack, new))
				ft_error(stack, s);
			ft_lstadd_back(stack, ft_lstnew(new));
			j++;
		}
		ft_free(s);
		i++;
	}
}
