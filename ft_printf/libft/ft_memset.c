/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:06:45 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:06:47 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*cpy_str;

	i = 0;
	cpy_str = (unsigned char *)str;
	ch = c;
	while (i++ < n)
		*cpy_str++ = c;
	return (str);
}
