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

static char	*ft_sign(int n, char *s, t_tag *tag)
{
	if (tag->plus == EXEC)
	{
		if (n >= 0)
			s = ft_strjoin("+", s);
	}
	else
	{
		if (tag->space == EXEC && n >= 0)
			tag->size += ft_putchar(' ');
	}
	return (s);
}

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

static void	ft_pfzero(t_tag *tag)
{
	if (tag->plus == EXEC || tag->space == EXEC)
		tag->width--;
	if (tag->left != EXEC)
		ft_space(tag);
	if (tag->plus == EXEC)
		tag->size += ft_putchar('+');
	else if (tag->space == EXEC)
		tag->size += ft_putchar(' ');
	if (tag->left == EXEC)
		ft_space(tag);
}

int			ft_print_d(t_tag *tag, int n)
{
	char	*s;

	if (tag->p_sign == EXEC && tag->prec == 0 && n == 0)
	{
		ft_pfzero(tag);
		return (SUCCESS);
	}
	if ((s = ft_itoa(n)) == 0)
		return (ERROR);
	s = ft_sign(n, s, tag);
	ft_size_d(s, tag, n);
	if (tag->left != EXEC)
		ft_space(tag);
	ft_print(s, tag);
	if (tag->left == EXEC)
		ft_space(tag);
	free(s);
	return (SUCCESS);
}
