/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:31:16 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/08 18:45:54 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *d)
{
	t_list	*b1;
	t_list	*b2;

	b1 = d->b;
	if (!d->b)
		return ;
	b2 = d->b->next;
	b1->next = d->a;
	d->a = b1;
	d->b = b2;
	d->lb -= 1;
	d->l += 1;
	add_move(d, "pa\n");
}

void	pb(t_data *d)
{
	t_list	*a1;
	t_list	*a2;
	t_list	*b1;

	a1 = d->a;
	if (!d->a)
		return ;
	a2 = d->a->next;
	b1 = d->b;
	if (!d->b)
	{	
		d->b = a1;
		a1->next = NULL;
	}
	else
	{
		a1->next = b1;
		d->b = a1;
	}
	d->a = a2;
	d->l -= 1;
	d->lb += 1;
	add_move(d, "pb\n");
}
