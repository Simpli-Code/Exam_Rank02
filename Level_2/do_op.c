/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:37:30 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 09:23:30 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : do_op
Expected files   : do_op.c
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

void	do_op(int n1, char *s, int n2)
{
	if (s[0] == '+')
		printf("%d\n", n1 + n2);
	else if (s[0] == '-')
		printf("%d\n", n1 - n2);
	else if (s[0] == '*')
		printf("%d\n", n1 * n2);
	else if (s[0] == '/')
		printf("%d\n", n1 / n2);
	else if (s[0] == '%')
		printf("%d\n", n1 % n2);
	else
		return ;
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		do_op(atoi(argv[1]), argv[2], atoi(argv[3]));
	}
	else
		printf("\n");
}
