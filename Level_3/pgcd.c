/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:30:59 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:43:23 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

void	pgcd(char *s1, char *s2)
{
	int	n1, n2;

	if ((n1 = atoi(s1)) > 0 && (n2 = atoi(s2)) > 0)
	{
		while (n1 != n2)
		{
			if (n1 > n2)
				n1 = n1 - n2;
			else
				n2 = n2 - n1;
		}
	}
	printf ("%d\n", n1);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		pgcd(argv[1], argv[2]);
	}
	else
		printf("\n");
	return (0);
}
