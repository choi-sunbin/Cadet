/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 12:42:38 by hwalee            #+#    #+#             */
/*   Updated: 2020/10/06 20:46:26 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	cpy_c;

	cpy_c = c;
	if (*str == cpy_c)
		return ((char *)str);
	while (*str++ != '\0')
	{
		if (*str == cpy_c)
			return ((char *)str);
	}
	return (0);
}
