/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:21:00 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/29 18:56:47 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*push;

	if (*src == NULL)
		return ;
	push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	push->previous = NULL;
	if (*dst == NULL)
	{
		*dst = push;
		push->next = NULL;
	}
	else
	{
		push->next = *dst;
		(*dst)->previous = push;
		*dst = push;
	}
}

void	pa(t_node **a, t_node **b, int p)
{
	push(a, b);
	if (p == 1)
		write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a, int p)
{
	push(b, a);
	if (p == 1)
		write(1, "pb\n", 3);
}
