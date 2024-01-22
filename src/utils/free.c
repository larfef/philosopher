/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:35:33 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/22 09:20:28 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosopher.h"

void	_destroy(t_config *data, t_list *thread)
{
	t_list	*temp;

	temp = data->first;
	while (temp != thread)
	{
		if (pthread_mutex_destroy(&temp->mutex) != 0)
			print_error(data, EMUTEXD);
		temp = temp->next;
	}
}

bool	_free(t_config *data, char *str)
{
	if (data->threads != NULL)
		free(data->threads);
	if (str != NULL)
		return (print_error(data, EALLOC));
	return (false);
}
