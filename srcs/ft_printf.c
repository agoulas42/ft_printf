/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:30:22 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/12 13:31:02 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	free_printf(int d, int c, va_list *ap, t_format **f)
{
	va_end(*ap);
	free(*f);
	*f = NULL;
	if (c == -1 || c == 0)
		return (c);
	return (d);
}

static int	ft_test_caratere(char *s, int c)
{
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		if (s[i++] == c)
			return (0);
	}
	write(1, s, i);
	return (i);
}

int			ft_printf(char const *format, ...)
{
	va_list		ap;
	t_format	*f;
	size_t		d;
	int			c;

	c = 0;
	f = NULL;
	if ((d = ft_test_caratere((char*)format, '%')) != 0)
		return (d);
	else
	{
		va_start(ap, format);
		if (init_format(format, &f) == 0)
			return (0);
		if ((c = parsing_format(&f, &ap)) != 0)
		{
			if (f->pos_b != 0)
			{
				f->pos_b = (c == -1) ? f->lst_pourc : f->pos_b;
				write(1, f->buffer, f->pos_b);
			}
		}
		return (free_printf(f->pos_b + f->length_write, c, &ap, &f));
	}
}
