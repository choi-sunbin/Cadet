/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:49:11 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/30 19:11:03 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		ret;

	if (argc != 5 && argc != 6)
		return (write_error(STR_ERR_ARG_CNT));
	ret = init_all(&rules, argv);
	if (ret)
		return (error_manager(ret));
	if (launcher(&rules))
		return (write_error(STR_ERR_THR_FAIL));
	return (0);
}
