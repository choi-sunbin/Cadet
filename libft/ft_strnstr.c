/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 23:06:07 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/01/04 01:08:27 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (*src)
	{
		if (len == 0)
			return (0);
		while (len > 0 && ft_strncmp(dest, src, src_len) != 0)
		{
			if (len <= src_len)
				return (0);
			if (*dest == 0)
				return (0);
			dest++;
			len--;
		}
	}
	return ((char*)dest);
}
