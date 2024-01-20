/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:34 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/20 14:46:51 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosopher.h"

size_t	get_timestamp(struct timeval *start_time, struct timeval *current_time)
{
	return (((current_time->tv_sec * 1000) + (current_time->tv_usec / 1000))
				- ((start_time->tv_sec * 1000) + (start_time->tv_usec / 1000)));
}

size_t	get_ms_time(struct timeval *tv)
{
	size_t	us_time;

	return (us_time = (tv->tv_sec * 1000000) + tv->tv_usec);
}

bool	sleep_us(size_t duration)
{
	struct	timeval tv_start;
	struct	timeval	tv_end_sleep;

	if (gettimeofday(&tv_start, NULL) != 0
		|| gettimeofday(&tv_end_sleep, NULL) != 0)
		return (true);
	while (get_ms_time(&tv_end_sleep) - get_ms_time(&tv_start) != duration)
		if (gettimeofday(&tv_end_sleep, NULL) != 0)
			return (true);
	return (false);
}
