/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:30:18 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 16:51:10 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int	val_prohibit(int i)
{
	if (i < -2147483647 || i > 2147483647)
		return (-2147483648);
	else
		return (i);
}

int			ft_abs(int i)
{
	int a;

	if ((a = val_prohibit(i)) != i)
		return (a);
	if (i < 0)
		return (-i);
	else
		return (i);
}
