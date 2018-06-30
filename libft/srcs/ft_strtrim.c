/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:04:21 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:16:01 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	last_caractere(char const *s, size_t min)
{
	size_t i;

	if (s == NULL)
		return (-1);
	i = ft_strlen(s);
	while (min < i && (s[i - 1] == ' ' ||
				s[i - 1] == '\n' || s[i - 1] == '\t'))
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		len;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (s[0] == '\0')
		return (ft_strnew(1));
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if ((len = last_caractere(s, i)) == (size_t)-1)
		return (NULL);
	if (i == ft_strlen(s))
		return (ft_strnew(1));
	return (ft_strsub(s, i, (len - i)));
}
