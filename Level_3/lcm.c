/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:30:39 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 10:00:41 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

unsigned int	lcm(unsigned int a, unsigned int b);
2/3 = 6
6/10 = 30
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int num;
	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		num = a;
	else
		num = b;
	while (1)
	{
		if (num % a == 0 && num % b == 0)
			return (num);
		num++;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	nbr = nbr % 10 + '0';
	write (1, &nbr, 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		ft_putnbr(lcm((unsigned int)atoi(argv[1]), (unsigned int)atoi(argv[2])));
	}
	printf("\n");
	return (0);
}
