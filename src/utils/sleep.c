/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:34 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/21 12:12:37 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosopher.h"

size_t	get_timestamp(struct timeval *start_time, t_list *thread)
{
	if (gettimeofday(&thread->current_time, NULL) == 0)
		return (((thread->current_time.tv_sec * 1000)
				+ (thread->current_time.tv_usec / 1000))
				- ((start_time->tv_sec * 1000)
				+ (start_time->tv_usec / 1000)));
	thread->ret = 1;
	return (1);
}

size_t	get_time(struct timeval *tv, int unit)
{
	size_t	time;

	return (((tv->tv_sec * 1000000) + tv->tv_usec) / unit);
}

bool	sleep_us(size_t duration)
{
	struct	timeval tv_start;
	struct	timeval	tv_end_sleep;

	if (gettimeofday(&tv_start, NULL) != 0
		|| gettimeofday(&tv_end_sleep, NULL) != 0)
		return (true);
	while (get_time(&tv_end_sleep, US) - get_time(&tv_start, US) != duration)
		if (gettimeofday(&tv_end_sleep, NULL) != 0)
			return (true);
	return (false);
}
