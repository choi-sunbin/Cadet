/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:03:57 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:03:58 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag(char **format, t_tag *tag)
{
	int res;

	while (1)
	{
		res = ft_strchr_opt(**format, FLAG);
		if (res == FAIL)
			return ;
		if (**format == '0')
			tag->z_sign = EXEC;
		if (**format == '-')
			tag->left = EXEC;
		if (**format == '+')
			tag->plus = EXEC;
		if (**format == ' ')
			tag->space = EXEC;
		(*format)++;
		if (tag->left == EXEC)
			tag->z_sign = 0;
		if (tag->plus == EXEC)
			tag->space = 0;
	}
}

void		ft_width(char **format, va_list ap, t_tag *tag)
{
	if (**format == '*')
	{
		tag->width = va_arg(ap, int);
		if (tag->width < 0)
		{
			tag->left = EXEC;
			tag->width *= -1;
		}
		(*format)++;
	}
	else
		tag->width = ft_isnum(format);
}

static void	ft_prze(t_tag *tag)
{
	tag->prec = 0;
	tag->p_sign = EXEC;
}

void		ft_precision(char **format, va_list ap, t_tag *tag)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			tag->prec = va_arg(ap, int);
			if (tag->prec < 0)
			{
				tag->prec = 0;
				tag->p_sign = 0;
			}
			else
				tag->p_sign = EXEC;
			(*format)++;
		}
		else if (!(**format >= '0' && **format <= '9'))
			ft_prze(tag);
		else
		{
			tag->prec = ft_isnum(format);
			tag->p_sign = EXEC;
		}
	}
}
