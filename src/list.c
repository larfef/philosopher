/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:44:33 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/18 16:09:23 by rkersten         ###   ########.fr       */
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

void	lst_iter(int argc, char **argv, void (*function)(int, void *, void *),
					t_thread *first)
{
	t_thread	*temp;

	temp = first;
	while (temp != NULL)
	{
		function(argc, argv, temp);
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

	node = ft_calloc(1, sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->previous = NULL;
	node->next = NULL;
	return (node);
}
