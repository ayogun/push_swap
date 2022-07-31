/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:26:24 by yogun             #+#    #+#             */
/*   Updated: 2022/07/31 14:05:31 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//function to add a new node to the stack from back side
void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	t_stack	*head;
	t_stack	*tail;

	head = *stack;
	if (head == NULL)
	{
		tail = NULL;
		printf("");
		stack_new->next = NULL;
		stack_new->prev = NULL;
		*stack = stack_new;
		head = stack_new;
		tail = stack_new;
	}
	else
	{
		tail->next = stack_new;
		stack_new->prev = tail;
		stack_new->next = NULL;
		tail = stack_new;
	}	
}
