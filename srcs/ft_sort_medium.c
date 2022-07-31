/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:38:42 by yogun             #+#    #+#             */
/*   Updated: 2022/07/31 14:59:17 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_medium(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while(ft_lstsize(*stack_a) > 3)
	{
		
		ft_pb(stack_a, &stack_b, 0);
		ft_sort_three(stack_a);
	}

}