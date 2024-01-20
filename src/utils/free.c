/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:35:33 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/20 10:24:52 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosopher.h"

void	_destroy(t_config *data, t_thread *thread)
{
	t_thread	*temp;

	temp = thread;
	temp = temp->previous;
	while (temp != NULL)
	{
		if (pthread_mutex_destroy(&temp->fork) != 0)
			print_error(data, EMUTEXD);
		temp = temp->previous;
	}
}

bool	_free(t_config *data)
{
	if (data->threads != NULL)
		free(data->threads);
	return (print_error(data, EALLOC));
}
