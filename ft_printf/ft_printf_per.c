/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_per.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:03:13 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:03:15 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_space(t_tag *tag)
{
	while (tag->width - 1 > 0)
	{
		if (tag->z_sign != EXEC)
			tag->size += ft_putchar(' ');
		else if (tag->z_sign == EXEC && tag->left != EXEC)
			tag->size += ft_putchar('0');
		else if (tag->z_sign == EXEC && tag->left == EXEC)
			tag->size += ft_putchar(' ');
		tag->width--;
	}
}

int			ft_print_per(t_tag *tag)
{
	if (tag->left != EXEC)
		ft_space(tag);
	tag->size += ft_putchar('%');
	if (tag->left == EXEC)
		ft_space(tag);
	return (SUCCESS);
}
