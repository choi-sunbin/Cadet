/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:38:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/07/16 17:30:19 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub_str;
	size_t		str_len;

	sub_str = (char*)ft_calloc(sizeof(char), len + 1);
	if (s == 0)
		return (0);
	str_len = ft_strlen(s);
	if (str_len <= start)
		return (ft_strdup(""));
	ft_strlcpy(sub_str, s + start, len + 1);
	return (ft_strdup(sub_str));
}
