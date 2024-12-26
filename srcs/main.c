/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:33:28 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/29 19:00:13 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	get_nodes(&a, argc, argv);
	if (is_sorted(a) != 1)
	{
		if (nodes_count(a) == 2)
			sa(&a, 1);
		else if (nodes_count(a) == 3)
			sort3(&a);
		else
			push_swap(&a, &b);
	}
	free_nodes(&a);
	return (0);
}
