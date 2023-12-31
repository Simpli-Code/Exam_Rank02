/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:37:59 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:35:41 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>
#include <stdio.h>

int	check_dupli(char *s, char c, int index)
{
	int	i = 0;

	while (s[i] && (i < index || index == -1))
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	inter(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i])
	{
		if (!check_dupli(s1, s1[i], i) && check_dupli(s2, s1[i], -1))
			write (1, &s1[i], 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		inter(argv[1], argv[2]);
	}
	write (1, "\n", 1);
	return (0);
}
