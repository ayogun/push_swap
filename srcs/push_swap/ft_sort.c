/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:19:40 by yogun             #+#    #+#             */
/*   Updated: 2022/08/06 19:44:05 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function checks the size of the stack.
// 	 If the size is two it calls ft_sa to sort the stack.
// 	 If the size is three it calls ft_sort_three to sort the stack.
// 	 If the size is more than three it calls ft_sort_big 
//	 to sort the stack.
void	ft_sort(t_stack **stack_a)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 2)
		ft_sa(stack_a, 0);
	else if (stack_size == 3)
	{
		ft_sort_three(stack_a);
	}
	else
		ft_sort_big(stack_a);
}
