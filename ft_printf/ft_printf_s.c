/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:03:18 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:03:19 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_buff(char *str, int size)
{
	int		i;
	char	*buff;

	if (!(buff = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (*str && i < size)
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

static void	ft_print_ssize(t_tag *tag, char *str)
{
	if (tag->width > ft_strlen(str))
		tag->width -= ft_strlen(str);
	else
		tag->width = 0;
}

static void	ft_print_space(t_tag *tag)
{
	while (tag->width > 0)
	{
		if (tag->z_sign != EXEC)
			tag->size += ft_putchar(' ');
		else if (tag->z_sign == EXEC && tag->left != EXEC)
			tag->size += ft_putchar('0');
		tag->width--;
	}
}

static void	ft_printf_s(char *str, t_tag *tag)
{
	while (*str)
	{
		tag->size += ft_putchar(*str);
		str++;
	}
}

int			ft_print_s(t_tag *tag, char *s)
{
	char	*buff;
	int		size;

	if (s == NULL)
		s = "(null)";
	if (ft_strncmp(s, "(null)", 6) == 0 && tag->p_sign == EXEC)
		size = (tag->prec < ft_strlen(s)) ? tag->prec : ft_strlen(s);
	else if (tag->p_sign == EXEC)
		size = (tag->prec <= ft_strlen(s)) ? tag->prec : ft_strlen(s);
	else
		size = ft_strlen(s);
	if ((buff = ft_buff(s, size)) == 0)
		return (ERROR);
	ft_print_ssize(tag, buff);
	if (tag->left != EXEC)
		ft_print_space(tag);
	ft_printf_s(buff, tag);
	if (tag->left == EXEC)
		ft_print_space(tag);
	free(buff);
	return (SUCCESS);
}
