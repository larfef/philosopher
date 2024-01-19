/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:44 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/19 11:49:30 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"

// void	*start_routine(void *ptr)
// {
// 	int	*ret = (int *)ptr;
// 	*ret = printf("thread created\n");
// 	return (ptr);
// }

int	main(int argc, char **argv)
{
	t_config	data;

	if (parse_argc_argv(argc, argv) == 1)
		return (1);
	init_config(argc, argv, &data);
	init_list(&data);
	if (data.ealloc == true)
		return (1);
	//free(data->threads);
	//free(data);
	//pthread_create(&thread, NULL, start_routine, &nb);
	//sleep_us(3000000);
	_free(NULL, &data);
	lst_clear(data.nb, data.first);
	return (0);
}
