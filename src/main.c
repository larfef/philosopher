/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:44 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/18 16:24:39 by rkersten         ###   ########.fr       */
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
	t_config	*data;

	if (parse_argc_argv(argc, argv) == 1
		|| init_config(argc, argv, &data) == 1)
		return (1);
	
	if (data != NULL
		&& init_threads_nb(argv[1], data) == 0)
	{
		free(data);
		return (0);
	}
	//free(data->threads);
	//free(data);
	//pthread_create(&thread, NULL, start_routine, &nb);
	//sleep_us(3000000);
	return (0);
}
