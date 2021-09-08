/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:50:04 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/07/16 17:35:30 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "string.h"

void show_stack(t_list *stack)
{
	t_list		*cur;
	int			loop;

	cur = stack;
	loop = 0;
	printf("--------SHOW_STACK--------\n");
	printf("STACK SIZE = %d\n", ft_lstsize(stack));
	printf("--------------------------\n");
	while(cur->next != 0)
	{
		printf("POS = [%d], CUR = [%d]", loop, cur->data);
		if (loop == 0)
			printf(" --> HEAD\n");
		else
			printf("\n");
		cur = cur->next;
		loop++;
	}
	printf("POS = [%d], CUR = [%d]\n", loop, cur->data);
}

void ft_split_free(char** words) //libft 이관 필요
{
	int loop;

	loop = 0;
	while(words[loop] != 0)
		free(words[loop++]);
	free(words[loop]);
	free(words);
}

int ft_stack_save(t_list **stack, char** words)
{
	int		loop;
	int		loop2;
	int		data;
	
	loop = 0;
	while(words[loop] != 0)
	{
		loop2 = 0;
		while ((ft_isdigit(words[loop][loop2])) || 
				(words[loop][loop2] == ' ') ||
				(words[loop][loop2] == '+') ||
				(words[loop][loop2] == '-') )
			loop2++;
		if (words[loop][loop2] != 0)
			return -1;
		else
			data = ft_atoi(words[loop]);
		if ((data == -1) && (ft_strlen("-1") != ft_strlen(words[loop])))
			return -1;
		else if ((data == 0) && (ft_strlen("0") != ft_strlen(words[loop])))
			return -1;
		else
			ft_lstadd_back(stack, ft_lstnew(data));
		loop++;
	}
	return (1);
}

void	ft_fix_lstclear(t_list **lst)
{
	t_list	*del_lst;

	while (*lst != 0)
	{
		del_lst = *lst;
		*lst = (*lst)->next;
		free(del_lst);
	}
}

int div_s(t_list** stack_1, t_list** stack_2, int len)
{
	int half_len;
	int loop;

	half_len = len / 2;
	loop = 0;
	while(loop < half_len)
	{	
		ft_push_func(stack_2, stack_1);
		ft_rot_func(stack_2);
		loop++;
	}
}
/*
void merge_loop(t_list** stack_a, t_list** stack_b, int cut_cnt, int cur, int g_size)
{
	int a_cut;
	int b_cut;

	a_cut = cut_cnt;
	b_cut = cut_cnt;

	while ((a_cut > 0 || b_cut > 0) && g_size > cur)
	{
		//A 가져오기
		if (a_cut > 0 && (*stack_a)->next != 0)
		{
			if ((b_cut > 0) && (*stack_b)->next != 0)
			{
				if ((*stack_a)->next->data > (*stack_b)->next->data)
				{
					ft_rot_func(stack_a);
					printf("ROT\n");
					a_cut--;
				}
			}
		}
		//B 가져오기
		else if (b_cut > 0 && (*stack_b)->next != 0)
		{
			if ((a_cut > 0) && (*stack_a)->next != 0)
			{
				if ((*stack_b)->next->data > (*stack_a)->next->data)
				{
					ft_push_func(stack_b, stack_a);
					printf("PUSH_A\n");
					b_cut--;
				}
				printf("ROTB\n");
			}
		}
		//리필
		if (a_cut == 0 && b_cut == 0)
		{
			a_cut = cut_cnt;
			b_cut = cut_cnt;
		}
	}
}*/

int main(int argc, char* argv[])
{
	int loop;
	int loop2;
	t_list		*stack_a;
	t_list		*stack_b;
	char**		words;
	char*		temp;

	stack_a = ft_lstnew(0);
	stack_b = ft_lstnew(0);
	loop = 1;
	while (loop < argc)
	{
		words = ft_split(argv[loop], ' ');
		loop2 = 0;
		temp = (char*)ft_calloc(ft_strlen(argv[loop]) + 1, sizeof(char));
		ft_memmove(temp, argv[loop], ft_strlen(argv[loop]));
		words = ft_split(temp, ' ');
		while(words[loop2] != 0)
			printf("[%s]\n", words[loop2++]);
		//ft_stack_save(&stack_a, words);
		//ft_split_free(words);
		//words = ft_split(argv[loop], ' ');
		loop2 = 0;
		while(words[loop2] != 0)
			printf("WORDS[%s]\n", words[loop2++]);
		
		printf("loop[%s][%d]\n", argv[loop], ft_strlen(argv[loop]));
		loop++;
	}
	//int merge_cnt = 2;
//	while (1)
//	{
//		div_s(&stack_a, &stack_b, (ft_lstsize(stack_a) - 1));
//		merge_loop(&stack_a, &stack_b, merge_cnt);
//		if (merge_cnt <= ft_lstsize(stack_a))
//			break;
//	}

//	show_stack(stack_a);
//	show_stack(stack_b);
	ft_fix_lstclear(&stack_a);
	ft_fix_lstclear(&stack_b);
//	system("leaks a.out");
}


