/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 17:34:13 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/26 13:53:00 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_row(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s)
	{
		if (*s && !(*s == c))
		{
			size++;
			while (*s && !(*s == c))
				s++;
		}
		if (*s && (*s == c))
			s++;
	}
	return (size);
}

static int	ft_col(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !(s[i] == c))
		i++;
	return (i);
}

void	ft_free(char **str, int n)
{
	int	i;

	i = 0;
	while (i <= n)
		free(str[i++]);
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	str = (char **)ft_calloc(sizeof(char *), (ft_row(s, c) + 1));
	if (str == NULL)
		return (0);
	while (*s)
	{
		j = 0;
		if (*s && (*s == c))
			s++;
		if (*s && !(*s == c))
		{
			str[i] = (char *)ft_calloc(sizeof(char), (ft_col(s, c) + 1));
			if (str[i] == NULL)
				ft_free(str, i - 1);
			while (*s && !(*s == c))
				str[i][j++] = *s++;
			str[i][j] = '\0';
			i++;
		}
	}
	return (str);
}
