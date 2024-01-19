/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:25:53 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/19 17:40:16 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosopher.h"

int	print_error(char *str)
{
	printf(str);
	return (1);
}

void	print_message(t_config *data, t_thread *thread, char *str)
{
	printf("%lu %d %s", get_timestamp(&data->start_time, &thread->current_time),
			thread->pos, str);
}