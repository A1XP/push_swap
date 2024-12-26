/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:16:55 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/29 15:17:10 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_nodes(t_node **a, int argc, char **argv)
{
	long	num;
	int		i;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	while (argv[i] != NULL)
	{
		if (number_error(argv[i]))
			error_free(a, argc, argv);
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			error_free(a, argc, argv);
		if (dup_error(*a, (int)num))
			error_free(a, argc, argv);
		add_node(a, num);
		i++;
	}
	if (argc == 2)
		free_argv(argv);
}

void	add_node(t_node **nodes, int num)
{
	t_node	*node;
	t_node	*last;

	if (nodes == NULL)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = num;
	node->index = -1;
	node->price = 0;
	if (*nodes == NULL)
	{
		*nodes = node;
		node->previous = NULL;
	}
	else
	{
		last = find_last(*nodes);
		last->next = node;
		node->previous = last;
	}
}
