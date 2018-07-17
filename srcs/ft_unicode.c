/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:34:39 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/30 17:57:44 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

int			ft_wcharstrlen(wchar_t c)
{
	int	i;

	i = 0;
	if ((c <= 0x7F && MB_CUR_MAX > 1) || (c <= 0xff && MB_CUR_MAX == 1))
		i = 1;
	else if (c <= 0x7FF)
		i = 2;
	else if (c <= 0xFFFF)
		i = 3;
	else if (c <= 0x10FFFF)
		i = 4;
	if (i > MB_CUR_MAX || forbiddenwchar(c) == -1)
		return (-1);
	return (i);
}

int			forbiddenwchar(wchar_t c)
{
	if ((c >= 0x0000 && c <= 0xD7FF) || (c >= 0xE000 && c <= 0x10FFFF))
		return (1);
	return (-1);
}

int			ft_char_wchar(t_format **f, wchar_t c, int len)
{
	int		d;
	char	*s;

	s = NULL;
	d = 0;
	if (len < 0 || (s = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (-1);
	if ((d = ft_wctomb(s, c)) != -1)
		write_buffer_str(f, s, d);
	free(s);
	return (d);
}
