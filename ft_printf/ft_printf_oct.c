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

#include "ft_printf.h"

static void	ft_print(char *s, t_tag *tag)
{
	if (*s == '+' || *s == '-')
		tag->size += ft_putchar(*s++);
	if (tag->left != EXEC)
	{
		while (tag->zero > 0)
		{
			tag->size += ft_putchar('0');
			tag->zero -= 1;
		}
	}
	while (tag->prec > 0)
	{
		tag->size += ft_putchar('0');
		tag->prec -= 1;
	}
	while (*s)
	{
		tag->size += ft_putchar(*s);
		s++;
	}
}

static void	ft_space(t_tag *tag)
{
	while (tag->width > 0)
	{
		tag->size += ft_putchar(' ');
		tag->width -= 1;
	}
}

int			ft_print_oct(t_tag *tag, unsigned int n)
{
	char	*s;

	if (tag->p_sign == EXEC && tag->prec == 0)
	{
		if (n == 0)
		{
			ft_space(tag);
			return (SUCCESS);
		}
	}
	if ((s = ft_oct(n)) == 0)
		return (ERROR);
	ft_size_d(s, tag, n);
	if (tag->left != EXEC)
		ft_space(tag);
	ft_print(s, tag);
	if (tag->left == EXEC)
		ft_space(tag);
	free(s);
	return (SUCCESS);
}
