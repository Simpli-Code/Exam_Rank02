/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:36:34 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 10:14:55 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display '\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

#include <unistd.h>
#include <stdio.h>

void	rev_wstr(char *s)
{
	int	i = 0;
	int	end = 0;
	int	flag = 0;
	int	start = 0;

	while (s[i])
		i++;
	i--;
	while (i > 0)
	{
		while (s[i] == ' ' || s[i] == '\t')
			i--;
		end = i;
		while (s[i] && s[i] != ' ' && s[i] != '\0')
			i--;
		start = i + 1;
		flag = start;
		while (start <= end)
			write (1, &s[start++], 1);
		if (flag != 0)
			write (1, " ", 1);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		rev_wstr(argv[1]);
		write (1, "\n", 1);
	}
	else
		write (1, "\n", 1);
	return (0);
}
