/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:19:40 by yogun             #+#    #+#             */
/*   Updated: 2022/07/31 14:09:26 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	int	arr[3];

	arr[0] = (*stack_a)->nbr;
	arr[1] = (*stack_a)->next->nbr;
	arr[2] = (*stack_a)->next->next->nbr;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		ft_ra(stack_a, 0);
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		ft_sa(stack_a, 0);
		ft_rra(stack_a, 0);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		ft_sa(stack_a, 0);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		ft_rra(stack_a, 0);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
	{
		ft_sa(stack_a, 0);
		ft_ra(stack_a, 0);
	}		
}

void	ft_sort(t_stack **stack_a)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size <= 3)
	{
		ft_sort_three(stack_a);
	}
	else if (stack_size > 3 && stack_size <= 100)
		ft_sort_medium(stack_a);
	else
		printf("büyük");
}
