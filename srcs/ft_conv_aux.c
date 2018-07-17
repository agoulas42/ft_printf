/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:45:29 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/17 13:48:11 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_prec_aux(t_conv **p, t_format **f)
{
	int		i;
	char	buffer[4098];

	i = 0;
	if (ft_isdigit((*f)->format[(*f)->pos_f]) == 1)
	{
		while (ft_isdigit((*f)->format[(*f)->pos_f]) == 1)
		{
			buffer[i] = (*f)->format[(*f)->pos_f];
			(*f)->pos_f++;
			i++;
		}
		buffer[i] = '\0';
		(*p)->precs = ft_atoi(buffer);
	}
	else
		(*p)->precs = 0;
	return (1);
}

int			ft_find_prec(t_conv **p, t_format **f, va_list *ap)
{
	int d;

	d = 0;
	if ((*f)->format[(*f)->pos_f] != '.')
		return (0);
	(*f)->pos_f++;
	if ((*f)->format[(*f)->pos_f] == '*')
	{
		if (((*p)->precs = va_arg(*ap, int)) < 0)
			(*p)->precs = -1;
		(*f)->pos_f++;
	}
	else
		return (ft_prec_aux(p, f));
	return (1);
}

static int	ft_width_star(t_conv **p, t_format **f, va_list *ap)
{
	if ((*f)->format[(*f)->pos_f] == '*')
	{
		(*p)->width = va_arg(*ap, int);
		if ((*p)->width < 0)
		{
			(*p)->fl_minus = 1;
			(*p)->width = ft_abs((*p)->width);
		}
		(*f)->pos_f++;
		return (1);
	}
	return (0);
}

int			ft_find_width(t_conv **p, t_format **f, va_list *ap)
{
	char	buffer[2000];
	int		i;

	i = 0;
	(*p)->width = 0;
	if (ft_isdigit((*f)->format[(*f)->pos_f]) == 1)
	{
		while (ft_isdigit((*f)->format[(*f)->pos_f]) == 1)
		{
			buffer[i] = (*f)->format[(*f)->pos_f];
			(*f)->pos_f++;
			i++;
		}
		buffer[i] = '\0';
		(*p)->width = ft_atoi(buffer);
	}
	else
		return (ft_width_star(p, f, ap));
	return (1);
}
