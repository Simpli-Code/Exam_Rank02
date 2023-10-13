/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:37:10 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 10:42:21 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	int		data;
	t_list	*next;
};

int ascending(int a, int b)
{
	return (a <= b);
}

void	ft_swap(int *a, int *b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*tmp = lst;

	while (lst->next)
	{
		if (!cmp(lst->data, lst->next->data))
		{
			ft_swap(&lst->data, &lst->next->data);
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}



// The below functions are not required!!! It is just for testing purposes.

t_list	*ft_lstnew(int data)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_add_node_to_lst(t_list *lst, int data)
{
	t_list	*tmp = NULL;
	t_list	*new_node = NULL;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	tmp = lst->next;
	lst->next = new_node;
	new_node->data = data;
	new_node->next = tmp;
	return (new_node);
}

int	main(void)
{
	t_list	*lst = NULL;

	int arr[] = { 34, 111, 65, -99, 2, 0};

	int	size = sizeof(arr) / sizeof(arr[0]);
	int i = size - 1;

	lst = ft_lstnew(arr[0]);
	while (i > 0)
	{
		ft_add_node_to_lst(lst, arr[i]);
		i--;
	}
	t_list	*new_lst = lst;
	printf("before: ");
	while (lst)
	{
		printf(" %d\t", lst->data);
		lst = lst->next;
	}
	lst = new_lst;

	t_list	*lst_sorted = sort_list(lst, ascending);
	printf("\nafter: ");
	while (lst_sorted)
	{
		printf(" %d\t", lst_sorted->data);
		lst_sorted = lst_sorted->next;
	}
	printf("\n");

	return (0);
}
