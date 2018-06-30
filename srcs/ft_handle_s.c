/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.f                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:54:42 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/29 16:38:17 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

static int		ft_hand_prec(char **s, t_format **f, t_conv *p)
{
	int		d;
	int		u;
	char	c;

	c = (p->fl_zero == 1 && p->fl_zero == 1) ? '0' : ' ';
	d = ft_strlen(*s);
	u = (p->width > p->precs && p->width > d) ? p->width : p->precs;
	d = (p->precs < d) ? p->precs : d;
	(u > d) ? ft_buffer_check(f, u) : ft_buffer_check(f, d);
	if (p->fl_minus == 1)
	{
		ft_strncat((*f)->buffer, *s, d);
		(*f)->pos_b = (*f)->pos_b + d;
		if (p->width > d)
			ft_s_empty(f, (*f)->pos_b, (p->width - d), c);
	}
	else
	{
		if (p->width > d)
			ft_s_empty(f, (*f)->pos_b, (p->width - d), c);
		ft_strncat((*f)->buffer, *s, d);
	}
	return (1);
}

static int		ft_hand_str(char **s, t_conv *p, va_list *ap)
{
	char	*s2;
	wchar_t	*s3;

	s2 = NULL;
	if (p->length == none)
	{
		if ((s2 = va_arg(*ap, char *)) == NULL)
			*s = ft_strdup("(null)");
		else
			*s = ft_strdup(s2);
		return (ft_strlen(*s));
	}
	else if (p->length == l)
	{
		if ((s3 = va_arg(*ap, wchar_t *)) == NULL)
			*s = ft_strdup("(null)");
		else if (ft_wcslen(s3) == 0)
			*s = ft_strdup("");
		else
			return (ft_strwchar(s, s3, p));
	}
	return (ft_strlen(*s));
}

int				ft_handle_s(t_format **f, t_conv *p, va_list *ap)
{
	char	*s;
	char	c;
	int		d;

	s = NULL;
	if ((d = ft_hand_str(&s, p, ap)) == -1 || ft_buffer_check(f, d) == 0)
		return (d);
	if (p->precs != -1)
		ft_hand_prec(&s, f, p);
	else if (p->width == 0)
		ft_strncat((*f)->buffer, s, d);
	else
	{
		ft_buffer_check(f, p->width);
		if (p->fl_minus == 1)
			ft_strncat((*f)->buffer, s, d);
		c = (p->fl_zero == 1 && p->fl_minus == 0) ? '0' : ' ';
		ft_s_empty(f, ft_strlen((*f)->buffer), (p->width - d), c);
		if (p->fl_minus == 0)
			ft_strncat((*f)->buffer, s, d);
	}
	(*f)->pos_b = ft_strlen((*f)->buffer);
	(*f)->lst_pourc = (*f)->pos_b;
	free(s);
	return (1);
}
