/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:07:55 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:07:56 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	unsigned char	*cpy_str;
	size_t			size;

	size = 0;
	cpy_str = (unsigned char *)str;
	while (*cpy_str)
	{
		size++;
		cpy_str++;
	}
	return (size);
}
