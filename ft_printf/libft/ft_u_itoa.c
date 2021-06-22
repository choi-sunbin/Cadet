/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:08:51 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:08:52 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_u_getlen(long long n)
{
	int size;

	size = 0;
	if (n < 0)
		size += 1;
	if (n == 0)
		return (2);
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

char		*ft_u_itoa(long long n)
{
	int			size;
	char		*str;
	long long	cpy_n;

	cpy_n = n;
	size = ft_u_getlen(n);
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (0);
	if (cpy_n < 0)
	{
		str[0] = '-';
		cpy_n *= -1;
	}
	str[--size] = '\0';
	size--;
	if (cpy_n == 0)
		str[0] = '0';
	while (cpy_n)
	{
		str[size--] = (cpy_n % 10) + '0';
		cpy_n /= 10;
	}
	return (str);
}
