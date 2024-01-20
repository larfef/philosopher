/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:33:36 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/20 22:38:42 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	eat_state(t_config *time, t_thread *thread)
{
	if (thread->state == EAT && time->eat >= time->die)
	{
		thread->ret = sleep_us(time->die);
		if (thread->ret)
			return ;
		thread->state = DEAD;
		return ;
	}
	else if (thread->state == EAT && time->eat < time->die)
	{
		thread->ret = sleep_us(time->eat);
		if (thread->ret)
			return ;
		thread->state = SLEEP;
		return ;
	}
}

void	handle_state(t_config *data, t_thread *thread)
{
	set_thread_state(thread);
	if (thread->ret)
		return ;
	if (thread->state == EAT)
	{
		print_message(data, thread, MEAT);
		if (thread->ret)
			return ;
		eat_state(data, thread);
		if (thread->ret)
			return ;
		print_message(data, thread, MSLEEP);
		if (thread->ret)
			return ;
		sleep_state(data, thread);
		if (thread->ret)
			return ;
		print_message(data, thread, MTHINK);
		if (thread->ret)
			return ;
	}
	handle_state(data, thread);
}

void	set_thread_state(t_thread *thread)
{
	thread->ret = pthread_mutex_lock(&thread->mutex);
	if (thread->ret)
		return ;
	if (thread->mutex_lock == false)
		thread->ret = pthread_mutex_lock(&thread->next->mutex);
	if (thread->ret)
		thread->ret = pthread_mutex_unlock(&thread->mutex);
	if (thread->ret)
		return ;
	if (thread->mutex_lock == false
		&& thread->next->mutex_lock == false)
	{
		thread->mutex_lock = true;
		thread->next->mutex_lock = true;
		thread->state = EAT;
	}
	thread->ret = pthread_mutex_unlock(&thread->mutex);
	if (thread->ret)
		return ;
	thread->ret = pthread_mutex_unlock(&thread->next->mutex);
	if (thread->ret)
		return ;
}

void	sleep_state(t_config *time, t_thread *thread)
{
	if (thread->state == SLEEP && time->sleep >= time->die)
	{
		thread->ret = sleep_us(time->die);
		if (thread->ret)
			return ;
		thread->state = DEAD;
	}
	else if (thread->state == SLEEP)
		thread->ret = sleep_us(time->die);
}
