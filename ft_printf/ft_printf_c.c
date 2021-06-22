/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:14:41 by hwalee            #+#    #+#             */
/*   Updated: 2020/11/21 13:10:54 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_space(t_tag *tag)
{
	while (tag->width - 1 > 0)
	{
		tag->size += ft_putchar(' ');
		tag->width--;
	}
}

int			ft_print_c(t_tag *tag, char ch)
{
	if (tag->left != EXEC)
		ft_space(tag);
	tag->size += ft_putchar(ch);
	if (tag->left == EXEC)
		ft_space(tag);
	return (SUCCESS);
}
