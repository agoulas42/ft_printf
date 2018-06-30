/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:30:22 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/28 16:11:33 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_del_lst_all(t_list **f)
{
	if ((*f) != NULL)
	{
		if ((*f)->next != NULL)
			ft_del_lst_all(&((*f)->next));
		ft_lst_del_one((*f), (*f)->content, (*f)->content_size);
	}
	return (1);
}

static int	free_printf(int d, int c, va_list *ap, t_format **f)
{
	va_end(*ap);
	if ((*f)->lst != NULL)
		ft_del_lst_all(&((*f)->lst));
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
	ft_putstr(s);
	return (i);
}

int			print_lst_rec(t_list *l)
{
	t_list	*p;
	int		d;

	d = 0;
	p = l;
	while (p && p->content != NULL)
	{
		ft_putstr(p->content);
		d = d + ft_strlen(p->content);
		p = p->next;
	}
	return (d);
}

int			ft_printf(char const *format, ...)
{
	va_list		ap;
	t_format	*f;
	size_t		d;
	int			c;
	int			u;

	c = 0;
	u = 0;
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
			f->pos_b = (c == -1) ? f->lst_pourc : f->pos_b;
			u = print_lst_rec(f->lst);
			while (d < f->pos_b)
				ft_putchar(f->buffer[d++]);
		}
		return (free_printf(d + u, c, &ap, &f));
	}
}
