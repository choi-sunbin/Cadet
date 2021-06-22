/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:05:51 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/12 12:05:52 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *new_next;
	t_list *curr;

	if (lst == 0 || f == 0)
		return (0);
	if (!(new = ft_lstnew(f(lst->content))))
		return (0);
	curr = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new_next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (0);
		}
		curr->next = new_next;
		curr = new_next;
		lst = lst->next;
	}
	return (new);
}
