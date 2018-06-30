/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower_rea.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:10:52 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/25 15:04:55 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

int		ft_strtolower_rea(char **s)
{
	int		i;
	char	*str;

	i = 0;
	if (s != NULL)
	{
		str = *s;
		*s = ft_strtolower(str);
		free(str);
		return (1);
	}
	return (1);
}
