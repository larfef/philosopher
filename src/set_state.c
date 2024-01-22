/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:24:59 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/22 20:22:43 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"

void	eat_state(t_config *time, t_list *thread)
{
	if (time->eat >= time->die)
	{
		thread->ret = sleep_us(time->die);
		if (thread->ret)
			return ;
		thread->state = DEAD;
		return (print_message(time, thread, MDIE));
	}
	if (time->eat < time->die)
	{
		thread->last_meal = get_timestamp(&time->start_time, thread);
		if (thread->ret)
			return ;
		thread->ret = sleep_us(time->eat);
		if (thread->ret)
			return ;
		if (time->argc == 6)
			thread->meals--;
		return ;
	}
}

void	sleep_state(t_config *time, t_list *thread)
{
	if (thread->state == SLEEP && time->sleep >= time->die)
	{
		thread->ret = sleep_us(time->die);
		if (thread->ret)
			return ;
		thread->state = DEAD;
		print_message(time, thread, MDIE);
	}
	else if (thread->state == SLEEP)
		thread->ret = sleep_us(time->sleep);
}

void	lock_mutex(t_config *data, t_list *thread)
{
	pthread_mutex_t	*first_mutex;
	pthread_mutex_t	*second_mutex;
	
	if (thread->pos % 2 == 0)
	{
		first_mutex = &thread->mutex;
		second_mutex = &thread->next->mutex;
	}
	else
	{
		sleep_us(100000);
		first_mutex = &thread->next->mutex;
		second_mutex = &thread->mutex;
	}
	thread->ret = pthread_mutex_lock(first_mutex);
	if (thread->ret)
		return ;
	thread->ret = pthread_mutex_lock(second_mutex);
	if (thread->ret)
		thread->ret = pthread_mutex_unlock(first_mutex);
	if (thread->ret)
		return ;
	print_message(data, thread, MEAT);
	if (thread->ret)
		return ;
	eat_state(data, thread);
	thread->ret = pthread_mutex_unlock(second_mutex);
	if (thread->ret)
		return ;
	thread->ret = pthread_mutex_unlock(first_mutex);
	thread->state = SLEEP;
}
