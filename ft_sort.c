/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:19:40 by yogun             #+#    #+#             */
/*   Updated: 2022/07/30 18:41:23 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->next->nbr < (*stack_a)->next->next->nbr && (*stack_a)->next->next->nbr < (*stack_a)->nbr)
		ft_sa(stack_a, 0);
	else if((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->next->nbr < (*stack_a)->next->next->nbr && (*stack_a)->next->next->nbr > (*stack_a)->nbr)
	{
		ft_sa(stack_a, 0);
		ft_rra(stack_a, 0);
	}
	else if((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->next->nbr < (*stack_a)->next->next->nbr && (*stack_a)->next->next->nbr > (*stack_a)->nbr)
		ft_ra(stack_a, 0);
	else if((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->next->nbr > (*stack_a)->next->next->nbr && (*stack_a)->next->next->nbr < (*stack_a)->nbr)
	{
		ft_rra(stack_a, 0);
		printf("rra\n");
	}
	else if((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->next->nbr > (*stack_a)->next->next->nbr && (*stack_a)->next->next->nbr > (*stack_a)->nbr)
	{
		ft_sa(stack_a, 0);
		ft_ra(stack_a, 0);
	}		
}

void	ft_sort(t_stack **stack_a)
{
	int stack_size;

	stack_size = ft_lstsize(*stack_a);
	
	if(stack_size <= 3)
	{
		ft_sort_three(stack_a);
	}
	else if(stack_size > 3 && stack_size <= 100)
		printf("100 eleman");
	else
		printf("büyük");
}