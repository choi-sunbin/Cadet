/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:24:13 by hwalee            #+#    #+#             */
/*   Updated: 2020/10/04 20:24:14 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t size_dest;
	size_t size_src;
	size_t i;

	i = 0;
	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (size <= size_dest)
		return (size_src + size);
	while (*dest)
		dest++;
	while (src[i] && i < (size - size_dest - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (size_dest + size_src);
}
