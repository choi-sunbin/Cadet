/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:03:25 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:03:28 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sign(unsigned int n, char *s, t_tag *tag)
{
	if (tag->plus == EXEC)
	{
		if (n >= 0)
			s = ft_strnjoin("+", s, 1);
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

int			ft_print_u(t_tag *tag, unsigned int n)
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
	if ((s = ft_u_itoa(n)) == 0)
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
