/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:14:58 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 09:25:13 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : camel_to_snake.c
Expected files   : camel_to_snake.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/

#include <unistd.h>

void	camel_to_snake(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			write (1, "_", 1);
			s[i] += ('a' - 'A');
		}
		write (1, &s[i++], 1);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		camel_to_snake(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}
