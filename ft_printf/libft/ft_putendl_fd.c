/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:07:05 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:07:06 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = ft_strlen(s);
	if (fd < 0)
		return ;
	while (i < len)
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}
