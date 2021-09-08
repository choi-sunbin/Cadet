/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:03:48 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/07/04 16:01:51 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int data)
{
	t_list	*list;

	list = ft_calloc(sizeof(t_list), 1);
	if (list == 0)
		return (0);
	list->data = data;
	list->next = 0;
	return (list);
}
