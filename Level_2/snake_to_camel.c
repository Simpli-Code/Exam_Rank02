/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:18:18 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 09:36:39 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./camel_to_snake | cat -e
$
*/

#include <unistd.h>

void	snake_to_camel(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] == '_')
		{
			s[i+1] -= ('a' - 'A');
			i++;
		}
		write (1, &s[i++], 1);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		snake_to_camel(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}
