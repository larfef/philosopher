/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:29:48 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/21 21:58:42 by rkersten         ###   ########.fr       */
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
		stop_simulation(data, thread);
	thread->ret = pthread_mutex_unlock(&data->start_simulation);
	if (thread->ret)
		stop_simulation(data, thread);
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
	void	*ret;
	t_arg	*data;

	data = (t_arg *)arg;
	
	start_simulation(data->config, data->thread);
	if (data->thread->ret)
		return (NULL);
	if (data->config->nb > 1)
		multiple_thread(data->config, data->thread);
	else
		one_thread(data->config, data->thread);
	stop_simulation(data->config, data->thread);
	// if (data->config->nb == 1
	// 	&& (sleep_us((size_t)data->thread->die)))
	// {
	// 	sleep_us((size_t)data->thread->die);
	// 	print_message(data->config, data->thread, DIE);
	// 	return ((void *)&data->thread);
	// }
	// if (data->config->argc == 6)
	// 	if (data->thread->meals != 0)
	// 		data->thread->meals--;
}

int	_wait(t_config *data)
{
	int	i;

	i = 0;
	while (i != data->nb)
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
	return (data->ret);
}

int	create_thread(t_config *data)
{
	int			i;
	t_arg		arg;
	t_list	*temp;

	i = -1;
	temp = data->first;
	while (++i != data->nb)
	{
		arg.config = data;
		arg.thread = temp;
		if (pthread_create(&data->threads[i], NULL,
							start_routine, (void *)&arg) != 0)
			return (1);
		temp = temp->next;
	}
	if (gettimeofday(&data->start_time, NULL) != 0
		|| pthread_mutex_unlock(&data->start_simulation) != 0)
		return (1);
	return (_wait(data));
}

