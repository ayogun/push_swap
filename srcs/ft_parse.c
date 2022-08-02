/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:13:33 by yogun             #+#    #+#             */
/*   Updated: 2022/08/02 17:24:32 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	ft_parse(t_stack **stack_a)
{
	long index;
	long min;
	t_stack *tmp;
	
	tmp = *stack_a;
	min = ft_min(*stack_a);
	index = 1;
	while (*stack_a)
	{
		if ((*stack_a)->nbr < tmp->next->nbr)
		{
			while ((*stack_a)->nbr < (*stack_a)->next->nbr)
		}
	}
}
// void	list_args(char **argv, t_stack **stack_a)
// {
// 	long	i;

// 	i = 1;
// 	while (argv[i] != NULL)
// 	{
// 		ft_add_back(stack_a, ft_stack_new(ft_atoi(argv[i])));
// 		i++;
// 	}
// }	