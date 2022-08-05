/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:46:09 by yogun             #+#    #+#             */
/*   Updated: 2022/08/05 14:44:34 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = ft_parse(argc, argv);
	if (argc < 2)
		ft_error();
	else if (argc == 2)
		stack_a = ft_parse_args_quoted(argv);
	else
	{
		if (!check_args(argv))
			ft_error();
		else
			list_args(argv, &stack_a);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	b = NULL;
	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free (&a);
		ft_error();
	}
	line = get_next_line(0);
	if (!line && !ft_checksorted(a))
		write(1, "KO\n", 3);
	else if (!line && ft_checksorted(a))
		write(1, "OK\n", 3);
	else
		ft_checker(&a, &b, line);
	ft_free(&b);
	ft_free(&a);
	return (0);
}
