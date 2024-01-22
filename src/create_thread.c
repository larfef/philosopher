/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:29:48 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/22 20:22:32 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"

void	stop_simulation(t_config *data, t_list *thread)
{
	if (pthread_mutex_lock(&data->stop_simulation) != 0)
		return ;
	if (data->is_dead == false)
	{
		if (thread->state == DEAD)
			data->is_dead = true;
	}
	pthread_mutex_unlock(&data->stop_simulation);
}

void	start_simulation(t_config *data, t_list *thread)
{
	thread->ret = pthread_mutex_lock(&data->start_simulation);
	if (thread->ret)
		return ;
	thread->ret = pthread_mutex_unlock(&data->start_simulation);
}

void	*start_routine(void *arg)
{
	t_arg	*data;

	data = (t_arg *)arg;
	start_simulation(data->config, data->thread);
	if (data->config->ret || data->thread->ret)
	{
		free(data);
		return (NULL);
	}
	while (data->thread->state != DEAD && data->thread->state != STOP)
		multiple_thread(data->config, data->thread);
	free(data);
	return (NULL);
}

int	_wait(t_config *data)
{
	int	i;

	i = 0;
	while (i != data->nb)
	{
		if (pthread_join(data->threads[i], NULL) != 0)
			return (1);
		i++;
	}
	return (data->ret);
}

int	create_thread(t_config *data)
{
	int			i;
	t_arg		*arg;
	t_list		*temp;

	i = -1;
	temp = data->first;
	while (++i != data->nb)
	{
		arg = _calloc(1, sizeof(*arg));
		arg->config = data;
		arg->thread = temp;
		data->ret = pthread_create(&data->threads[i], NULL,
									start_routine, (void *)arg);
		if (data->ret)
			break;
		temp = temp->next;
	}
	if (gettimeofday(&data->start_time, NULL) == 0
		&& pthread_mutex_unlock(&data->start_simulation) == 0)
		return (_wait(data));
	return (1);
}
