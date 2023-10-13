/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:27:48 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:37:27 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "forty two" "qfqfsoudf arzgrsayns tsryegftdgs sjytwdekuooixq " | cat -e
forty two$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/

#include <unistd.h>
#include <stdio.h>

void	wdmatch(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;
	int	len = 0;

	while (s1[len])
		len++;
	while (s2[j] && i < len)
	{
		if (s2[j] == s1[i])
			i++;
		j++;
	}
	if (i == len)
	{
		i = 0;
		while (s1[i])
			write (1, &s1[i++], 1);
	}
}

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		wdmatch(argv[1], argv[2]);
	}
	write (1, "\n", 1);
	return (0);
}
