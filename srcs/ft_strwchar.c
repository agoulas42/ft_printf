/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:53:12 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/29 17:07:16 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_conv_wchar(char **buf, wchar_t c, int length)
{
	int		d;
	char	*buffer;

	if (*buf == NULL || (d = ft_wcharstrlen(c)) <= 0)
		return (-1);
	if ((buffer = ft_strnew(4)) == NULL)
		return (-1);
	if ((d = ft_wctomb(buffer, c)) == -1)
		return (-1);
	if (length > -1 && length < (d + (int)ft_strlen(*buf)))
		return (0);
	ft_strncat(*buf, buffer, d);
	free(buffer);
	return (d);
}

int			ft_wc_nbr(wchar_t *s, int nbr)
{
	size_t	d;
	size_t	i;
	size_t	size;

	size = 0;
	d = ft_wcslen(s);
	if (nbr != -1 && (size_t)nbr < d)
	{
		i = 0;
		while (s[i] && i < d)
		{
			size = size + ft_wclen(s[i]);
			i++;
		}
		return (size);
	}
	return (d);
}

static int	ft_strwchar_aux(wchar_t *s, char **res, size_t size)
{
	size_t	i;
	int		v;

	i = 0;
	while (s[i] && i < size)
	{
		if ((v = ft_conv_wchar(res, s[i], -1)) < 0)
		{
			free(*res);
			return (-1);
		}
		if (v == 0)
			break ;
		i++;
	}
	return (ft_strlen(*res));
}

int			ft_strwchar(char **res, wchar_t *s, t_conv *p)
{
	size_t		i;
	size_t		d;
	size_t		u;
	int			v;

	d = ft_wc_nbr(s, p->precs);
	u = (p->precs > -1 && p->precs < (int)d) ? p->precs : d;
	if ((*res = ft_strnew(ft_wc_nbr(s, p->precs) + 1)) == NULL)
		return (0);
	if (p->precs != -1 && p->precs <= ((int)ft_wcslen(s)))
	{
		i = 0;
		while (s[i] && i < u && ((ft_strlen(*res) + ft_wclen(s[i])) <= d))
		{
			if (((v = ft_conv_wchar(res, s[i], p->precs))) < 0)
				return (-1);
			if (v == 0)
				break ;
			i++;
		}
	}
	else
		return (ft_strwchar_aux(s, res, ft_wcslen(s)));
	return (ft_strlen(*res));
}
