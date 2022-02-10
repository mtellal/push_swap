/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:10:47 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/08 18:49:30 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *d, int i)
{
	t_list	*a1;

	if (!d->a)
		return ;
	a1 = d->a;
	d->a = a1->next;
	a1->next = NULL;
	ft_lstadd_back(&d->a, a1);
	if (i)
		add_move(d, "ra\n");
}

void	rb(t_data *d, int i)
{
	t_list	*b1;

	if (!d->b)
		return ;
	b1 = d->b;
	d->b = b1->next;
	b1->next = NULL;
	ft_lstadd_back(&d->b, b1);
	if (i)
		add_move(d, "rb\n");
}

void	rr(t_data *d)
{
	ra(d, 0);
	rb(d, 0);
	add_move(d, "rr\n");
}
