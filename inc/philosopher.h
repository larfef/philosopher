/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:54 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/18 16:27:14 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "constant.h"
# include <sys/wait.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>

typedef	struct t_struct
{
	bool				die;
	int					nb;
	pthread_t			**threads;
	struct	t_thread	*first;
}	t_config;

typedef struct t_struct1
{
	int					die;
	int					eat;
	int					meals;
	int					sleep;
	struct	t_thread	*next;
	struct	t_thread	*previous;
}	t_thread;


int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
size_t		get_ms_time(struct timeval *tv);
int			init_config(int	argc, char **argv, t_config *data);
void		init_node(int argc, char **argv, t_thread *node);
int			lstadd_back(t_thread *first);
void		lst_clear(int nb, t_thread *first);
void		lst_iter(int argc, char **argv, void (*function)(int, void *, void *),
					t_thread *first);
t_thread	*lst_last(t_thread *first);
t_thread	*lst_new(void);
int			parse_argc_argv(int argc, char **argv);
void		sleep_us(size_t duration);

#endif