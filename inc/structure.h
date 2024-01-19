#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "philosopher.h"

typedef struct t_list
{
	bool			die;
	bool			eat;
	bool			sleep;
	bool			think;
	int				meals;//5
	int				pos;
	pthread_mutex_t	fork;
	struct	timeval	current_time;
	struct	t_list	*next;
	struct	t_list	*previous;
}	t_thread;

typedef	struct t_struct
{
	bool			ealloc;
	bool			emutexinit;
	bool			is_dead;
	char			**argv;
	int				argc;
	int				nb;//1
	int				die;//2
	int				eat;//3
	int				sleep;//4
	pthread_mutex_t	start_simulation;
	pthread_t		*threads;
	struct	t_list	*first;
	struct	timeval	start_time;
	size_t			timestamp;
}	t_config;

typedef struct t_arg
{
	t_config	*config;
	t_thread	*thread;
}	t_arg;

#endif