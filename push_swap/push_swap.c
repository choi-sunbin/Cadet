/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:29:01 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/06/22 21:33:13 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int loop;

    loop = 0;
    while (loop < argc)
    {
        printf("LOOP =[%d] STACK[%s] \n", loop, argv[loop]);
        loop++;
    }
}