/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:58:33 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:58:36 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include "libft.h"
# include "ft_style_sheet.h"
# define TYPES 	"sScC%idDxXoOuUbpn&krfFeE"
# define FV		"-+ #0'"
# define MINUS 0
# define PLUS  1
# define SPACE 2
# define HASH  3
# define ZERO  4
# define HOOK  5

typedef enum	e_size_modificator
{
	i = 0,
	hh = 1,
	h = 2,
	ll = 3,
	l = 4,
	j = 5,
	z = 6,
	L = 7
}				t_sm;

typedef struct	s_format_qualifier
{
	char		flags[7];
	size_t		width;
	int			precision;
	t_sm		size;
	char		type;
	int			indent;
	char		*s;
	wchar_t		*p;
	size_t		l;
	intmax_t	n;
	uintmax_t	un;
	long double	fn;
	int			fd;
}				t_fq;

int				ft_printf(const char *format, ...);
void			parse_qualifier(const char *qual, t_fq *fq, va_list ap);
int				check_width(char **q_str, t_fq *fq, va_list ap);
int				check_precision(char **q_str, t_fq *fq, va_list ap);
int				check_size(char **q_str, t_fq *fq);
int				form_output(va_list ap, t_fq *fq);
char			*fill_left(char *s, size_t width, size_t *len, char c);
char			*fill_right(char *s, size_t width, size_t *len, char c);
void			form_s(t_fq *fq, va_list ap);
void			form_s_wide(t_fq *fq, va_list ap);
void			form_c(t_fq *fq, va_list ap);
void			form_c_wide(t_fq *fq, va_list ap);
void			form_elips(t_fq *fq);
void			form_i_d(t_fq *fq, va_list ap);
void			form_xoubp(t_fq *fq, va_list ap);
void			form_p(t_fq *fq, va_list ap);
int				print_date(t_fq *fq);
void			form_r(t_fq *fq, va_list ap);
void			form_f(t_fq *fq, va_list ap);
void			form_e(t_fq *fq, va_list ap);
char			*encode_symbol(int val);
void			form_issue_out(t_fq *fq, char c);
void			add_sign(t_fq *fq);
void			compute_precision(t_fq *fq);
void			compute_precision_unsigned(t_fq *fq);
void			compute_width(t_fq *fq);
void			compute_width_unsigned(t_fq *fq);
void			add_prefix(t_fq *fq);
void			compute_space(t_fq *fq);
void			compute_width_float(t_fq *fq);
void			add_sign_float(t_fq *fq);

#endif
