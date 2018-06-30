/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:22:17 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/25 17:08:19 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		test_is_flag(const char *s, int i)
{
	if (s[i] == ' ' || s[i] == '+' || s[i] == '-' || s[i] == '0'
			|| s[i] == '#')
		return (1);
	return (0);
}

int		test_flags(t_format **f, t_conv **p)
{
	int i;

	i = 1;
	while (test_is_flag((*f)->format, (*f)->pos_f) == 1)
	{
		if ((*f)->format[(*f)->pos_f] == ' ')
			(*p)->fl_space = 1;
		if ((*f)->format[(*f)->pos_f] == '+')
			(*p)->fl_plus = 1;
		else if ((*f)->format[(*f)->pos_f] == '-')
			(*p)->fl_minus = 1;
		else if ((*f)->format[(*f)->pos_f] == '#')
			(*p)->fl_diese = 1;
		else if ((*f)->format[(*f)->pos_f] == '0')
			(*p)->fl_zero = 1;
		(*f)->pos_f++;
	}
	return (i);
}
