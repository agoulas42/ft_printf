/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uoxx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:08:42 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/29 16:09:57 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	hand_x_paux(t_format **f, char **num, t_conv *p, union u_uox value)
{
	int		size;
	int		ret_signe;
	int		i;

	size = ft_strlen(*num);
	ret_signe = return_sign_uox(p, value);
	i = (p->fl_diese == 1 && ret_signe != 0) ? 2 : 0;
	if (p->precs > size)
	{
		if ((p->fl_zero == 0 && p->fl_minus == 0)
				|| (i == 2 && p->fl_minus == 0))
			ft_s_empty(f, (*f)->pos_b, (p->width - p->precs - i), ' ');
		ft_add_0x_x(f, i, p);
		if (p->fl_zero == 1 && p->fl_minus == 0 && i == 0)
			ft_s_empty(f, (*f)->pos_b, (p->width - p->precs - i), ' ');
		ft_s_empty(f, (*f)->pos_b, (p->precs - size), '0');
		ft_strncat((*f)->buffer, *num, size);
		(*f)->pos_b = (*f)->pos_b + size;
		if (p->fl_minus == 1)
			ft_s_empty(f, (*f)->pos_b, (p->width - p->precs - i), ' ');
	}
	return (1);
}

static int	hand_x_p(t_format **f, char **num, t_conv *p, union u_uox value)
{
	int		size;
	int		ret_signe;
	int		i;

	ret_signe = return_sign_uox(p, value);
	size = (ret_signe == 0 && p->precs == 0) ? 0 : ft_strlen(*num);
	i = (p->fl_diese == 1 && ret_signe != 0) ? 2 : 0;
	if (p->precs <= size && p->precs >= 0)
	{
		if ((p->fl_minus == 0 && p->fl_zero == 0)
				|| (i == 2 && p->fl_minus == 0))
			ft_s_empty(f, (*f)->pos_b, (p->width - size - i), ' ');
		ft_add_0x_x(f, i, p);
		if (p->fl_minus == 0 && p->fl_zero == 1 && i == 0)
			ft_s_empty(f, (*f)->pos_b, (p->width - size - i), ' ');
		ft_strncat((*f)->buffer, *num, size);
		(*f)->pos_b = (*f)->pos_b + size;
		if (p->fl_minus == 1)
			ft_s_empty(f, (*f)->pos_b, (p->width - size - i), ' ');
	}
	else
		return (hand_x_paux(f, num, p, value));
	return (1);
}

static int	hand_x(t_format **f, char **num, t_conv *p, union u_uox value)
{
	int	size;
	int	i;

	if (p->precs > -1)
		return (hand_x_p(f, num, p, value));
	i = (p->fl_diese == 1 && (return_sign_uox(p, value)) != 0) ? 2 : 0;
	size = ft_strlen(*num);
	if (p->fl_zero == 0 && p->fl_minus == 0)
		ft_s_empty(f, (*f)->pos_b, (p->width - size - i), ' ');
	ft_add_0x_x(f, i, p);
	if (p->fl_zero == 1 && p->fl_minus == 0)
		ft_s_empty(f, (*f)->pos_b, (p->width - size - i), '0');
	ft_strncat((*f)->buffer, *num, size);
	(*f)->pos_b = (*f)->pos_b + size;
	if (p->width > 0 && p->width > size && p->fl_minus == 1)
		ft_s_empty(f, (*f)->pos_b, (p->width - size - i), ' ');
	return (1);
}

int			ft_handle_x(t_format **f, t_conv *p, va_list *ap)
{
	int			size;
	char		*num;
	union u_uox	value;

	if ((ft_init_union_uox(&value, p, ap) == 0)
			|| ((num = ft_itoa_union_uox(value, p)) == NULL)
			|| (size = size_value_uox(num, p, value) == 0)
			|| (ft_buffer_check(f, size) == 0)
			|| hand_x(f, &num, p, value) == 0)
		return (0);
	(*f)->pos_b = ft_strlen((*f)->buffer);
	(*f)->lst_pourc = (*f)->pos_b;
	free(num);
	return (0);
}
