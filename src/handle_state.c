/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:33:36 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/22 20:16:21 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

// static	void	check_end_condition(t_config *time, t_list *thread)
// {
// 	thread->ret = pthread_mutex_lock(&time->stop_simulation);
// 	if (thread->ret)
// 		return ;
// 	if (time->is_dead == true)
// 		thread->state = STOP;
// 	thread->ret = pthread_mutex_unlock(&time->stop_simulation);
// 	if (thread->state == STOP || thread->ret)
// 		return ;
// 	if (get_timestamp(&time->start_time, thread)
// 		- thread->last_meal >= (size_t)time->die)
// 		thread->state = DEAD;
// 	if (thread->state == DEAD)
// 		return (print_message(time, thread, MDIE));
// 	if (time->argc == 6 && thread->meals == 0)
// 		thread->state = STOP;
// }

void	multiple_thread(t_config *data, t_list *thread)
{
	//check_end_condition(data, thread);
	//stop_simulation(data, thread);
	if (thread->ret || thread->state == STOP || thread->state == DEAD)
		return ;
	lock_mutex(data, thread);
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

// void	multiple_thread(t_config *data, t_list *thread)
// {
// 	check_end_condition(data, thread);
// 	if (thread->ret || thread->state == STOP || thread->state == DEAD)
// 		return ;
// 	set_eat_state(data, thread);
// 	if (thread->ret)
// 		return ;
// 	if (thread->state == EAT)
// 	{
// 		print_message(data, thread, MEAT);
// 		if (thread->ret)
// 			return ;
// 		eat_state(data, thread);
// 		if (thread->ret)
// 			return ;
// 		print_message(data, thread, MSLEEP);
// 		if (thread->ret)
// 			return ;
// 		sleep_state(data, thread);
// 		if (thread->ret)
// 			return ;
// 		print_message(data, thread, MTHINK);
// 		if (thread->ret)
// 			return ;
// 	}
// }
