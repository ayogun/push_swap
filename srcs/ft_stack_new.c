/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:29:05 by yogun             #+#    #+#             */
/*   Updated: 2022/07/31 14:07:37 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stack_new(long content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->nbr = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
