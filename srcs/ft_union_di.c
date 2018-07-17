/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:16:44 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/17 13:49:01 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		specifier_di(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (1);
	return (0);
}

int		ft_init_union_di(union u_di *value, t_conv *p, va_list *ap)
{
	if (p->length == none)
		value->none = (int)(va_arg(*ap, int));
	else if (p->length == h)
		value->h = (short int)(va_arg(*ap, int));
	else if (p->length == hh)
		value->hh = (signed int)(va_arg(*ap, signed int));
	else if (p->length == l)
		value->l = (long int)(va_arg(*ap, long int));
	else if (p->length == ll)
		value->ll = (va_arg(*ap, long long int));
	else if (p->length == z)
		value->z = (va_arg(*ap, size_t));
	else if (p->length == j)
		value->j = (va_arg(*ap, intmax_t));
	else if (p->length == t)
		value->t = (ptrdiff_t)(va_arg(*ap, ptrdiff_t));
	else
		return (0);
	return (1);
}

char	*ft_itoa_union_di(union u_di value, t_conv *p)
{
	char			*s;
	intmax_t		n;

	n = -1;
	s = NULL;
	if (p->length == none)
		n = value.none;
	else if (p->length == h)
		n = value.h;
	else if (p->length == hh)
		n = value.hh;
	else if (p->length == l)
		n = value.l;
	else if (p->length == ll)
		n = value.ll;
	else if (p->length == z)
		n = value.z;
	else if (p->length == j)
		n = value.j;
	else if (p->length == t)
		n = value.t;
	else
		return (NULL);
	s = ft_itoa_base_di(n, 10);
	return (s);
}
