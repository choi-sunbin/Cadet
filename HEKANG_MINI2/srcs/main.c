/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:22:47 by hekang            #+#    #+#             */
/*   Updated: 2021/08/31 17:09:57 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char		*input;
	extern char	**environ;

	init_env(environ);
	init_signal();
	init_pipefd_backup(all()->pipefd_backup);
	while (1)
	{
		dup2(all()->pipefd_backup[0], 0);
		dup2(all()->pipefd_backup[1], 1);
		input = readline("\033[1;4;34;47mHOS >\033[0m ");
		if (input)
			handle_input(input);
		else
			exit(all()->end_code);
	}
	return (0);
}
