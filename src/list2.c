/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 09:27:34 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/20 09:34:36 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	link_unlink_list(t_thread *first)
{
	t_thread	*last;

	last = lst_last(first);
	if (first->previous == NULL
		&& last->next == NULL)
	{
		first->previous = last;
		last->next = first;
	}
	else if (first->previous == last
		&& last->next == first)
	{
		first->previous = NULL;
		last->next = NULL;
	}
}
