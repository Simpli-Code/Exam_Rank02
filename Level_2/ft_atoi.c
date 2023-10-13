/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:37:35 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 09:23:57 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

#include <unistd.h>

int	ft_atoi(char *s)
{
	int	i = 0;
	int	sum = 0;
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
	return ((int)sum * sign);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	nbr = nbr % 10 + '0';
	write (1, &nbr, 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_putnbr(ft_atoi(argv[1]));
	}
	write (1, "\n", 1);
	return (0);
}
