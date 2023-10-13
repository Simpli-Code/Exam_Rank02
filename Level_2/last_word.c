/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:38:09 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 09:33:21 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>
#include <stdio.h>

void	last_word(char *s)
{
	int	i = 0;
	int	j = 0;

	while (s[i])
	{
		if (s[i] == ' ' && s[i+1] >= 33 && s[i+1] <= 126)
			j = i + 1;
		i++;
	}
	while (s[j] >= 33 && s[j] <= 126)
		write (1, &s[j++], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		last_word(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
