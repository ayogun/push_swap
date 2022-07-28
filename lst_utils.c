/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:01:05 by yogun             #+#    #+#             */
/*   Updated: 2022/07/28 19:08:30 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_min(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr < i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

int	ft_max(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr > i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

int	ft_lstrchr(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	ft_find_place_b(t_stack *b, int c)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (c > b->nbr && c < ft_lstlast(b)->nbr)
		i = 0;
	else if (c > ft_max(b) || c < ft_min(b))
		i = ft_lstrchr(b, ft_max(b));
	else
	{
		tmp = b->next;
		while (b->nbr < c || tmp->nbr > c)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_place_a(t_stack *a, int c)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (c < a->nbr && c > ft_lstlast(a)->nbr)
		i = 0;
	else if (c > ft_max(a) || c < ft_min(a))
		i = ft_lstrchr(a, ft_min(a));
	else
	{
		tmp = a->next;
		while (a->nbr > c || tmp->nbr < c)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}