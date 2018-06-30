/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pourc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:05:20 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/21 18:36:04 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_aux(t_format **f, t_conv *p)
{
	if (p->fl_zero == 1 && p->fl_minus == 0)
		ft_s_empty(f, (*f)->pos_b, (p->width - 1), '0');
	else
		ft_s_empty(f, (*f)->pos_b, (p->width - 1), ' ');
	return (1);
}

int			ft_handle_pourc(t_format **f, t_conv *p)
{
	if (p->width > 0)
	{
		if (p->fl_minus == 0)
			ft_aux(f, p);
		ft_strcat((*f)->buffer, "%");
		(*f)->pos_b++;
		if (p->fl_minus == 1)
			ft_aux(f, p);
	}
	else
	{
		ft_strcat((*f)->buffer, "%");
		(*f)->pos_b++;
	}
	(*f)->lst_pourc = (*f)->pos_b;
	return (1);
}
