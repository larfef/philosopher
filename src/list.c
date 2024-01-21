/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:44:33 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/21 12:48:48 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	link_unlink_list(t_list *first, int mode)
{
	t_list	*temp;

	temp = first;
	if (mode == LINK)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = first;
	}
	else
	{
		while (--mode)
			temp = temp->next;
		temp->next = NULL;
	}
}

int	lstadd_back(t_list *first)
{
	t_list	*node;
	t_list	*temp;

	node = lst_new();
	if (node == NULL)
		return (1);
	temp = first;
	while (temp->next != NULL)
		temp = temp->next;
	node->next = NULL;
	temp->next = node;
	return (0);
}

void	lst_clear(t_list *first)
{
	t_list	*temp;

	temp = first->next;
	while (temp != NULL)
	{
		free(first);
		first = temp;
		temp = temp->next;
	}
	free(first);
}

t_list	*lst_iter(t_list *(*function)(t_config *, t_list *), t_config *data)
{
	int			pos;
	void		*ret;
	t_list	*temp;

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

t_list	*lst_new(void)
{
	t_list	*node;

	node = _calloc(1, sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	return (node);
}

// t_list	*lst_last(t_list *first)
// {
// 	t_list	*temp;

// 	temp = first;
// 	while (temp->next != NULL)
// 		temp = temp->next;
// 	return (temp);
// }