/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:44 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/22 09:20:14 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"

int	main(int argc, char **argv)
{
	int			ret;
	t_config	data;

	if (parse_argc_argv(argc, argv) == 1
		|| init_config(argc, argv, &data) == 1
		|| init_list(&data) == 1)
		return (1);
	link_unlink_list(data.first, LINK);
	ret = create_thread(&data);
	link_unlink_list(data.first, 1);
	_destroy(&data, data.first);
	_free(&data, NULL);
	lst_clear(data.first);
	return (ret);
}
