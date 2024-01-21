/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:33:36 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/21 12:24:30 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

static	void	check_end_condition(t_config *time, t_list *thread)
{
	thread->ret = gettimeofday(&thread->current_time, NULL);
	if (thread->ret)
		return ;
	if (get_time(&thread->current_time, MS)
		- get_time(&time->start_time, MS) >= (size_t)time->die)
		thread->state = DEAD;
	if (thread->state == DEAD)
		return (print_message(time, thread, MDIE));
	if (thread->meals == 0)
		thread->state = STOP;
}

static	void	eat_state(t_config *time, t_list *thread)
{
	if (thread->state == EAT && time->eat >= time->die)
	{
		thread->ret = sleep_us(time->die);
		if (thread->ret)
			return ;
		thread->state = DEAD;
		return (print_message(time, thread, MDIE));
	}
	else if (thread->state == EAT && time->eat < time->die)
	{
		thread->last_meal = get_timestamp(&time->start_time, thread);
		if (thread->ret == 0)
			return ;
		thread->ret = sleep_us(time->eat);
		if (thread->ret)
			return ;
		if (time->argc == 6)
			thread->meals--;
		thread->state = SLEEP;
		return ;
	}
}

static	void	sleep_state(t_config *time, t_list *thread)
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
		thread->ret = sleep_us(time->die);
}

static	void	set_list_state(t_list *thread)
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

void	handle_state(t_config *data, t_list *thread)
{
	check_end_condition(thread);
	if (thread->ret || thread->state == STOP || thread->state == DEAD)
		return ;
	set_list_state(thread);
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
