/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:44:33 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/20 10:43:56 by rkersten         ###   ########.fr       */
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

t_thread	*lst_iter(t_thread *(*function)(t_config *, t_thread *), t_config *data)
{
	int			pos;
	void		*ret;
	t_thread	*temp;

	pos = 1;
	temp = data->first;
	while (temp != NULL)
	{
		ret = function(data, temp);
		temp->pos = pos;
		temp = temp->next;
		pos++;
	}
	return (ret);
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
