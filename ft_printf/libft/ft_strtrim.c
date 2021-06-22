/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:08:29 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:08:30 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_word(char ch, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	front_ind(char const *s1, char const *set)
{
	int i;

	i = 0;
	while (s1[i] && check_word(s1[i], set))
		i++;
	return (i);
}

static int	rear_ind(char const *s1, char const *set)
{
	int size;

	size = ft_strlen(s1);
	size--;
	while (size && check_word(s1[size], set))
		size--;
	return (size);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		front;
	int		rear;

	if (s1 == NULL)
		return (0);
	if (set == NULL)
		return (ft_strdup(s1));
	front = front_ind(s1, set);
	rear = rear_ind(s1, set);
	if (rear < front)
		return (ft_strdup(""));
	if (!(dest = (char *)malloc(sizeof(char) * (rear - front + 2))))
		return (0);
	ft_strlcpy(dest, s1 + front, rear - front + 2);
	return (dest);
}
