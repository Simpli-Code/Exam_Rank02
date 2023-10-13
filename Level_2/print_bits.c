/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:10:03 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:36:42 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/

#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	unsigned char bits;
	int	i = 7;

	while (i >= 0)
	{
		bits = ((octet >> i) & 1) + '0';
		write (1, &bits, 1);
		i--;
	}
}

int	main(void)
{
	print_bits(65);
	write (1, "\n", 1);
	return (0);
}
