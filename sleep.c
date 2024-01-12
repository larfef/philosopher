/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:34 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/12 15:24:35 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

size_t	get_ms_time(struct timeval *tv)
{
	size_t	us_time;

	return (us_time = (tv->tv_sec * 1000000) + tv->tv_usec);
}

void	sleep_us(size_t duration)
{
	struct	timeval tv_start;
	struct	timeval	tv_end_sleep;

	gettimeofday(&tv_start, NULL);
	gettimeofday(&tv_end_sleep, NULL);
	while (get_ms_time(&tv_end_sleep) - get_ms_time(&tv_start) != duration)
		gettimeofday(&tv_end_sleep, NULL);
}
