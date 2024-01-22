/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:38:48 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/22 17:39:25 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	*one_thread_routine(void *ptr)
{
	t_arg	*arg;

	arg = (t_arg *)ptr;
	print_message(arg->config, arg->thread, MTHINK);
	if (arg->thread->ret)
		return ((void *)&arg->thread->ret);
	sleep_us(arg->config->die);
	if (arg->thread->ret)
		return ((void *)&arg->thread->ret);
	print_message(arg->config, arg->thread, MDIE);
	return ((void *)&arg->thread->ret);
}

void	one_thread(t_config *data)
{
	t_arg	arg;

	arg.config = data;
	arg.thread = data->first;
	data->ret = gettimeofday(&data->start_time, NULL);
	if (data->ret)
		return ;
	data->ret = pthread_create(&data->threads[0], NULL, one_thread_routine, (void *)&arg);
	if (data->ret)
		return ;
	data->ret = pthread_join(data->threads[0], (void **)&data->first->ret);
	if (data->ret)
		return ;
	data->ret = data->first->ret;
}
