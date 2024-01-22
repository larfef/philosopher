/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:24:59 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/22 10:27:59 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"

void	lock_mutex(t_list *thread)
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

void	unlock_mutex(t_list *thread)
{
	thread->ret = pthread_mutex_lock(&thread->mutex);
	if (thread->ret)
		return ;
	if (thread->mutex_lock == true)
		thread->ret = pthread_mutex_lock(&thread->next->mutex);
	if (thread->ret)
		thread->ret = pthread_mutex_unlock(&thread->mutex);
	if (thread->ret)
		return ;
	if (thread->mutex_lock == true
		&& thread->next->mutex_lock == true)
	{
		thread->mutex_lock = false;
		thread->next->mutex_lock = false;
		thread->state = SLEEP;
	}
	thread->ret = pthread_mutex_unlock(&thread->mutex);
	if (thread->ret)
		return ;
	thread->ret = pthread_mutex_unlock(&thread->next->mutex);
	if (thread->ret)
		return ;
}
