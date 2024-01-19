/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:54 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/19 11:48:13 by rkersten         ###   ########.fr       */
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

typedef struct t_list
{
	//int			die;
	//int			eat;
	//int			sleep;
	bool			die;
	bool			eat;
	bool			sleep;
	bool			think;
	int				meals;//5
	struct	t_list	*next;
	struct	t_list	*previous;
}	t_thread;

typedef	struct t_struct
{
	bool			ealloc;
	bool			*forks;
	bool			is_dead;
	char			**argv;
	int				argc;
	int				nb;//1
	int				die;//2
	int				eat;//3
	int				sleep;//4
	pthread_t		*threads;
	struct	t_list	*first;
}	t_config;

int			_atoi(const char *str);
void		_bzero(void *s, size_t n);
void		*_calloc(size_t count, size_t size);
void		_free(char *str, t_config *data);
size_t		get_ms_time(struct timeval *tv);
void		init_config(int	argc, char **argv, t_config *data);
void		init_list(t_config *data);
void		init_node(t_config *data, t_thread *node);
//void		init_node(int argc, char **argv, t_thread *node);
int			lstadd_back(t_thread *first);
void		lst_clear(int nb, t_thread *first);
// void		lst_iter(int argc, char **argv, void (*function)(int, void *, void *),
// 					t_thread *first);
void		lst_iter(void (*function)(t_config *, t_thread *), t_config *data);
t_thread	*lst_last(t_thread *first);
t_thread	*lst_new(void);
int			parse_argc_argv(int argc, char **argv);
void		sleep_us(size_t duration);
size_t		_strlen(const char *s);
int			_strncmp(const char *s1, const char *s2, size_t n);

#endif