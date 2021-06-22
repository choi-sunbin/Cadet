/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:03:36 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:03:37 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_tag_init(t_tag *tag)
{
	tag->left = 0;
	tag->plus = 0;
	tag->space = 0;
	tag->zero = 0;
	tag->width = 0;
	tag->prec = 0;
	tag->p_sign = 0;
	tag->z_sign = 0;
}

static int	ft_specifier(char **format, t_tag *tag, va_list ap)
{
	int res;

	if ((res = ft_strchr_opt(**format, SPEC)) == ERROR)
		return (ERROR);
	if (**format == 'd' || **format == 'i')
		res = ft_print_d(tag, va_arg(ap, int));
	if (**format == 's')
		res = ft_print_s(tag, va_arg(ap, char *));
	if (**format == 'c')
		res = ft_print_c(tag, (char)va_arg(ap, int));
	if (**format == 'u')
		res = ft_print_u(tag, (unsigned int)va_arg(ap, int));
	if (**format == 'x' || **format == 'X')
		res = ft_print_x(tag, (unsigned int)va_arg(ap, int), **format);
	if (**format == 'o')
		res = ft_print_oct(tag, (unsigned int)va_arg(ap, int));
	if (**format == 'p')
		res = ft_print_p(tag, (unsigned long)va_arg(ap, void *));
	if (**format == '%')
		res = ft_print_per(tag);
	return (res);
}

static int	ft_format_tag(char **format, t_tag *tag, va_list ap)
{
	if (**format == '\0')
		return (ERROR);
	ft_flag(format, tag);
	if (**format == '\0')
		return (ERROR);
	ft_width(format, ap, tag);
	if (**format == '\0')
		return (ERROR);
	ft_precision(format, ap, tag);
	if (**format == '\0')
		return (ERROR);
	return (SUCCESS);
}

static int	ft_format(char *format, t_tag *tag, va_list ap)
{
	char	ch;

	if (format == NULL)
		return (ERROR);
	tag->size = 0;
	while (*format)
	{
		if (*format != '%')
			tag->size += ft_putchar(*format);
		else
		{
			format++;
			ft_tag_init(tag);
			if (ft_format_tag(&format, tag, ap) == ERROR)
				return (ERROR);
			if (ft_specifier(&format, tag, ap) == ERROR)
				return (ERROR);
		}
		format++;
	}
	return (SUCCESS);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_tag	tag;

	va_start(ap, format);
	if (ft_format((char *)format, &tag, ap) == ERROR)
		return (ERROR);
	return (tag.size);
}
