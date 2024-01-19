/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:54 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/19 17:45:13 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H


# include <sys/wait.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include "constant.h"
# include "structure.h"

int			_atoi(const char *str);
void		_bzero(void *s, size_t n);
void		*_calloc(size_t count, size_t size);
int			create_thread(t_config *data);
void		_destroy(void *ptr1, void *ptr2);
int			_free(t_config *data);
size_t		get_timestamp(struct timeval *start_time,
					struct timeval *current_time);
size_t		get_ms_time(struct timeval *tv);
int			init_config(int	argc, char **argv, t_config *data);
int			init_list(t_config *data);
void		*init_node(t_config *data, t_thread *node);
int			lstadd_back(t_thread *first);
void		lst_clear(int nb, t_thread *first);
void		*lst_iter(void *(*function)(t_config *, t_thread *), t_config *data);
t_thread	*lst_last(t_thread *first);
t_thread	*lst_new(void);
int			parse_argc_argv(int argc, char **argv);
void		print_message(t_config *data, t_thread *thread, char *str);
int			print_error(char *str);
void		sleep_us(size_t duration);
size_t		_strlen(const char *s);
int			_strncmp(const char *s1, const char *s2, size_t n);

#endif