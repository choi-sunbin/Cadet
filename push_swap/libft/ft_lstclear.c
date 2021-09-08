/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:56:48 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/07/04 18:31:36 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*del_lst;

	while (*lst != 0 && del != 0)
	{
		del_lst = *lst;
		*lst = (*lst)->next;
		del(del_lst);
		free(del_lst);
	}
}
