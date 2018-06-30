/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:20:46 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/27 13:56:40 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	hand_prec2(t_format **f, char **num, t_conv *p, union u_di value)
{
	int u;
	int d;
	int i;

	i = 0;
	d = ft_strlen(*num);
	u = (p->precs < d) ? d : p->precs;
	if ((p->fl_space == 1 && return_sign_num(p, value) >= 0)
			|| p->fl_plus == 1 || return_sign_num(p, value) == -1)
		i = 1;
	if (p->width != 0 && p->precs >= 0)
	{
		if (p->width > u && p->fl_minus == 0)
			ft_s_empty(f, (*f)->pos_b, (p->width - u - i), ' ');
		i = ft_test_fldi(f, value, p);
		if (u > d)
			ft_s_empty(f, (*f)->pos_b, (u - d), '0');
		ft_strncat((*f)->buffer, *num, d);
		(*f)->pos_b = (*f)->pos_b + d;
		if (p->fl_minus == 1 && p->width > u)
			ft_s_empty(f, (*f)->pos_b, (p->width - u - i), ' ');
	}
	return (1);
}

static int	hand_prec(t_format **f, char **num, t_conv *p, union u_di value)
{
	int d;
	int u;
	int i;

	i = 0;
	d = ft_strlen(*num);
	u = (p->precs < d) ? d : p->precs;
	if (p->precs == 0 && return_sign_num(p, value) == 0)
	{
		i = ft_test_fldi(f, value, p);
		ft_s_empty(f, (*f)->pos_b, (p->width - u + 1), ' ');
		return (1);
	}
	if (p->width == 0)
	{
		ft_test_fldi(f, value, p);
		if (u > d)
			ft_s_empty(f, (*f)->pos_b, (u - d), '0');
		ft_strncat((*f)->buffer, *num, d);
	}
	else
		hand_prec2(f, num, p, value);
	return (1);
}

static int	hand_di2(t_format **f, char **num, t_conv *p, union u_di value)
{
	int		d;
	int		i;
	char	c;

	i = 0;
	d = 0;
	if ((p->fl_space == 1 && return_sign_num(p, value) >= 0
				&& p->fl_plus == 0)
			|| p->fl_plus == 1 || return_sign_num(p, value) == -1)
		i = 1;
	d = ft_strlen(*num) + i;
	if (p->width != 0 && p->width >= d)
	{
		c = (p->fl_minus == 0 && p->fl_zero == 1) ? '0' : ' ';
		if (p->fl_minus == 0 && p->fl_zero == 0)
			ft_s_empty(f, (*f)->pos_b, (p->width - d), c);
		ft_test_fldi(f, value, p);
		if (p->fl_minus == 0 && p->fl_zero == 1)
			ft_s_empty(f, (*f)->pos_b, (p->width - d), c);
		ft_strncat((*f)->buffer, *num, d - i);
		(*f)->pos_b = (*f)->pos_b + d - i;
		if (p->fl_minus == 1)
			ft_s_empty(f, (*f)->pos_b, (p->width - d), ' ');
	}
	return (1);
}

static int	hand_di(t_format **f, char **num, t_conv *p, union u_di value)
{
	int		d;
	char	c;
	int		i;

	i = 0;
	c = '\0';
	d = 0;
	if (p->precs != -1)
		return (hand_prec(f, num, p, value));
	else
	{
		if ((p->fl_space == 1 && return_sign_num(p, value) >= 0
					&& p->fl_plus == 0)
				|| p->fl_plus == 1 || return_sign_num(p, value) == -1)
			i = 1;
		d = ft_strlen(*num) + i;
		if (p->width == 0 || p->width < d)
		{
			i = ft_test_fldi(f, value, p);
			ft_strncat((*f)->buffer, *num, d - i);
		}
		else
			hand_di2(f, num, p, value);
	}
	return (1);
}

int			ft_handle_d_i(t_format **f, t_conv *p, va_list *ap)
{
	char		*num;
	union u_di	value;
	int			size;

	num = NULL;
	ft_init_union_di(&value, p, ap);
	num = ft_itoa_union_di(value, p);
	size = size_value(num, p, value);
	ft_buffer_check(f, size);
	hand_di(f, &num, p, value);
	(*f)->pos_b = ft_strlen((*f)->buffer);
	(*f)->lst_pourc = (*f)->pos_b;
	free(num);
	return (1);
}
