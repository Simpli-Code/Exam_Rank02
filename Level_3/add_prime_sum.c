/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:53:00 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:39:00 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *s)
{
	int	i = 0;
	int	sum = 0;

	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		sum = sum * 10 + (s[i] - '0');
		i++;
	}
	return (sum);
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

int	is_prime(int nbr)
{
	int i = 2;

	while (i < nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void add_prime_sum(int nbr)
{
	if (nbr <= 0)
		return ;
	int sum = 0;
	while (nbr >= 2)
	{
		if (is_prime(nbr))
			sum = sum + nbr;
		nbr--;
	}
	ft_putnbr(sum);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		add_prime_sum(ft_atoi(argv[1]));
		write (1, "\n", 1);
	}
	else
		write (1, "0\n", 2);
	return (0);
}
