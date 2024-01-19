/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:17:28 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/19 14:09:28 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	parse_argc_argv(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (argc == 6 && _atoi(argv[--argc]) <= 0)
		return (1);
	while (--argc != 1)
		if (argv[argc] == NULL || *argv[argc] == '\0' 
			|| _atoi(argv[argc]) < 0 || _atoi(argv[argc]) > TIME_MAX)
			return (1);
	if (_atoi(argv[argc]) < 1 || _atoi(argv[argc]) > THREAD_MAX)
		return (1);
	return (0);
}
