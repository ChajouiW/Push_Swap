/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:03:35 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/12 18:26:14 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid(char **s)
{
	long	nb;
	int		i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		if (s[i][0] == '\0')
			return (0);
		nb = ft_atoi(s[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		if (!is_number(s[i]))
			return (0);
		i++;
	}
	return (1);
}
