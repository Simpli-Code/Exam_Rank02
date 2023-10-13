/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:31:23 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:44:07 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that displays a number's multiplication table
The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.
If there are no parameters, the program displays \n.

Examples:
$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$> */

#include <unistd.h>

void	ft_tab_mult(int nbr)
{
	int	i = 1;

	if (nbr < 0)
		return ;
	while (i <= 9)
	{
		ft_putnbr(i);
		write (1, " x ", 3);
		ft_putnbr(nbr);
		write (1, " = ", 3);
		ft_putnbr(i * nbr);
		write (1, "\n", 1);
		i++;
	}
}

int	main(int argc, const char *argv[])
{
	if (argc == 2)
	{
		tab_mult(ft_atoi(argv[1]));
	}
	else
		write (1, "\n", 1);
	return (0);
}
