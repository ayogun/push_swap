/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:13:33 by yogun             #+#    #+#             */
/*   Updated: 2022/08/03 20:55:28 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_parse(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	i = 1;
	stack_a = NULL;
	if (argc < 2)
		ft_error();
	else if (argc == 2)
	 	stack_a = ft_parse_args_quoted(argv);
	else
	{
		list_args(argv, &stack_a);
	}
	return (stack_a);
}