/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:07:53 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/12 13:54:46 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_test_fldi(t_format **f, union u_di value, t_conv *p)
{
	int	ret_signe;

	ret_signe = return_sign_num(p, value);
	if (p->fl_space == 1 && ret_signe >= 0 && p->fl_plus == 0)
		write_buffer(f, ' ');
	else if (p->fl_plus == 1 || ret_signe == -1)
		(ret_signe == -1) ? write_buffer(f, '-') : write_buffer(f, '+');
	else
		return (0);
	return (1);
}

void	ft_add_0x_x(t_format **f, int i, t_conv *p)
{
	if (i == 2)
	{
		if (p->specifier == 'x')
			write_buffer_str(f, "0x", 2);
		else
			write_buffer_str(f, "0X", 2);
	}
}
