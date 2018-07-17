/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_none.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:32:56 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/17 13:55:24 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_handle_none(t_format **f, t_conv *p)
{
	char	c;
	int		d;

	d = (p->width > 1) ? p->width : 1;
	if (p->fl_minus == 1 && p->width > 0)
	{
		write_buffer(f, (*f)->format[(*f)->pos_f]);
		(*f)->pos_f++;
	}
	c = ((p)->fl_zero == 1 && (p)->fl_minus == 0) ? '0' : ' ';
	if ((p)->width > 1)
		ft_s_empty(f, ((p)->width - 1), c);
	if (p->fl_minus == 0 && p->width > 0)
	{
		write_buffer(f, (*f)->format[(*f)->pos_f]);
		(*f)->pos_f++;
	}
	free(p);
	return (1);
}
