/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:07:29 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:03:22 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *tmp2;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp2 = f(lst);
	tmp = tmp2;
	while (lst->next != NULL && f != NULL)
	{
		tmp2->next = f(lst->next);
		tmp2 = tmp2->next;
		lst = lst->next;
	}
	return (tmp);
}
