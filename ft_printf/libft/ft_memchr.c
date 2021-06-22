/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:06:23 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:06:24 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*cpy_str;
	size_t			i;
	unsigned char	cpy_c;

	cpy_c = c;
	i = 0;
	cpy_str = (unsigned char *)str;
	while (i < n)
	{
		if (cpy_str[i] == cpy_c)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
