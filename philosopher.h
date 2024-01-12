/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:54 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/12 16:53:02 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <sys/wait.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef	struct t_struct
{
	int			threads_nb;
	pthread_t	**threads;
}t_philo;

int		ft_atoi(const char *str);
size_t	get_ms_time(struct timeval *tv);
void	sleep_us(size_t duration);

#endif