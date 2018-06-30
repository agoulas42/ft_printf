/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:24:03 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/25 17:03:24 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		init_format(const char *str, t_format **f)
{
	if ((*f = (t_format*)malloc(sizeof(t_format))) == NULL)
		return (0);
	(*f)->format = (char*)(str);
	(*f)->lst = NULL;
	(*f)->pos_f = 0;
	(*f)->pos_b = 0;
	(*f)->lst_pourc = 0;
	(*f)->length_write = 0;
	(*f)->length_lst = 0;
	ft_bzero((*f)->buffer, SIZE_MAX_BUF);
	return (1);
}
