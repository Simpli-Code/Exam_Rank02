/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 06:28:37 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 10:43:07 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : ft_list_size
Expected files   : ft_list_size.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure in your program ft_list_size.c :

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;


int	ft_list_size(t_list *begin_list)
{
	int	size = 0;

	while (begin_list)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}




// The below functions are not required!!! It is just for testing purposes.

t_list	*lst_new(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

t_list	*add_node_to_list(t_list *lst, void *data)
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
	size_t	i;
	t_list	*lst;
	char *s[]={"This", "is", "a", "linked", "list", "test", "to", "count", "the", "list", "size"};
	char ref[]="list";
	size_t size = sizeof(s) / sizeof(s[0]);

	i = size - 1;
	lst = lst_new(s[0]);
	while (i > 0)
	{
		add_node_to_list(lst, s[i]);
		i--;
	}
	printf("The Size of List is: %d\n", ft_list_size(lst));
	return (0);
}
