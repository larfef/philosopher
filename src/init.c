/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:36:10 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/19 11:49:52 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philosopher.h"

void	init_config(int	argc, char **argv, t_config *data)
{
	data->ealloc = false;
	data->nb = _atoi(argv[1]);
	data->threads = _calloc(data->nb, sizeof(*data->threads));
	if (data->threads == NULL)
		return (_free(EALLOC, data));
	data->forks = _calloc(data->nb, sizeof(*data->forks));
	if (data->forks == NULL)
		return (_free(EALLOC, data));
	data->argc = argc;
	data->argv = argv;
	data->is_dead = false;
	data->first = NULL;
	data->die = _atoi(argv[2]);
	data->eat = _atoi(argv[3]);
	data->sleep = _atoi(argv[4]);
}

void	init_list(t_config *data)
{
	int	i;
	
	data->first = lst_new();
	if (data->first == NULL)
		return (_free(EALLOC, data));
	i = 0;
	while (++i < data->nb)
	{
		if (lstadd_back(data->first) == 1)
		{
			_free(EALLOC, data);
			return (lst_clear(i, data->first));
		}
	}
	lst_iter(init_node, data);
}

void	init_node(t_config *data, t_thread *node)
{
	node->die = false;
	node->eat = false;
	node->sleep = false;
	node->think = false;
	if (data->argc == 6)
		node->meals = _atoi(data->argv[5]);
}
// void	init_node(int argc, char **argv, t_thread *node)
// {
// 	node->die = _atoi(argv[2]);
// 	node->eat = _atoi(argv[3]);
// 	node->sleep = _atoi(argv[4]);
// 	if (argc == 6)
// 		node->meals = _atoi(argv[5]);
// }
