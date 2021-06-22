/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:03:47 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:03:48 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_prec_d(t_tag *tag, int size, int n)
{
	tag->prec -= size;
	tag->width = 0;
	if (tag->p_sign == EXEC)
		if (n < 0 || tag->plus == EXEC)
			tag->prec++;
}

static void	ft_width_d(t_tag *tag, int size, long long n)
{
	int p_size;

	if (n < 0 || tag->plus == EXEC)
		p_size = size - 1;
	else
		p_size = size;
	tag->width -= size;
	if (tag->p_sign == EXEC)
	{
		if (tag->prec > p_size)
			tag->prec -= p_size;
		else
			tag->prec = 0;
	}
	tag->width -= tag->prec;
	if (tag->space == EXEC && n >= 0)
		tag->width -= 1;
}

void		ft_size_d(char *s, t_tag *tag, long long n)
{
	int size;

	size = ft_strlen(s);
	if (size > tag->prec && size >= tag->width)
	{
		tag->prec = 0;
		tag->width = 0;
		return ;
	}
	else if (tag->prec >= tag->width)
		ft_prec_d(tag, size, n);
	else
		ft_width_d(tag, size, n);
	if (tag->p_sign == EXEC)
		tag->z_sign = 0;
	if (tag->z_sign == EXEC && tag->left != EXEC)
	{
		tag->zero = tag->width;
		tag->width = 0;
	}
}
