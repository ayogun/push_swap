/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:19:40 by yogun             #+#    #+#             */
/*   Updated: 2022/07/29 17:14:24 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **stack_a)
{
	int stack_size;

	stack_size = ft_lstsize(*stack_a);
	
	if(stack_size <= 3)
		printf("üç veya daha az eleman var\n");
	else if(stack_size > 3 && stack_size <= 100)
		printf("100 eleman");
	else
		printf("büyük");
}