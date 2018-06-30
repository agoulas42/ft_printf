/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:28:39 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/27 14:38:10 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_printf.h"

static void	aux(intmax_t n, int b, char *ans, int *p)
{
	static char base[] = "0123456789ABCDEF";

	if (n <= -b || b <= n)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[ft_abs(n % b)];
}

char		*ft_itoa_base_di(intmax_t value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
			|| !(ans = (char *)ft_memalloc(35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		value = value * -1;
	aux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}

static void	x_aux(uintmax_t n, int b, char *ans, int *p)
{
	static char base[] = "0123456789abcdef";

	if ((unsigned long long)b <= n)
		x_aux(n / b, b, ans, p);
	ans[(*p)++] = base[ft_abs(n % b)];
}

static void	bigx_aux(uintmax_t n, int b, char *ans, int *p)
{
	static char base[] = "0123456789ABCDEF";

	if ((unsigned long long)b <= n)
		bigx_aux(n / b, b, ans, p);
	ans[(*p)++] = base[ft_abs(n % b)];
}

char		*ft_itoa_base_uox(uintmax_t value, int base, int maj)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
			|| !(ans = (char *)ft_memalloc(35)))
		return (NULL);
	p = 0;
	if (maj == 1)
		bigx_aux(value, base, ans, &p);
	else
		x_aux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
