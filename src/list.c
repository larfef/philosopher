/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:44:33 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/19 11:46:42 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	lstadd_back(t_thread *first)
{
	t_thread	*node;
	t_thread	*temp;

	node = lst_new();
	if (node == NULL)
		return (1);
	temp = lst_last(first);
	node->previous = temp;
	node->next = NULL;
	temp->next = node;
	return (0);
}

void	lst_clear(int nb, t_thread *first)
{
	t_thread	*temp;

	temp = first;
	while (--nb)
	{
		temp = temp->next;
		free(temp->previous);
	}
	free(temp);
}

void		lst_iter(void (*function)(t_config *, t_thread *), t_config *data)
{
	t_thread	*temp;

	temp = data->first;
	while (temp != NULL)
	{
		function(data, temp);
		temp = temp->next;
	}
}

t_thread	*lst_last(t_thread *first)
{
	t_thread	*temp;

	temp = first;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

t_thread	*lst_new(void)
{
	t_thread	*node;

	node = _calloc(1, sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

// void	lst_iter(int argc, char **argv, void (*function)(int, void *, void *),
// 					t_thread *first)
// {
// 	t_thread	*temp;

// 	temp = first;
// 	while (temp != NULL)
// 	{
// 		function(argc, argv, temp);
// 		temp = temp->next;
// 	}
// }