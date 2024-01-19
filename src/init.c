/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:36:10 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/19 17:44:32 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"

int	init_config(int	argc, char **argv, t_config *data)
{
	if (pthread_mutex_init(&data->start_simulation, NULL) != 0
		|| pthread_mutex_lock(&data->start_simulation) != 0)
		return (1);
	data->ealloc = false;
	data->nb = _atoi(argv[1]);
	data->threads = _calloc(data->nb, sizeof(*data->threads));
	if (data->threads == NULL)
		return (_free(data));
	data->argc = argc;
	data->argv = argv;
	data->emutexinit = false;
	data->is_dead = false;
	data->first = NULL;
	data->die = _atoi(argv[2]);
	data->eat = _atoi(argv[3]);
	data->sleep = _atoi(argv[4]);
	return (0);
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
			lst_clear(i, data->first);
			return (_free(data));
		}
	}
	ptr = lst_iter(init_node, data);
	if (ptr == NULL)
		return (0);
	_destroy(data, ptr);
	lst_clear(data->nb, data->first);
	free(data->threads);
	return (1);
}

void	*init_node(t_config *data, t_thread *node)
{
	node->die = false;
	node->eat = false;
	node->sleep = false;
	node->think = false;
	if (pthread_mutex_init(&node->fork, NULL) != 0)
		return ((void *)node);
	if (data->argc == 6)
		node->meals = _atoi(data->argv[5]);
	return (NULL);
}

