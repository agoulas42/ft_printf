/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_sign_uoxx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:12:08 by agoulas           #+#    #+#             */
/*   Updated: 2018/05/29 17:27:32 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	return_num_nonet(t_conv *p, union u_uox value)
{
	if (p->length == none)
	{
		if (value.none > 0)
			return (1);
		return (0);
	}
	else if (p->length == t)
	{
		if (value.t > 0)
			return (1);
		return (0);
	}
	else
		return (-2);
}

static int	return_num_lll(t_conv *p, union u_uox value)
{
	if (p->length == ll)
	{
		if (value.ll > 0)
			return (1);
		return (0);
	}
	else if (p->length == l)
	{
		if (value.l > 0)
			return (1);
		return (0);
	}
	else
		return (-2);
}

static int	return_num_jz(t_conv *p, union u_uox value)
{
	if (p->length == j)
	{
		if (value.j > 0)
			return (1);
		return (0);
	}
	else if (p->length == z)
	{
		if (value.z == 0)
			return (0);
		return (1);
	}
	else
		return (-2);
}

static int	return_num_hhh(t_conv *p, union u_uox value)
{
	if (p->length == hh)
	{
		if (value.hh > 0)
			return (1);
		return (0);
	}
	else if (p->length == h)
	{
		if (value.h > 0)
			return (1);
		return (0);
	}
	else
		return (-2);
}

int			return_sign_uox(t_conv *p, union u_uox value)
{
	enum e_mod test;

	test = p->length;
	if (test == j || test == z)
		return (return_num_jz(p, value));
	else if (test == hh || test == h)
		return (return_num_hhh(p, value));
	else if (test == ll || test == l)
		return (return_num_lll(p, value));
	else
		return (return_num_nonet(p, value));
}
