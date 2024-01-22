/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:29:48 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/22 09:08:41 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"

int	set_error(t_config *data, int errnum)
{
	data->errnum = errnum;
	return (ERROR);
}

void	stop_simulation(t_config *data, t_list *thread)
{
	if (pthread_mutex_lock(&data->stop_simulation) != 0)
		return ;
	if (data->is_ret == false)
	{
		if (thread->state == DEAD)
			data->is_dead = true;
		data->ret = thread->ret;
		data->is_ret = true;
	}
	pthread_mutex_unlock(&data->stop_simulation);
}

void	start_simulation(t_config *data, t_list *thread)
{
	thread->ret = pthread_mutex_lock(&data->start_simulation);
	if (thread->ret)
		return ;
	thread->ret = pthread_mutex_unlock(&data->start_simulation);
	if (thread->ret)
		return ;
}

void	one_thread(t_config *time, t_list *thread)
{
	print_message(time, thread, MTHINK);
	if (thread->ret)
		return ;
	sleep_us(time->die);
	if (thread->ret)
		return ;
	print_message(time, thread, MDIE);
}

void	*start_routine(void *arg)
{
	t_arg	*data;

	data = (t_arg *)arg;
	
	start_simulation(data->config, data->thread);
	if (data->config->ret || data->thread->ret)
		return (NULL);
	if (data->config->nb > 1)
		multiple_thread(data->config, data->thread);
	else
		one_thread(data->config, data->thread);
	stop_simulation(data->config, data->thread);
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
	t_arg		arg;
	t_list		*temp;

	i = -1;
	temp = data->first;
	while (++i != data->nb)
	{
		arg.config = data;
		arg.thread = temp;
		data->ret = pthread_create(&data->threads[i], NULL,
									start_routine, (void *)&arg);
		if (data->ret)
			break;
		temp = temp->next;
	}
	if (gettimeofday(&data->start_time, NULL) == 0
		&& pthread_mutex_unlock(&data->start_simulation) == 0)
		return (_wait(data));
	return (1);
}

