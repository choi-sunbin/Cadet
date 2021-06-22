/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:03:08 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:03:10 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(char *s, t_tag *tag, unsigned long n)
{
	tag->size += ft_putchar('0');
	tag->size += ft_putchar('x');
	if (tag->p_sign == EXEC)
		while (tag->prec > 0)
		{
			tag->size += ft_putchar('0');
			tag->prec--;
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

static void	ft_size_p(char *s, t_tag *tag, unsigned long n)
{
	if (tag->width > (ft_strlen(s) + 2))
		tag->width -= (ft_strlen(s) + 2);
	else
		tag->width = 0;
	if (tag->p_sign == EXEC)
	{
		if (tag->prec > ft_strlen(s))
			tag->prec -= ft_strlen(s);
		else
			tag->prec = 0;
		tag->width -= tag->prec;
	}
}

int			ft_print_p(t_tag *tag, unsigned long n)
{
	char	*s;
	char	*buff;

	if ((s = ft_hax(n, 1)) == 0)
		return (ERROR);
	if ((void *)n == NULL)
	{
		free(s);
		if (tag->prec == 0 && tag->p_sign == EXEC)
			s = ft_strdup("");
		else
			s = ft_strdup("0");
	}
	ft_size_p(s, tag, n);
	if (tag->left != EXEC)
		ft_space(tag);
	ft_print(s, tag, n);
	if (tag->left == EXEC)
		ft_space(tag);
	free(s);
	return (SUCCESS);
}
