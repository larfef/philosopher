/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:44 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/20 10:46:02 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"

int	main(int argc, char **argv)
{
	t_config	data;

	if (parse_argc_argv(argc, argv) == 1
		|| init_config(argc, argv, &data) == 1
		|| init_list(&data) == 1
		|| create_thread(&data) == 1)
		return (1);
	link_unlink_list(data.first);
	_destroy(&data, lst_last(data.first));
	_free(&data);
	lst_clear(data.nb, data.first);
	return (0);
}
