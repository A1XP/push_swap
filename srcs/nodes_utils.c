/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:49:01 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/28 22:06:26 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last(t_node *nodes)
{
	if (nodes == NULL)
		return (NULL);
	while (nodes->next != NULL)
		nodes = nodes->next;
	return (nodes);
}

t_node	*find_smallest(t_node *nodes)
{
	long	smallest;
	t_node	*s_node;

	if (nodes == NULL)
		return (NULL);
	smallest = INT_MAX;
	while (nodes != NULL)
	{
		if (nodes->value < smallest)
		{
			smallest = nodes->value;
			s_node = nodes;
		}
		nodes = nodes->next;
	}
	return (s_node);
}

t_node	*find_biggest(t_node *nodes)
{
	long	biggest;
	t_node	*b_node;

	if (nodes == NULL)
		return (NULL);
	biggest = INT_MIN;
	while (nodes != NULL)
	{
		if (nodes->value > biggest)
		{
			biggest = nodes->value;
			b_node = nodes;
		}
		nodes = nodes->next;
	}
	return (b_node);
}

t_node	*find_cheapest(t_node *nodes)
{
	if (nodes == NULL)
		return (NULL);
	while (nodes != NULL)
	{
		if (nodes->cheapest == 1)
			return (nodes);
		nodes = nodes->next;
	}
	return (NULL);
}

int	nodes_count(t_node *nodes)
{
	int	count;

	if (nodes == NULL)
		return (0);
	count = 0;
	while (nodes != NULL)
	{
		++count;
		nodes = nodes->next;
	}
	return (count);
}
