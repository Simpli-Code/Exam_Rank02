/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:31:05 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 10:04:20 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

int	ft_atoi(char *s)
{
	int	i = 0;
	int sum = 0;
	int sign = 1;

	if (s[i] == ' ')
		return (-1);
	if (s[i] == '-')
	{
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

void	print_hex(int nbr)
{
	int i = 0;
	int	arr[10];
	char hex[]="0123456789abcdef";

	if (nbr < 0)
		return ;
	if (nbr == 0)
	{
		write (1, "0", 1);
	}
	while (nbr != 0)
	{
		arr[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		write (1, &hex[arr[i] % 16], 1);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		print_hex(ft_atoi(argv[1]));
		write (1, "\n", 1);
	}
	else
		write (1, "\n", 1);
	return (0);
}
