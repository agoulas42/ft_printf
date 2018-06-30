/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:12:37 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/01 17:42:04 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <wchar.h>

size_t		ft_wcslen(wchar_t *wcs)
{
	size_t len;

	len = 0;
	while (*wcs)
	{
		len += ft_wclen(*wcs);
		wcs += 1;
	}
	return (len);
}
