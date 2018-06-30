/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:33:26 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/28 16:55:12 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stddef.h>
# include "../libft/includes/libft.h"
# include <wchar.h>
# define SIZE_MAX_BUF 9999

typedef struct				s_format
{
	char					*format;
	size_t					length_write;
	size_t					length_lst;
	size_t					pos_f;
	size_t					pos_b;
	size_t					lst_pourc;
	char					buffer[SIZE_MAX_BUF];
	t_list					*lst;
	va_list					ap;
}							t_format;

enum						e_mod
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	t,
	z,
	q
};

typedef struct				s_conv
{
	int						fl_zero;
	int						fl_plus;
	int						fl_minus;
	int						fl_space;
	int						fl_diese;
	signed int				width;
	signed int				precs;
	enum e_mod				length;
	char					specifier;
}							t_conv;

union						u_di{
	int						none;
	signed char				hh;
	short int				h;
	long int				l;
	long long int			ll;
	intmax_t				j;
	ssize_t					z;
	ptrdiff_t				t;
};

union						u_uox{
	unsigned int			none;
	unsigned char			hh;
	unsigned short int		h;
	unsigned long int		l;
	unsigned long long int	ll;
	uintmax_t				j;
	size_t					z;
	ptrdiff_t				t;
};

int							ft_printf(const char *format, ...);
char						*ft_itoa_base_di(intmax_t value, int base);
int							ft_length_nbr(int n);
int							init_format(const char *str, t_format **f);
void						free_format(t_format **f);
void						printformat(t_format *f);
int							test_is_flags(const char *s, int i);
int							test_flags(t_format **f, t_conv **p);
int							test_is_flag(const char *s, int i);
int							test_mod(char c);
int							test_is_mod(t_conv **p, t_format **f);
int							ft_find_prec(t_conv **p, t_format **f, va_list *ap);
int							ft_find_width(t_conv **p, t_format **f,
		va_list *ap);
int							init_tconv(t_conv **p, t_format **f, va_list *ap);

void						char_abs_nbr(char **num, union u_di value,
		t_conv *p);
int							parsing_format(t_format **f, va_list *ap);
int							ft_fl_empty(char **s, int nbr, char c);
int							ft_fl_plus(char **s, union u_di value, t_conv *p);
int							ft_fl_diese(char **s, union u_uox value,
		t_conv *p);
char						*ft_itoa_union_di(union u_di value, t_conv *p);
char						*ft_itoa_union_uox(union u_uox value, t_conv *p);
char						*ft_itoa_base_uox(uintmax_t value, int base,
		int maj);
int							ft_init_union_di(union u_di *value, t_conv *p,
		va_list *ap);
int							size_value(char *num, t_conv *p, union u_di value);
int							size_value_uox(char *num, t_conv *p,
		union u_uox value);
int							return_sign_uox(t_conv *p, union u_uox value);
int							return_sign_num(t_conv *p, union u_di value);

int							ft_init_union_uox(union u_uox *value, t_conv *p,
		va_list *ap);
int							specifier_di(char c);
int							specifier_uox(char c);
int							ft_handle_d_i(t_format **f, t_conv *p, va_list *ap);
int							ft_handle_u(t_format **f, t_conv *p, va_list *ap);
int							ft_handle_x(t_format **f, t_conv *p, va_list *ap);
int							ft_handle_o(t_format **f, t_conv *p, va_list *ap);
int							ft_handle_c(t_format **f, t_conv *p, va_list *ap);
int							ft_handle_p(t_format **f, t_conv *p, va_list *ap);
int							ft_handle_s(t_format **f, t_conv *p, va_list *ap);
int							ft_handle_lc(t_format **f, t_conv *p, va_list *ap);
int							ft_handle_sl(t_format **f, t_conv *p, va_list *ap);
int							ft_handle_pourc(t_format **f, t_conv *p);
int							ft_handle_none(t_format **f, t_conv *p);
int							ft_handle_uox(t_format **f, t_conv *p,
		va_list *ap);
int							ft_test_fldi(t_format **f, union u_di value,
		t_conv *p);
int							ft_test_fluox(char **s, char *num,
		union u_uox value, t_conv *p);

int							ft_char_wchar(t_format **f, wchar_t c, int len);
int							ft_s_empty(t_format **f, int start, int nbr,
		char c);
int							ft_wcharstrlen(wchar_t c);
char						*ft_get_str(t_format **f, t_conv *p, va_list *ap);
int							forbiddenwchar(wchar_t c);
int							ft_conv_wchar(char **buf, wchar_t c, int lentgh);
int							ft_wc_nbr(wchar_t *s, int nbr);
int							ft_strwchar(char **res, wchar_t *s, t_conv *p);
int							ft_buffer_check(t_format **f, int length);
void						ft_add_0x_o(char **num, t_conv *p);
void						ft_add_0x_x(t_format **f, int i, t_conv *p);
#endif
