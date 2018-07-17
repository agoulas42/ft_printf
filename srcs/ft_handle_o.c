/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uoxx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:08:42 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/17 13:46:06 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	hand_o_p2(t_format **f, char **num, t_conv *p, union u_uox value)
{
	int		i;
	int		ret_signe;
	char	c;
	int		d;

	d = ft_strlen(*num);
	ret_signe = return_sign_uox(p, value);
	i = (p->fl_diese == 1 && ret_signe != 0) ? 1 : 0;
	c = (p->fl_zero == 1 && p->fl_minus == 0) ? '0' : ' ';
	if (p->fl_diese == 0 && p->precs == 0 && ret_signe == 0)
	{
		ft_s_empty(f, p->width, ' ');
		return (1);
	}
	if (p->width > 0 && p->width > d && p->fl_minus == 0)
		ft_s_empty(f, (p->width - d - i), ' ');
	if (i == 1)
		ft_s_empty(f, i, '0');
	write_buffer_str(f, *num, d);
	if (p->width > 0 && p->width > d && p->fl_minus == 1)
		ft_s_empty(f, (p->width - d - i), ' ');
	return (1);
}

static int	hand_o_prec(t_format **f, char **num, t_conv *p, union u_uox value)
{
	int		i;
	int		ret_signe;
	int		d;

	d = ft_strlen(*num);
	ret_signe = return_sign_uox(p, value);
	i = (p->fl_diese == 1 && ret_signe != 0) ? 1 : 0;
	if (p->precs > d)
	{
		if (p->width > 0 && p->width > p->precs && p->fl_minus == 0)
			ft_s_empty(f, (p->width - p->precs), ' ');
		ft_s_empty(f, (p->precs - d - i), '0');
		if (i == 1)
			ft_s_empty(f, i, '0');
		write_buffer_str(f, *num, d);
		if (p->width > 0 && p->width > p->precs && p->fl_minus == 1)
			ft_s_empty(f, (p->width - p->precs), ' ');
	}
	else
		return (hand_o_p2(f, num, p, value));
	return (1);
}

static int	hand_o_aux(t_format **f, char **num, t_conv *p, union u_uox value)
{
	int		i;
	int		d;
	int		ret_signe;
	char	c;

	d = ft_strlen(*num);
	ret_signe = return_sign_uox(p, value);
	i = (p->fl_diese == 1 && ret_signe != 0) ? 1 : 0;
	c = (p->fl_zero == 1 && p->fl_minus == 0) ? '0' : ' ';
	if (p->fl_minus == 0)
		ft_s_empty(f, (p->width - d - i), c);
	if (i == 1)
		ft_s_empty(f, i, '0');
	write_buffer_str(f, *num, d);
	if (p->fl_minus == 1)
		ft_s_empty(f, (p->width - d - i), ' ');
	return (1);
}

static int	hand_o(t_format **f, char **num, t_conv *p, union u_uox value)
{
	int		i;
	int		ret_signe;
	int		d;

	d = ft_strlen(*num);
	ret_signe = return_sign_uox(p, value);
	i = (p->fl_diese == 1 && ret_signe != 0) ? 1 : 0;
	if (p->precs > -1)
		return (hand_o_prec(f, num, p, value));
	if (p->width == 0)
	{
		if (i == 1)
			ft_s_empty(f, i, '0');
		write_buffer_str(f, *num, d);
	}
	else
		return (hand_o_aux(f, num, p, value));
	return (1);
}

int			ft_handle_o(t_format **f, t_conv *p, va_list *ap)
{
	char		*num;
	union u_uox	value;

	if ((ft_init_union_uox(&value, p, ap) == 0)
			|| ((num = ft_itoa_union_uox(value, p)) == NULL))
		return (0);
	hand_o(f, &num, p, value);
	(*f)->pos_b = ft_strlen((*f)->buffer);
	(*f)->lst_pourc = (*f)->pos_b;
	free(num);
	return ((*f)->pos_b);
}
