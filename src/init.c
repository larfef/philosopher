/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:36:10 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/21 12:50:00 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"
#include <pthread.h>

int	init_config(int	argc, char **argv, t_config *data)
{
	memset(data, '\0', sizeof(*data));
	if (pthread_mutex_init(&data->start_simulation, NULL) != 0
		|| pthread_mutex_init(&data->output, NULL) != 0
		|| pthread_mutex_init(&data->stop_simulation, NULL) != 0
		|| pthread_mutex_lock(&data->start_simulation) != 0)
		return (1);
	data->nb = _atoi(argv[1]);
	data->threads = _calloc(data->nb, sizeof(*data->threads));
	if (data->threads == NULL)
		return (_free(data));
	data->argc = argc;
	data->argv = argv;
	data->die = _atoi(argv[2]);
	data->eat = _atoi(argv[3]);
	data->sleep = _atoi(argv[4]);
	return (0);
}

static	t_list	*init_node(t_config *data, t_list *node)
{
	if (pthread_mutex_init(&node->mutex, NULL) != 0)
		return (node);
	if (data->argc == 6)
		node->meals = _atoi(data->argv[5]);
	return (NULL);
}

int	init_list(t_config *data)
{
	int		i;
	void	*ptr;
	
	data->first = lst_new();
	if (data->first == NULL)
		return (_free(data));
	i = 0;
	while (++i < data->nb)
	{
		if (lstadd_back(data->first) == 1)
		{
			lst_clear(data->first);
			return (_free(data));
		}
	}
	ptr = lst_iter(init_node, data);
	if (ptr == NULL)
		return (0);
	_destroy(data, ptr);
	lst_clear(data->first);
	free(data->threads);
	return (1);
}
