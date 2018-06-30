/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:26:38 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:15:35 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>
#include <stdlib.h>

static size_t	ft_length_to_c(char const *s, size_t i, char c)
{
	size_t t;

	t = i;
	if (s == NULL)
		return (0);
	while (s[t])
	{
		if (s[t] == c)
			return (t);
		t++;
	}
	return (ft_strlen(s));
}

static size_t	ft_nbr(char const *s, char c)
{
	size_t	i;
	size_t	nb;

	nb = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			return (nb);
		if (s[i] != c)
		{
			nb++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (nb);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	index_t;
	size_t	t;

	index_t = 0;
	i = 0;
	t = 0;
	if ((tab = (char**)malloc(sizeof(char*) * ft_nbr(s, c) + 1)) == NULL)
		return (NULL);
	while ((index_t < (ft_nbr(s, c))) && (i <= ft_strlen(s)))
	{
		while (s[i] == c && s[i])
			i++;
		t = ft_length_to_c(s, i, c);
		if ((tab[index_t] = ft_strsub(s, i, (t - i))) == NULL)
			return (NULL);
		index_t++;
		i = t;
	}
	tab[index_t] = 0;
	return (tab);
}
