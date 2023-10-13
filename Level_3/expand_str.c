/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:07:31 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 09:52:55 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/

#include <unistd.h>

void	expand_str(char *s)
{
	int i = 0;
	int	flag;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t')
			flag = 1;
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		{
			if (flag == 1)
				write (1, "   ", 3);
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
		expand_str(argv[1]);
		write (1, "\n", 1);
	}
	else
		write (1, "\n", 1);
	return (0);
}
