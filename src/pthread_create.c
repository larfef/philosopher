/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:29:48 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/19 15:42:48 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"

void	*start_routine(void *arg)
{
	t_arg	*data;

	pthread_mutex_lock(&data->config->start_simulation);
	pthread_mutex_unlock(&data->config->start_simulation);
	if (data->config->nb == 1)
	{
		sleep_us((size_t)data->thread->die);
		print_message(data->config, data->thread, DIE);
		return ((void *)&data->thread);
	}
	data = (t_arg *)arg;
	pthread_mutex_lock(&data->thread->previous->fork);
	pthread_mutex_lock(&data->thread->next->fork);
	print_message(data->config, data->thread, FORK);
	print_message(data->config, data->thread, EAT);
	sleep_us((size_t)data->config->eat);
	pthread_mutex_unlock(&data->thread->previous->fork);
	pthread_mutex_unlock(&data->thread->next->fork);
	print_message(data->config, data->thread, SLEEP);
	sleep_us((size_t)data->config->sleep);
	data->thread->meals++;
}

int	create_thread(t_config *data)
{
	int			i;
	t_arg		arg;
	t_thread	*temp;

	i = -1;
	temp = data->first;
	while (++i != data->nb)
	{
		arg.config = data;
		arg.thread = temp;
		pthread_create(&data->threads[i], NULL, start_routine, (void *)&arg);
		temp = temp->next;
	}
	gettimeofday(&data->start_time, NULL);
	pthread_mutex_unlock(&data->start_simulation);
}