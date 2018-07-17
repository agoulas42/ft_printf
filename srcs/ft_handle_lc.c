/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:57:54 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/30 18:27:35 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <locale.h>
#include <stdlib.h>

int			ft_handle_lc(t_format **f, t_conv *p, va_list *ap)
{
	int		c;
	int		d;
	wchar_t	c1;

	c1 = va_arg(*ap, wint_t);
	d = ft_wcharstrlen(c1);
	if (d == -1)
		return (-1);
	else
	{
		if (p->width == 0 || p->width < d)
			c = ft_char_wchar(f, c1, d);
		else
		{
			if (p->fl_minus == 1)
				c = ft_char_wchar(f, c1, d);
			ft_s_empty(f, (p->width - d), ' ');
			if (p->fl_minus == 0)
				c = ft_char_wchar(f, c1, d);
		}
		if (c != -1)
			(*f)->lst_pourc = (*f)->pos_b;
	}
	return (c);
}
