/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:35:33 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/19 17:42:42 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosopher.h"

void	_destroy(void *ptr1, void *ptr2)
{
	t_config	*data;
	t_thread	*temp;

	data = (t_config *)ptr1;
	temp = (t_thread *)ptr2;
	temp = temp->previous;
	while (temp != NULL)
	{
		if (pthread_mutex_destroy(&temp->fork) != 0)
			print_error(EMUTEXD);
		temp = temp->previous;
	}
	data->emutexinit = true;
}

int	_free(t_config *data)
{
	if (data->threads != NULL)
		free(data->threads);
	return (print_error(EALLOC));
}
