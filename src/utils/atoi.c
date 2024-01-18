/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:45:33 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/05 18:45:33 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

static	size_t	get_nbr(const char *str, int *ptr_j, size_t *ptr_k, size_t j)
{
	size_t	i;
	size_t	k;

	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*ptr_j *= -1;
		str++;
	}
	i = 0;
	k = 0;
	while (str[j] == '0')
		j++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k *= 10;
		k += str[i] - 48;
		i++;
	}
	*ptr_k = i - j;
	return (k);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		j;
	size_t	k;

	j = 1;
	i = get_nbr(str, &j, &k, 0);
	if (i < 9223372036854775807 && k < 20)
		return ((int) i * j);
	if (i == 9223372036854775807 && j == -1)
		return (-1);
	else if (i == 9223372036854775807 && j == 1)
		return (-1);
	else if (k >= 19 && j == -1)
		return (-1);
	else
		return (-1);
}
