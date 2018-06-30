/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wclen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:10:31 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/01 17:41:50 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <wchar.h>
#include <stdlib.h>

int		ft_wclen(wchar_t wc)
{
	if (wc <= (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
		return (1);
	if (wc <= 0x7ff)
		return (2);
	if (wc <= 0xffff)
		return (3);
	if (wc <= 0x10ffff)
		return (4);
	return (-1);
}
