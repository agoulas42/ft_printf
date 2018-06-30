/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:41:48 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/25 17:08:01 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			test_mod(char c)
{
	if (c == 'h' || c == 'l' || c == 'z' || c == 't' || c == 'q' || c == 'j')
		return (1);
	return (0);
}

static int	test_mod_aux(t_conv **p, t_format **f)
{
	enum e_mod test;

	test = none;
	if ((*f)->format[(*f)->pos_f] == 'z')
		test = z;
	else if ((*f)->format[(*f)->pos_f] == 'j')
		test = j;
	else if ((*f)->format[(*f)->pos_f] == 't')
		test = t;
	else if ((*f)->format[(*f)->pos_f] == 'q')
		test = q;
	else
		return (0);
	if ((*p)->length < test)
		(*p)->length = test;
	return (1);
}

int			test_is_mod(t_conv **p, t_format **f)
{
	enum e_mod	test;

	test = none;
	if (test_mod_aux(p, f) == 0)
	{
		if ((*f)->format[(*f)->pos_f] == 'h')
			test = ((*f)->format[(*f)->pos_f + 1] == 'h') ? hh : h;
		if ((*f)->format[(*f)->pos_f] == 'l')
			test = ((*f)->format[(*f)->pos_f + 1] == 'l') ? ll : l;
	}
	if (test == hh || test == ll)
		(*f)->pos_f++;
	if ((*p)->length <= test || (*p)->length == none)
		(*p)->length = test;
	(*f)->pos_f++;
	return (1);
}
