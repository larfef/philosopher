/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:03:51 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/21 12:03:26 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosopher.h"

void	*_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	range;

	range = count * size;
	if (size != 0 && count != (range / size))
		return (0);
	ptr = (void *) malloc(size * count);
	if (!ptr)
		return (NULL);
	memset(ptr, '\0', size * count);
	return (ptr);
}
