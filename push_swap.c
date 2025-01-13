/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:40:48 by mochajou          #+#    #+#             */
/*   Updated: 2025/01/10 16:51:18 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*void	ft_free(char **s)
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
	write(1, "Error\n", 6);
	ft_free(s);
	ft_lstclear(stack);
	exit(1);
}*/

	/*while (av[i])
	{
		s = ft_split(av[i], ' ');
		if (!is_valid(s))
			ft_error(&stack, s);
		for (int j = 0; s[j]; j++)
		{
			//printf("%ld\n", (long)ft_atoi(s[j]));
			new = ft_lstnew(ft_atoi(s[j]));
			ft_lstadd_back(&stack, new);
		}
		ft_free(s);
		i++;
	}*/
int	main(int ac, char *av[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	handle_input(&a, av);
	sort_stack(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
}
