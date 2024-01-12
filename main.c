/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:44 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/12 17:00:16 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosopher.h"

t_philo	*init_struct(void)
{
	t_philo	*data;
	
	data = malloc(sizeof(*data));
	if (data == NULL)
		return (NULL);
	return (data);
}

int	init_threads_nb(char *str, t_philo *data)
{
	data->threads_nb = ft_atoi(str);
	if (data->threads_nb > 0 && data->threads_nb <= 200)
		return (0);
	free(data);
	return (1);
}

int	init_threads(t_philo *data)
{
	data->threads = malloc(sizeof(*data->threads) * data->threads_nb);
	if (data->threads == NULL)
		return (1);
	return (0);
}

void	*start_routine(void *ptr)
{
	int	*ret = (int *)ptr;
	*ret = printf("thread created\n");
	return (ptr);
}

int	main(int argc, char **argv)
{
	t_philo	*data;
	
	data = init_struct();
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
