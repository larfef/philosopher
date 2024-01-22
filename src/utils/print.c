/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:25:53 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/22 18:18:24 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosopher.h"

bool	print_error(t_config *data, char *str)
{
	if (pthread_mutex_lock(&data->output) != 0)
		return (true);
	printf("%s", str);
	pthread_mutex_unlock(&data->output);
	return (true);
}

void	print_message(t_config *data, t_list *thread, char *str)
{
	thread->ret = pthread_mutex_lock(&data->output);
	if (thread->ret)
		return ;
	// if (data->is_dead == false)
	// {
		printf("%lu %d %s", get_timestamp(&data->start_time, thread),
				thread->pos, str);
		if (thread->state == DEAD)
			data->is_dead = true;
	//}
	thread->ret = pthread_mutex_unlock(&data->output);
	return ;
}