/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:06:35 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:06:37 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	cpy_dest = dest;
	cpy_src = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*cpy_dest++ = *cpy_src++;
	return (dest);
}
