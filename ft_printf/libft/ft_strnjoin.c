/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:08:09 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:08:10 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char const *s1, char const *s2, int n)
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	size = ft_strlen(s1) + n;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (*s1)
		str[i++] = *s1++;
	while (*s2 && n > 0)
	{
		str[i++] = *s2++;
		n--;
	}
	str[i] = '\0';
	return (str);
}
