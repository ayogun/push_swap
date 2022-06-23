/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:39:36 by yogun             #+#    #+#             */
/*   Updated: 2022/05/12 20:08:35 by yogun            ###   ########.fr       */
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

//function to add a new node to the stack from back side
void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	t_stack	*tmp1;

	tmp1 = *stack;
	if (tmp1 == NULL)
	{
		stack_new->next = NULL;
		stack_new->prev = NULL;
		*stack = stack_new;
	}
	else if (tmp1->next == NULL)
	{
		tmp1->next = stack_new;
		tmp1->prev = NULL;
		stack_new->prev = tmp1;
		stack_new->next = NULL;
	}
	else
	{
		tmp1 = tmp1->prev;
		tmp1->next = stack_new;
		tmp1->next->prev = tmp1;
		tmp1 = tmp1->next;
		tmp1->next = *stack;
		(*stack)->prev = tmp1;
	}	
}

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
	return (new);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	isnegative;
	int	i;

	res = 0;
	i = 0;
	isnegative = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	//We check whether the value is negative or not
	if (str[i] == '-')
		isnegative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	//We are making an ASCII check just in case. If everything is okay we make necessary math operations to turn our string-
	//into an integer value. Our purpose to turn the value into integer, is the neccessity of doing math operations in arguments.
	while (str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += ((int)str[i] - 48);
		i++;
	}
	//If our isnegative value gives as '1' which means "true", it will lead us into our if condition and append a negative sign-
	//to the integer value.
	if (isnegative)
		return (-res);
	else
		return (res);
}

void	list_args(char **argv, t_stack **stack_a)
{
	long	i;

	i = 1;
	while (argv[i] != NULL)
	{
			//While arguments are valid, we start to add them into stack here one by one with while loop.
			//Atoi takes the number and turn it into an integer value where we can make math operations.
			//With stack new we create a new node for the current argument without linking it to list.
			//We make linking stage in ft_add_back call.
			ft_add_back(stack_a, ft_stack_new(ft_atoi(argv[i])));
		i++;
	}
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
	int n1;
	
	stack_a = NULL;
	//check if there are enough arguments
	if (argc < 2)
		return (0);
	//check if the arguments are valid
	else if (!check_args(argv))
		ft_error();
	//create the stack
	list_args(argv, &stack_a);
	n1 = stack_a->nbr;
	stack_a = stack_a->next;
	printf("%ld\n", stack_a->nbr + n1);
	// printf("%c\n", argv[1][2]);
	// for(int i = 1; i < argc; i++)
	// {
	// 	printf("%s\n", argv[i]);
	// }
}
