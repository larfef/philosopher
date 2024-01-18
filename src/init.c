/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:36:10 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/18 16:27:22 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"

int	init_config(int	argc, char **argv, t_config *data)
{
	data->die = false;
	data->first == NULL;
	data->nb = ft_atoi(argv[1]);
	data->threads = ft_calloc(1, sizeof(*data->threads));
	if (data->threads == NULL)
		return (1);
}

void	init_list();

void	init_node(int argc, char **argv, t_thread *node)
{
	node->die = ft_atoi(argv[2]);
	node->eat = ft_atoi(argv[3]);
	node->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		node->meals = ft_atoi(argv[5]);
}
