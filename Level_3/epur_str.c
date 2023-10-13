/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:09:02 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:39:20 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/

#include <unistd.h>

void	epur_str(char *s)
{
	int	i = 0;
	int	flag = 0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t')
			flag = 1;
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		{
			if (flag == 1)
				write (1, " ", 1);
			flag = 0;
			write (1, &s[i], 1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		epur_str(argv[1]);
		write (1, "\n", 1);
	}
	else
		write (1, "\n", 1);
	return (0);
}
