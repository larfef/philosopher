/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:44 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/19 17:46:01 by rkersten         ###   ########.fr       */
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

	if (parse_argc_argv(argc, argv) == 1
		|| init_config(argc, argv, &data) == 1
		|| init_list(&data) == 1
		|| create_thread(&data) == 1)
		return (1);
	_free(&data);
	lst_clear(data.nb, data.first);
	return (0);
}
