/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:06:16 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:06:17 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;
	unsigned char	cpy_c;
	size_t			i;

	cpy_dest = dest;
	cpy_src = (unsigned char *)src;
	cpy_c = c;
	i = 0;
	while (i < n)
	{
		cpy_dest[i] = cpy_src[i];
		if (cpy_src[i] == cpy_c)
			return (dest + (i + 1));
		i++;
	}
	return (0);
}
