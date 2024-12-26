/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:44:02 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/27 18:27:38 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_node *nodes)
{
	int	i;
	int	middle;

	i = 0;
	if (nodes == NULL)
		return ;
	middle = nodes_count(nodes) / 2;
	while (nodes)
	{
		nodes->cheapest = 0;
		nodes->position = i;
		if (i <= middle)
			nodes->middle = 0;
		else
			nodes->middle = 1;
		nodes = nodes->next;
		i++;
	}
}

void	set_target(t_node *a, t_node *b)
{
	t_node	*current;
	t_node	*target;
	int		best;

	while (b)
	{
		best = INT_MAX;
		current = a;
		while (current)
		{
			if (current->value > b->value && current->value < best)
			{
				best = current->value;
				target = current;
			}
			current = current->next;
		}
		if (best == INT_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_price(t_node *a, t_node *b)
{
	int	count_a;
	int	count_b;

	count_a = nodes_count(a);
	count_b = nodes_count(b);
	while (b)
	{
		b->price = b->position;
		if (b->middle == 1)
			b->price = count_b - b->position;
		if (b->target->middle == 0)
			b->price += b->target->position;
		else
			b->price += count_a - b->target->position;
		b = b->next;
	}
}

void	set_cheapest(t_node *b)
{
	t_node	*best;
	int		best_price;

	if (b == NULL)
		return ;
	best_price = INT_MAX;
	while (b)
	{
		if (b->price < best_price)
		{
			best_price = b->price;
			best = b;
		}
		b = b->next;
	}
	best->cheapest = 1;
}

void	nodes_init(t_node *a, t_node *b)
{
	set_position(a);
	set_position(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}
