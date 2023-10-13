/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:06:40 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 09:47:46 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/

#include <unistd.h>

void	rev_print(char *s)
{
	int	i = 0;

	while (s[i])
		i++;
	i--;
	while (i >= 0)
	{
		write (1, &s[i--], 1);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		rev_print(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}
