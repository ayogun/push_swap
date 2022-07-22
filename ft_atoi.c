/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:19:27 by yogun             #+#    #+#             */
/*   Updated: 2022/07/22 18:19:41 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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