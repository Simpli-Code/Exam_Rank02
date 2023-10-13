/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:36:06 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:46:27 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	int_len(int	nbr)
{
	int len = 0;
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int	len = int_len(nbr);
	char *s = malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	if (nbr < 0)
	{
		s[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		s[0] = '0';
	int i = 0;
	while (nbr != 0)
	{
		len--;
		s[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (s);
}
// The below part is not required!!! It just tests the output of the function.

int	ft_atoi(char *s)
{
	int	i = 0;
	long int	sum = 0;
	int	sign = 1;

	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		sum = sum * 10 + (s[i] - '0');
		i++;
	}
	return (sum * sign);
}

void	ft_putstr(char *s)
{
	int	i = 0;

	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_putstr(ft_itoa(ft_atoi(argv[1])));
	}
	write (1, "\n", 1);
	return (0);
}
