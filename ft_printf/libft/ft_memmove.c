/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:06:40 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:06:41 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;

	if (!dest && !src)
		return (0);
	cpy_dest = dest;
	cpy_src = (unsigned char *)src;
	if (src > dest)
		while (n--)
			*cpy_dest++ = *cpy_src++;
	else
	{
		cpy_src += n;
		cpy_dest += n;
		while (n--)
			*--cpy_dest = *--cpy_src;
	}
	return (dest);
}
