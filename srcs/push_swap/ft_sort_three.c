/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:10:59 by yogun             #+#    #+#             */
/*   Updated: 2022/08/03 20:55:39 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
