/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:04:02 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:04:03 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchr_opt(char ch, char *str)
{
	while (*str)
	{
		if (*str == ch)
			return (SUCCESS);
		str++;
	}
	return (FAIL);
}

int	ft_isnum(char **format)
{
	int		res;

	res = 0;
	while (**format >= '0' && **format <= '9')
	{
		res = res * 10 + (**format - '0');
		(*format)++;
	}
	return (res);
}

int	ft_putchar(char ch)
{
	write(1, &ch, 1);
	return (1);
}
