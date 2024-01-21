/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:54 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/21 12:49:25 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <errno.h>
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
void		_destroy(t_config *data, t_list *thread);
bool		_free(t_config *data);
size_t		get_timestamp(struct timeval *start_time, t_list *thread);
size_t		get_time(struct timeval *tv, int unit);
void		handle_state(t_config *data, t_list *thread);
int			init_config(int	argc, char **argv, t_config *data);
int			init_list(t_config *data);
void		link_unlink_list(t_list *first, int mode);
int			lstadd_back(t_list *first);
void		lst_clear(t_list *first);
t_list		*lst_iter(t_list *(*function)(t_config *, t_list *),
						t_config *data);
t_list		*lst_last(t_list *first);
t_list		*lst_new(void);
int			parse_argc_argv(int argc, char **argv);
void		print_message(t_config *data, t_list *thread, char *str);
bool		print_error(t_config *data, char *str);
bool		sleep_us(size_t duration);
size_t		_strlen(const char *s);
int			_strncmp(const char *s1, const char *s2, size_t n);

#endif