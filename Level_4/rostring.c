/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:36:39 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 10:15:04 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

 void	rostring(char *s)
 {
 	int	i = 0;
 	int	flag = 0;

 	while (s[i] == ' ' || s[i] == '\t')
 		i++;
 	int	start = i;
 	while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
 		i++;
 	int	end = i;
 	while (s[i] == ' ' || s[i] == '\t')
 		i++;
 	while (s[i])
 	{
 		while (s[i] == ' ' && s[i+1] == ' ' || (s[i] == '\t' && s[i+1] == '\t'))
 			i++;
 		if (s[i] == ' ' || s[i] == '\t')
 			flag = 1;
 		write (1, &s[i++], 1);
 	}
 	if (flag == 1)
 		write (1, " ", 1);
 	while (start < end)
 		write (1, &s[start++], 1);
 }

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		rostring(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}
