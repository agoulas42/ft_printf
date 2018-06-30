/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uoxx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:08:42 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/29 16:10:07 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_add_0x_x(t_format **f, int i, t_conv *p)
{
	if (i == 2)
	{
		if (p->specifier == 'x')
			ft_strcat((*f)->buffer, "0x");
		else
			ft_strcat((*f)->buffer, "0X");
		(*f)->pos_b = (*f)->pos_b + 2;
	}
}

void		ft_add_0x_o(char **num, t_conv *p)
{
	if (p->specifier == 'o' || p->specifier == 'O')
		ft_strcat(*num, "0");
}

int			ft_handle_uox(t_format **f, t_conv *p, va_list *ap)
{
	if (p->specifier == 'o' || p->specifier == 'O')
	{
		return (ft_handle_o(f, p, ap));
	}
	else if (p->specifier == 'u' || p->specifier == 'U')
	{
		return (ft_handle_u(f, p, ap));
	}
	else if (p->specifier == 'x' || p->specifier == 'X')
	{
		return (ft_handle_x(f, p, ap));
	}
	else
		return (0);
	return (1);
}
