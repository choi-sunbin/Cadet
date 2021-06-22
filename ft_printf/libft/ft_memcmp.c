/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:06:29 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:06:30 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	if (n == 0 || s1 == s2)
		return (0);
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (n--)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		if (n)
		{
			c1++;
			c2++;
		}
	}
	return (0);
}
