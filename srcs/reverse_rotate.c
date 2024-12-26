/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:41:07 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/29 19:01:37 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **nodes)
{
	t_node	*last;
	int		count;

	count = nodes_count(*nodes);
	if (*nodes == NULL || nodes == NULL || count == 1)
		return ;
	last = find_last(*nodes);
	last->previous->next = NULL;
	last->next = *nodes;
	last->previous = NULL;
	*nodes = last;
	last->next->previous = last;
}

void	rra(t_node **a, int p)
{
	reverse_rotate(a);
	if (p == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int p)
{
	reverse_rotate(b);
	if (p == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, int p)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (p == 1)
		write(1, "rrr\n", 4);
}
