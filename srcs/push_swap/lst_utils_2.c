/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:16:13 by yogun             #+#    #+#             */
/*   Updated: 2022/08/03 20:55:48 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_find_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr)
	{
		a = a->next;
		i++;
	}
	a->index = 0;
	return (i);
}

int	ft_find_place_b(t_stack *b, int nbr)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr > b->nbr && nbr < ft_lstlast(b)->nbr)
		i = 0;
	else if (nbr > ft_max(b) || nbr < ft_min(b))
		i = ft_find_index(b, ft_max(b));
	else
	{
		tmp = b->next;
		while (b->nbr < nbr || tmp->nbr > nbr)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_place_a(t_stack *a, int nbr)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr < a->nbr && nbr > ft_lstlast(a)->nbr)
		i = 0;
	else if (nbr > ft_max(a) || nbr < ft_min(a))
		i = ft_find_index(a, ft_min(a));
	else
	{
		tmp = a->next;
		while (a->nbr > nbr || tmp->nbr < nbr)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}
