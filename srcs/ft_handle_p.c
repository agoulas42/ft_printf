/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:05:01 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/17 13:47:33 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_p_value(va_list *ap)
{
	char		*num;
	uintmax_t	value;

	num = NULL;
	value = (uintmax_t)va_arg(*ap, uintmax_t);
	num = ft_itoa_base_uox(value, 16, 0);
	return (num);
}

static int	ft_hand_precs(t_format **f, char **num, t_conv *p)
{
	int d;
	int u;
	int v;

	d = ft_strlen(*num);
	u = (d > p->precs) ? p->precs : d;
	v = (p->width > d) ? p->width : u;
	if (p->width > 0 && p->width > d + 2 && p->width > p->precs)
		ft_s_empty(f, (p->width - (d + 2)), ' ');
	write_buffer_str(f, "0x", 2);
	if (p->precs == 0 && ft_strcmp(*num, "0") == 0)
		return (1);
	if (p->precs > 0)
		ft_s_empty(f, (p->precs - d), '0');
	write_buffer_str(f, *num, d);
	return (1);
}

static int	ft_hand_p(t_format **f, char **num, t_conv *p)
{
	int		d;
	char	c;

	c = (p->fl_minus == 0 && p->fl_zero == 1) ? '0' : ' ';
	d = ft_strlen(*num);
	if (p->fl_minus == 0 && p->width > (d + 2) && p->fl_zero == 0)
		ft_s_empty(f, (p->width - d - 2), ' ');
	write_buffer_str(f, "0x", 2);
	write_buffer_str(f, *num, d);
	if (p->width > (d + 2) && ((p->fl_minus == 1)
				|| ((p->fl_minus == 0 && p->fl_zero == 1))))
		ft_s_empty(f, (p->width - d - 2), c);
	return (1);
}

int			ft_handle_p(t_format **f, t_conv *p, va_list *ap)
{
	char		*num;
	int			d;
	char		c;

	num = NULL;
	c = (p->fl_minus == 0 && p->fl_zero == 1) ? '0' : ' ';
	num = ft_p_value(ap);
	if (p->precs > -1)
		ft_hand_precs(f, &num, p);
	else
	{
		d = ft_strlen(num);
		if (p->width == 0)
		{
			write_buffer_str(f, "0x", 2);
			write_buffer_str(f, num, d);
		}
		else
			ft_hand_p(f, &num, p);
		free(num);
	}
	(*f)->lst_pourc = (*f)->pos_b;
	return (1);
}
