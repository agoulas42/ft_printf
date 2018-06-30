/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper_rea.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:53:16 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/25 15:05:45 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

int		ft_strtoupper_rea(char **s)
{
	int		i;
	char	*str;

	i = 0;
	if (s != NULL)
	{
		str = *s;
		*s = ft_strtoupper(str);
		free(str);
		return (1);
	}
	return (0);
}
