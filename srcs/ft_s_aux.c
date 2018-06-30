/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:20:28 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/04 17:06:16 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int			ft_s_empty(t_format **f, int start, int nbr, char c)
{
	int		i;

	i = 0;
	if (nbr <= 0)
		return (0);
	while (i < nbr)
	{
		(*f)->buffer[start + i] = c;
		i++;
	}
	(*f)->pos_b = (*f)->pos_b + i;
	return (1);
}
