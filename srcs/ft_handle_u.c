/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uoxx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:08:42 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/17 13:46:37 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	hand_up_aux(t_format **f, char **num, t_conv *p, union u_uox value)
{
	int		d;
	int		v;
	int		ret_signe;

	d = ft_strlen(*num);
	ret_signe = return_sign_uox(p, value);
	if (p->precs == 0 && return_sign_uox(p, value) == 0)
		return (1);
	v = (p->precs > d) ? p->precs : d;
	if (p->fl_minus == 0 && p->width > v)
		ft_s_empty(f, (p->width - v), ' ');
	if (p->precs > d)
		ft_s_empty(f, (p->precs - d), '0');
	write_buffer_str(f, *num, d);
	if (p->fl_minus == 1 && p->width > v)
		ft_s_empty(f, (p->width - v), ' ');
	return (1);
}

static int	hand_up(t_format **f, char **num, t_conv *p, union u_uox value)
{
	int		d;
	char	c;
	int		ret_signe;

	c = (p->fl_zero == 1 && p->fl_minus == 0) ? '0' : ' ';
	d = ft_strlen(*num);
	ret_signe = return_sign_uox(p, value);
	if (p->precs == 0 && return_sign_uox(p, value) == 0)
		return (1);
	if (p->precs < d && p->precs != 0)
	{
		if (p->fl_minus == 0 && p->width > d)
			ft_s_empty(f, (p->width - d), ' ');
		write_buffer_str(f, *num, d);
		if (p->fl_minus == 1 && p->width > p->precs)
			ft_s_empty(f, (p->width - d), ' ');
	}
	else
		return (hand_up_aux(f, num, p, value));
	return (1);
}

static int	hand_u(t_format **f, char **num, t_conv *p, union u_uox value)
{
	int		d;
	char	c;

	c = (p->fl_zero == 1 && p->fl_minus == 0) ? '0' : ' ';
	d = ft_strlen(*num);
	if (p->precs > -1)
		return (hand_up(f, num, p, value));
	if (p->fl_minus == 0 && p->width > 0)
		ft_s_empty(f, (p->width - d), c);
	write_buffer_str(f, *num, d);
	if (p->fl_minus == 1 && p->width > 0)
		ft_s_empty(f, (p->width - d), c);
	return (1);
}

int			ft_handle_u(t_format **f, t_conv *p, va_list *ap)
{
	char			*num;
	union u_uox		value;

	if ((ft_init_union_uox(&value, p, ap) == 0)
			|| ((num = ft_itoa_union_uox(value, p)) == NULL))
		return (0);
	hand_u(f, &num, p, value);
	(*f)->pos_b = ft_strlen((*f)->buffer);
	(*f)->lst_pourc = (*f)->pos_b;
	free(num);
	return (1);
}
