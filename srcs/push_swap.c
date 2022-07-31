/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:39:36 by yogun             #+#    #+#             */
/*   Updated: 2022/07/31 14:08:32 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	int		iter;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	else if (!check_args(argv))
		ft_error();
		
	//create the stack
	list_args(argv, &stack_a);
	
	if (!stack_a || ft_checkdup(stack_a))
	{
		ft_free(&stack_a);
		ft_error();
	}

	//ft_rra(&stack_a, 1);
	
	printf("**********************\n");
	
	//print the stack
	tmp = stack_a;
	while(tmp)
	{
		printf("%ld\n", tmp->nbr);
		tmp = tmp->next;
	}
	//tmp = stack_a;
	printf("**********************\n");
	
	while(ft_checksorted(stack_a) == 0)
	{
		ft_sort(&stack_a);
	}

	
	

	
	iter = ft_lstsize(stack_a);
	printf("Number of nodes : %d\n", iter);

	int min = ft_min(stack_a);
	printf("min : %d\n", min);
	
	if (ft_checksorted(stack_a))
		printf("sorted\n");
	else
		printf("not sorted\n");
}