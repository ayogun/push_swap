/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:39:36 by yogun             #+#    #+#             */
/*   Updated: 2022/07/23 09:05:50 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//chec if the chracter is negative
int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

//check if the character is digit
int	digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

//check if character is space character
int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

//function to check if given arguments is valid
int	check_error(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (sign(argv[i][j]))
			{
				j++;
				if (!digit(argv[i][j]))
					return (false);
			}
			else if (digit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if (!digit(argv[i][j]) && !space(argv[i][j]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

//function which checks the character if it is alphanumerical
int	ft_isalpha(int c)
{
	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42)
		|| (c == 44) || (c == 46) || (c == 47))
		return (1);
	return (0);
}





void	ft_error(void)
{	
	//Here an error message is being printed out
	write (2, "Error\n", 6);
	exit(1);
}

void	alpha_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			//Here arguments are send to make ASCII check regarding the alphanumeric values
			if (ft_isalpha(argv[i][j]))
				ft_error();
			j++;
		}
		i++;
	}
}

int	check_args(char **argv)
{
	//With this function it is checked whether arguments include alfanumeric or not
	alpha_check(argv);
	if (!check_error(argv, 1, 0))
		return (false);
	return (true);
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *tmp;
	int n1;
	int iter;
	
	stack_a = NULL;
	//check if there are enough arguments
	if (argc < 2)
		return (0);
	//check if the arguments are valid
	//else if (!check_args(argv))
		//ft_error();
	//create the stack
	list_args(argv, &stack_a);
	
	printf("**********************\n");
	//print the stack
	tmp = stack_a;
	while(tmp)
	{
		printf("%ld\n", tmp->nbr);
		tmp = tmp->next;
	}
	
	// tmp = stack_a;
	// printf("tmp->nbr : %ld\n", tmp->nbr);
	// tmp = tmp->next;
	// 	printf("tmp->nbr : %ld\n", tmp->nbr);
	// tmp = tmp->next;
	//  	printf("tmp->nbr : %ld\n", tmp->nbr);
	// // tmp = tmp->next;
	// while (tmp != stack_a)
	// {
	// 	printf("tmp->nbr : %ld\n", tmp->nbr);
	// 	tmp = tmp->next;
	// //  n1 = stack_a->nbr;
	// //  printf("%d\n", n1);
	// //  stack_a = stack_a->next;
	// //  n1 = stack_a->nbr;
	// //  printf("%d\n", n1);
	// //  stack_a = stack_a->next;
	// //  n1 = stack_a->nbr;
	// //  printf("%d\n", n1);
	// }
	 printf("**********************\n");

	iter = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		iter++;
	}
	 
	 printf("iter : %d\n", iter);
	// stack_a = stack_a->next;
	// 
	// printf("%c\n", argv[1][2]);
	// for(int i = 1; i < argc; i++)
	// {
	// 	printf("%s\n", argv[i]);
	// }
}
