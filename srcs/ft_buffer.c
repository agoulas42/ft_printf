/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 14:57:22 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/12 14:28:45 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			write_buffer_str(t_format **f, char *s, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write_buffer(f, s[i]);
		(*f)->lst_pourc = (*f)->pos_b;
		i++;
	}
	return (1);
}

char		*ft_strsubf(char const *s, unsigned int start, size_t len)
{
	char	*tr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if ((tr = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while ((i < (len)))
	{
		tr[i] = s[start + i];
		i++;
	}
	tr[i] = '\0';
	return (tr);
}

static void	write_aux(t_format **f)
{
	char	*s;
	int		d;

	if ((d = (*f)->pos_b - (*f)->lst_pourc) > 0 && (*f)->lst_pourc != 0)
	{
		write(1, (*f)->buffer, (*f)->lst_pourc);
		if ((s = ft_strsubf((*f)->buffer, (*f)->lst_pourc, d)) != NULL)
		{
			ft_bzero((*f)->buffer, (*f)->pos_b);
			(*f)->length_write = ((*f)->length_write + (*f)->lst_pourc);
			(*f)->pos_b = 0;
			write_buffer_str(f, s, d);
			free(s);
			(*f)->lst_pourc = 0;
		}
	}
	else
	{
		write(1, (*f)->buffer, (*f)->pos_b);
		(*f)->length_write = (*f)->length_write + (*f)->pos_b;
		ft_bzero((*f)->buffer, (*f)->pos_b);
		(*f)->pos_b = 0;
		(*f)->lst_pourc = 0;
	}
}

int			write_buffer(t_format **f, char c)
{
	if ((*f)->pos_b == SIZE_MAX_BUF - 1 && SIZE_MAX_BUF == 1)
	{
		write(1, &c, 1);
		(*f)->length_write++;
	}
	else if ((*f)->pos_b < SIZE_MAX_BUF - 1)
	{
		(*f)->buffer[(*f)->pos_b] = c;
		(*f)->pos_b++;
	}
	else
	{
		write_aux(f);
		(*f)->buffer[(*f)->pos_b] = c;
		(*f)->pos_b++;
	}
	return (1);
}
