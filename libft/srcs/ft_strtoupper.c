/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:06:54 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/25 14:56:06 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strtoupper(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if ((str = ft_strnew(ft_strlen(s))) == NULL)
		return (0);
	while (s[i])
	{
		str[i] = ft_toupper(s[i]);
		i++;
	}
	return (str);
}
