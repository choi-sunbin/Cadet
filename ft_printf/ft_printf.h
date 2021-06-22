/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:03:42 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 13:51:38 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# define ERROR -1
# define SUCCESS 1
# define FAIL 0
# define EXEC 1
# define SPEC "cspdiuxX%"
# define FLAG "-+ #0"
# define WIDTH '*'
# define PRECISION '.'

typedef struct	s_tag
{
	int	size;
	int	left;
	int	plus;
	int	space;
	int	zero;
	int z_sign;
	int	width;
	int prec;
	int p_sign;
}				t_tag;

int				ft_printf(const char *format, ...);
void			ft_flag(char **format, t_tag *tag);
void			ft_width(char **format, va_list ap, t_tag *tag);
void			ft_precision(char **format, va_list ap, t_tag *tag);

int				ft_strchr_opt(char ch, char *str);
int				ft_isnum(char **format);
int				ft_putchar(char ch);

int				ft_print_d(t_tag *tag, int n);
int				ft_print_s(t_tag *tag, char *s);
int				ft_print_c(t_tag *tag, char s);
int				ft_print_u(t_tag *tag, unsigned int n);
int				ft_print_x(t_tag *tag, unsigned int n, char op);
int				ft_print_p(t_tag *tag, unsigned long n);
int				ft_print_per(t_tag *tag);
int				ft_print_oct(t_tag *tag, unsigned int n);
void			ft_size_d(char *s, t_tag *tag, long long n);

#endif
