/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:20:27 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/12 14:02:36 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_lst_printf(t_list *f)
{
	t_list	*p;
	int		sum;
	int		size;

	p = f;
	sum = 0;
	while (p && p->content)
	{
		size = p->content_size;
		write(1, p->content, size);
		sum = sum + size;
		p = p->next;
	}
	return (sum);
}
