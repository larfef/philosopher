/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:35:33 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/19 11:45:01 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosopher.h"

void	_free(char *str, t_config *data)
{
	if (data->threads != NULL)
		free(data->threads);
	free(data->forks);
	if (str != NULL && _strncmp(EALLOC, str, _strlen(str)) == 0)
	{
		data->ealloc = true;
		printf(EALLOC);
	}
}
