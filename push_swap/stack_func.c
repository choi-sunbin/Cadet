/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:48:00 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/07/05 17:52:24 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap a = a의 index 0과 index 1을 스왑 요소가 1개 또는 0개면 아무 변화 없다.
int ft_swap_func(t_list** stack)
{
	t_list*	cur_list;
	t_list* next_list;
	t_list* temp_list;

	if ((*stack)->next != 0)
	{
		cur_list = (*stack)->next;
		if(cur_list->next != 0)
		{
			next_list = cur_list->next;
			temp_list = next_list->next;
			(*stack)->next = next_list;
			next_list->next = cur_list;
			cur_list->next = temp_list;
			return (1);
		}
	}
	return (0);
}

//pa -> push a = b의 index 0 을 a의 index 0에 올림 b의 요소가 없으면 아무 변화 없음. B0 요소-> A0 이동
int	ft_push_func(t_list** stack1, t_list** stack2)
{
	t_list*	list1;
	t_list*	list2;

	list1 = (*stack1)->next;
	list2 = (*stack2)->next;
	if (list2 != 0)
	{
		(*stack2)->next= list2->next;
		(*stack1)->next = list2;
		list2->next = list1;
		return (1);
	}
	return (0);
}
//ra -> rotate a = a스택의 요소를 1개씩 위로 이동시킴 index 0은 마지막이 됩니다. 첫번째 요소를 마지막 요소 끝요소로 보내기
int ft_rot_func(t_list** stack)
{
	t_list*	cur_list;
	t_list* last_list;

	cur_list = (*stack)->next;
	last_list = ft_lstlast(*stack);
	if ((cur_list != 0) && (last_list != cur_list))
	{
		(*stack)->next = cur_list->next;
		last_list->next = cur_list;
		cur_list->next = NULL;
		return (1);
	}
	return (0);
}

//rra -> reverse rotate a = a스택의 요소를 1칸씩 아래로 이동시킴 마지막 요소는 첫번째 요소가 됩니다.
int ft_revrot_func(t_list** stack)
{
	t_list*	cur_list;
	t_list* last_list;
	t_list*	temp_list;

	cur_list = (*stack)->next;
	last_list = ft_lstlast(*stack);
	if ((cur_list != 0) && (last_list != cur_list))
	{
		(*stack)->next = last_list;
		last_list->next = cur_list;
		temp_list = cur_list;
		while(temp_list->next != last_list)
			temp_list = temp_list->next;
		temp_list->next = NULL;
		return (1);
	}
	return (0);
}
