/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:33:22 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/25 15:32:39 by agoulas          ###   ########.fr       */
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

int			ft_buffer_check(t_format **f, int length)
{
	t_list	*tmp;
	char	*str;
	int		size;

	str = NULL;
	if ((length != -1 && (*f)->pos_b + length >= (SIZE_MAX_BUF)))
	{
		(*f)->buffer[(*f)->pos_b] = '\0';
		if ((str = ft_strdup((*f)->buffer)) == NULL)
			return (0);
		size = ft_strlen(str);
		if ((tmp = ft_lstnew(str, size)) == NULL)
			return (0);
		ft_lstadd_last((&(*f)->lst), tmp);
		(*f)->length_write = (*f)->length_write + size;
		ft_bzero((*f)->buffer, size);
		(*f)->pos_b = 0;
		(*f)->lst_pourc = 0;
		free(str);
	}
	return (1);
}

int			parsing_format(t_format **f, va_list *ap)
{
	int		c;

	c = 0;
	while ((*f)->format[(*f)->pos_f])
	{
		if ((*f)->format[(*f)->pos_f] != '%')
		{
			ft_buffer_check(f, 1);
			(*f)->buffer[(*f)->pos_b] = (*f)->format[(*f)->pos_f];
			(*f)->pos_f++;
			(*f)->pos_b++;
		}
		else
		{
			if ((c = parsing_arg(f, ap)) <= 0)
				return (c);
		}
	}
	return (1);
}
