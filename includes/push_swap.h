/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:35:05 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/29 18:59:53 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				position;
	int				middle;
	int				cheapest;
	int				price;
	struct s_node	*next;
	struct s_node	*previous;
	struct s_node	*target;
}		t_node;

// nodes_add.c
void		get_nodes(t_node **a, int argc, char **argv);
void		add_node(t_node **nodes, int num);

// index.c
int			index_stack(t_node **stack);

//	nodes_init.c
void		set_position(t_node *nodes);
void		set_target(t_node *a, t_node *b);
void		set_price(t_node *a, t_node *b);
void		set_cheapest(t_node *b);
void		nodes_init(t_node *a, t_node *b);

// nodes_utils.c
t_node		*find_last(t_node *nodes);
void		add_node(t_node **nodes, int num);
t_node		*find_smallest(t_node *nodes);
t_node		*find_biggest(t_node *nodes);
t_node		*find_cheapest(t_node *nodes);
int			nodes_count(t_node *nodes);

// check_errors.c
int			dup_error(t_node *a, int num);
int			number_error(char *str);
void		free_argv(char **argv);
void		free_nodes(t_node **nodes);
void		error_free(t_node **a, int argc, char **argv);

// sort_utils.c
int			is_sorted(t_node *nodes);
void		rotate_both(t_node **a, t_node **b, t_node *cheapest);
void		reverse_rotate_both(t_node **a, t_node **b, t_node *cheapest);
void		finish_rotation(t_node **nodes, t_node *top, char stack_name);

// push_swap.c
void		push_swap(t_node **a, t_node **b);
void		sort3(t_node **a);

// push.c swap.c rotate.c reverse_rotate.c
void		pa(t_node **a, t_node **b, int p);
void		pb(t_node **b, t_node **a, int p);
void		sa(t_node **a, int p);
void		sb(t_node **b, int p);
void		ss(t_node **a, t_node **b, int p);
void		ra(t_node **a, int p);
void		rb(t_node **b, int p);
void		rr(t_node **a, t_node **b, int p);
void		rra(t_node **a, int p);
void		rrb(t_node **b, int p);
void		rrr(t_node **a, t_node **b, int p);

#endif