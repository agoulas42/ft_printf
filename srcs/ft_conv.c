/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:15:06 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/25 17:09:22 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		test_specifier(t_conv **p, t_format **f)
{
	int c;

	c = (*f)->format[(*f)->pos_f];
	if (c == 'd' || c == 'i' || c == 'D'
			|| c == 'u' || c == 'U' || c == 'x' || c == 'X'
			|| c == 'o' || c == 'O' || c == 'e' || c == 'E'
			|| c == 'G' || c == 'g' || c == 'a' || c == 'A'
			|| c == 'c' || c == 'C' || c == 's' || c == 'S'
			|| c == 'p' || c == 'n' || c == '%')
	{
		(*p)->specifier = c;
		if (ft_isupper((*p)->specifier) == 1 && (*p)->specifier != 'X')
		{
			(*p)->length = l;
			(*p)->specifier = ft_tolower((*p)->specifier);
		}
		(*f)->pos_f++;
		return (1);
	}
	return (0);
}

static int		init_conv(t_conv **p)
{
	*p = NULL;
	if ((*p = (t_conv*)malloc(sizeof(t_conv))) == NULL)
		return (0);
	(*p)->fl_plus = 0;
	(*p)->fl_minus = 0;
	(*p)->fl_diese = 0;
	(*p)->fl_space = 0;
	(*p)->fl_zero = 0;
	(*p)->width = 0;
	(*p)->length = 0;
	(*p)->precs = -1;
	(*p)->specifier = '0';
	return (1);
}

int				init_tconv(t_conv **p, t_format **f, va_list *ap)
{
	int i;
	int d;

	i = -1;
	d = 1;
	if (init_conv(p) == 0)
		return (0);
	(*f)->pos_f++;
	while (d == 1)
	{
		if (test_is_flag((*f)->format, (*f)->pos_f) == 1)
			i = test_flags(f, p);
		else if (ft_isdigit((*f)->format[(*f)->pos_f]) == 1 ||
				(*f)->format[(*f)->pos_f] == '*')
			ft_find_width(p, f, ap);
		else if ((*f)->format[(*f)->pos_f] == '.')
			ft_find_prec(p, f, ap);
		else if (test_mod((*f)->format[(*f)->pos_f]) == 1)
			test_is_mod(p, f);
		else if (test_specifier(p, f) == 1)
			d = 0;
		else
			return (0);
	}
	return (1);
}
