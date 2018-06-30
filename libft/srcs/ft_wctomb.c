/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:40:21 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/18 13:44:23 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

int		ft_wctomb(char *tmp, wchar_t org)
{
	int len;

	if ((len = ft_wclen(org)) == -1 || tmp == NULL)
		return (-1);
	if (len == 1)
		tmp[0] = org;
	else if (len == 2)
	{
		tmp[0] = ((org >> 6) | 0xC0);
		tmp[1] = ((org & 0x3f) | 0x80);
	}
	else if (len == 3)
	{
		tmp[0] = ((org >> 12) | 0xE0);
		tmp[1] = (((org >> 6) & 0x3f) | 0x80);
		tmp[2] = ((org & 0x3f) | 0x80);
	}
	else if (len == 4)
	{
		tmp[0] = ((org >> 18) | 0xf0);
		tmp[1] = (((org >> 12) & 0x3f) | 0x80);
		tmp[2] = (((org >> 6) & 0x3f) | 0x80);
		tmp[3] = ((org & 0x3f) | 0x80);
	}
	return (len);
}
