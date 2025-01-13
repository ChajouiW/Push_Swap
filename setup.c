/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:55:46 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/10 16:47:57 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = 0;
	while (i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[min] > arr[j])
				min = j;
			j++;
		}
		if (min != i)
		{
			tmp = arr[min];
			arr[min] = arr[i];
			arr[i] = tmp;
		}
		i++;
	}
}

static void	s_index(t_list *stack, int data, int i)
{
	while (stack)
	{
		if (stack->data == data)
		{
			stack->sorted_index = i;
			break ;
		}
		stack = stack->next;
	}
}

void	sorted_index(t_list *stack)
{
	int		i;
	int		*arr;
	int		size;
	t_list	*first;

	first = stack;
	size = ft_lstsize(stack);
	arr = malloc(sizeof(int) * (size));
	i = 0;
	while (stack)
	{
		arr[i] = stack->data;
		i++;
		stack = stack->next;
	}
	sort_arr(arr, size);
	i = 0;
	while (i < size)
	{
		s_index(first, arr[i], i);
		i++;
	}
	free(arr);
}
