/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:04:30 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:04:31 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_h_getlen(long long n)
{
	int size;

	size = 0;
	if (n < 0)
		size += 1;
	if (n == 0)
		return (2);
	while (n)
	{
		n /= 16;
		size++;
	}
	return (size + 1);
}

char		*ft_hax(long long n, int op)
{
	int			size;
	char		*str;
	long long	cpy_n;
	char		ch;

	cpy_n = n;
	size = ft_h_getlen(n);
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (0);
	str[--size] = '\0';
	size--;
	if (cpy_n == 0)
		str[0] = '0';
	while (cpy_n)
	{
		if (cpy_n % 16 >= 10 && op == 1)
			ch = cpy_n % 16 + 'a' - 10;
		else if (cpy_n % 16 >= 10 && op == 2)
			ch = cpy_n % 16 + 'A' - 10;
		else
			ch = cpy_n % 16 + '0';
		str[size--] = ch;
		cpy_n /= 16;
	}
	return (str);
}
