/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:29:48 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/20 22:35:26 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"

int	set_error(t_config *data, int errnum)
{
	data->errnum = errnum;
	return (ERROR);
}

void	stop_simulation(t_arg *data, int ret)
{
	pthread_mutex_lock(&data->config->stop_simulation);
	data->config->ret = ret;
	pthread_mutex_unlock(&data->config->stop_simulation);
}

void	*start_simulation(t_arg *data)
{
	int	ret;

	pthread_mutex_lock(&data->config->start_simulation);
	ret = pthread_mutex_unlock(&data->config->start_simulation);
	if (ret != 0)
		stop_simulation(data, ret);
	stop_simulation(data, handle_state(data));
}

void	*start_routine(void *arg)
{
	void	*ret;
	t_arg	*data;

	data = (t_arg *)arg;
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

int	_wait(t_config *data)
{
	int	ret;

	while (1)
	{
		ret = pthread_mutex_lock(&data->stop_simulation);
		if (ret != 0)
			return (ret);
		if (data->ret == 0)
		{
			ret = pthread_mutex_unlock(&data->stop_simulation);
			if (ret != 0)
				return (ret);	
		}
		else
			break;
	}
	ret = pthread_mutex_unlock(&data->stop_simulation);
	if (ret != 0)
		return (ret);
	return (data->ret);
}
