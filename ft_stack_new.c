/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:29:05 by yogun             #+#    #+#             */
/*   Updated: 2022/07/23 08:56:55 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(long content)
{
	t_stack	*new;
	
	//We are creating neccessary free memory space in the RAM.
	new = (t_stack *)malloc(sizeof(t_stack));
	//We are protecting our memory allocation to avoid potential leakages.
	if (new == NULL)
		return (NULL);
	//In case of everything is okay, we put the argument ,which come to the function with the name of "content", into nbr value-
	//which is a member of the "new" node. Next is current pointing the NULL. We will link that list into our stack with ft_add_back.
	new->nbr = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}