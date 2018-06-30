/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:57:54 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/26 14:48:07 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <locale.h>

static int	ft_hand_c(t_format **f, va_list *ap)
{
	int	c1;

	c1 = va_arg(*ap, int);
	(*f)->buffer[(*f)->pos_b] = c1;
	(*f)->pos_b++;
	return (c1);
}

int			ft_handle_c(t_format **f, t_conv *p, va_list *ap)
{
	int		c;
	char	d;

	c = 0;
	d = (p->fl_zero == 1 && p->fl_minus == 0) ? '0' : ' ';
	if (p->width > 0)
	{
		ft_buffer_check(f, p->width);
		if (p->fl_minus == 1)
			c = ft_hand_c(f, ap);
		ft_s_empty(f, (*f)->pos_b, (p->width - 1), d);
		if (p->fl_minus == 0)
			c = ft_hand_c(f, ap);
	}
	else
	{
		ft_buffer_check(f, 1);
		c = ft_hand_c(f, ap);
	}
	(*f)->lst_pourc = (*f)->pos_b;
	return (1);
}
