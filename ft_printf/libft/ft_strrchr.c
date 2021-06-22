/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:08:21 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:08:22 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*cpy_str;
	unsigned char	cpy_c;
	int				i;

	cpy_str = (char *)str;
	cpy_c = c;
	i = 0;
	while (cpy_str[i])
		i++;
	while (i >= 0)
	{
		if (cpy_str[i] == cpy_c)
			return (cpy_str + i);
		i--;
	}
	return (0);
}
