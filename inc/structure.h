#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <sys/time.h>
# include <pthread.h>

typedef struct t_list
{
	bool			mutex_lock;
	bool			die;
	bool			eat;
	bool			sleep;
	bool			think;
	int				last_meal;
	int				meals;//5
	int				pos;
	int				ret;
	int				state;
	pthread_mutex_t	mutex;
	struct	timeval	current_time;
	struct	t_list	*next;
}	t_list;

typedef	struct t_struct
{
	bool			ealloc;
	bool			is_dead;
	bool			is_ret;
	char			**argv;
	int				argc;
	int				nb;//1
	int				die;//2
	int				eat;//3
	int				errnum;
	int				ret;
	int				sleep;//4
	pthread_mutex_t	start_simulation;
	pthread_mutex_t	stop_simulation;
	pthread_mutex_t output;
	pthread_t		*threads;
	struct	t_list	*first;
	struct	timeval	start_time;
	size_t			timestamp;
}	t_config;

typedef struct t_arg
{
	t_config	*config;
	t_list		*thread;
}	t_arg;

#endif