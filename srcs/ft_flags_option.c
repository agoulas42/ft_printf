/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:07:53 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/25 17:08:45 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_fl_empty(char **s, int nbr, char c)
{
	int		j;
	char	*s2;

	s2 = NULL;
	j = 0;
	if (nbr < 0 || (s2 = ft_strnew(nbr)) == NULL)
		return (0);
	while (j < nbr)
		s2[j++] = c;
	ft_strcat(*s, s2);
	free(s2);
	return (1);
}

int		ft_fl_plus(char **s, union u_di value, t_conv *p)
{
	if (return_sign_num(p, value) == -1)
		ft_strcat(*s, "-");
	else
		ft_strcat(*s, "+");
	return (1);
}

int		ft_test_fldi(t_format **f, union u_di value, t_conv *p)
{
	if (p->fl_space == 1 && return_sign_num(p, value) >= 0 && p->fl_plus == 0)
		ft_strcat((*f)->buffer, " ");
	else if (p->fl_plus == 1 || return_sign_num(p, value) == -1)
	{
		if (return_sign_num(p, value) == -1)
			ft_strcat((*f)->buffer, "-");
		else
			ft_strcat((*f)->buffer, "+");
	}
	else
		return (0);
	(*f)->pos_b++;
	return (1);
}

int		ft_test_fluox(char **s, char *num, union u_uox value, t_conv *p)
{
	int i;

	i = 0;
	if (p->fl_diese == 1 && return_sign_uox(p, value) != 0)
	{
		if (p->specifier == 'X' || p->specifier == 'x')
		{
			ft_strcat(*s, "0X");
			i = 2;
		}
		else if (p->specifier == 'o' || p->specifier == 'O')
		{
			ft_strcat(*s, "0");
			i = 1;
		}
		if (p->precs > (int)ft_strlen(num) && p->precs > 0)
			ft_fl_empty(s, (p->precs - ft_strlen(num) - i), '0');
		ft_strcat(*s, num);
	}
	return (1);
}
