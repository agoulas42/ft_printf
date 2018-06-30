/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_char_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:21:00 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/04 17:06:43 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	char_abs_nbr(char **num, union u_di value, t_conv *p)
{
	char	*s;
	int		i;

	i = 0;
	if (return_sign_num(p, value) == -1)
	{
		s = *num;
		while (s[i] != '+' && s[i] != '-')
			i++;
		*num = ft_strsub(*num, (i + 1), (ft_strlen(*num) - i));
		free(s);
	}
}
