/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:33:22 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/12 13:56:20 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	parsing_arg_aux(t_format **f, va_list *ap, t_conv *p)
{
	int c;

	c = 1;
	if (p->specifier == 'c' || p->specifier == 'C')
	{
		if ((p->length == l) || p->specifier == 'C')
			c = ft_handle_lc(f, p, ap);
		else if (p->length == none)
			c = ft_handle_c(f, p, ap);
		else
			return (1);
	}
	else if (p->specifier == 's' || p->specifier == 'S')
		c = ft_handle_s(f, p, ap);
	return (c);
}

static int	parsing_arg(t_format **f, va_list *ap)
{
	t_conv	*p;
	int		c;

	p = NULL;
	c = 1;
	if (init_tconv(&p, f, ap) == 0)
		return (ft_handle_none(f, p));
	if (specifier_di(p->specifier) == 1)
		ft_handle_d_i(f, p, ap);
	else if (specifier_uox(p->specifier) == 1)
		ft_handle_uox(f, p, ap);
	else if (p->specifier == 'p')
		ft_handle_p(f, p, ap);
	else if (p->specifier == '%')
		ft_handle_pourc(f, p);
	else
		c = parsing_arg_aux(f, ap, p);
	free(p);
	return (c);
}

int			parsing_format(t_format **f, va_list *ap)
{
	int		c;

	c = 0;
	while ((*f)->format[(*f)->pos_f])
	{
		if ((*f)->format[(*f)->pos_f] != '%')
		{
			write_buffer(f, (*f)->format[(*f)->pos_f]);
			(*f)->pos_f++;
		}
		else
		{
			if ((c = parsing_arg(f, ap)) <= 0)
				return (c);
		}
	}
	return (1);
}
