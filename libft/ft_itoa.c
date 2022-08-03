/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:29:23 by yogun             #+#    #+#             */
/*   Updated: 2022/04/06 02:57:24 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 ** count_cipher(int n): count cipher number, including sign minus.
 ** If the number is negative, we put the - sign to the left. 
 ** Once we enter the function str_numb,
 ** we will start placing numbers from the right to left. 
 ** So We will never overwrite the - sign if there is one,
 ** as the while condition (n > 0) of strn_number will prevent it.
 ** To handle the limiting case long long -2147483648LL,
 ** we have to convert the int n to unsigned int (we can cast it)
*/
static size_t	count_cipher(int n)
{
	size_t	cipher;

	cipher = 0;
	if (n <= 0)
		cipher++;
	while (n)
	{
		n = n / 10;
		cipher++;
	}
	return (cipher);
}

char	*str_numb(char *number, unsigned int n, int cipher)
{
	while (n > 0)
	{
		number[cipher--] = n % 10 + '0';
		n = n / 10;
	}
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number_str;
	int		cipher;

	cipher = count_cipher(n);
	number_str = (char *)malloc(sizeof(char) * cipher + 1);
	if (!number_str)
		return (NULL);
	number_str[cipher--] = '\0';
	if (n == 0)
	{
		number_str[cipher] = '0';
		return (number_str);
	}
	if (n < 0)
	{
		n = -n;
		number_str[0] = '-';
	}
	number_str = str_numb(number_str, (unsigned int)n, cipher);
	return (number_str);
}
