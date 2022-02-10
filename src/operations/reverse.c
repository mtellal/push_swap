/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:52:59 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/08 18:47:26 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*before_last(t_list *alst)
{
	while (alst && alst->next)
	{
		if (alst->next->next == NULL)
			return (alst);
		alst = alst->next;
	}
	return (alst);
}

void	rra(t_data *d, int i)
{
	t_list	*al;
	t_list	*al2;

	if (!d->a || !d->a->next)
		return ;
	al = ft_lstlast(d->a);
	al2 = before_last(d->a);
	al2->next = NULL;
	ft_lstadd_front(&d->a, al);
	if (i)
		add_move(d, "rra\n");
}

void	rrb(t_data *d, int i)
{
	t_list	*bl;
	t_list	*bl2;

	if (!d->b || !d->b->next)
		return ;
	bl = ft_lstlast(d->b);
	bl2 = before_last(d->b);
	bl2->next = NULL;
	ft_lstadd_front(&d->b, bl);
	if (i)
		add_move(d, "rrb\n");
}

void	rrr(t_data *d)
{
	rra(d, 0);
	rrb(d, 0);
	add_move(d, "rrr\n");
}
