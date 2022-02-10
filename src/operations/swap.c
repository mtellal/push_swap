/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:09:07 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/08 18:50:52 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *d, int i)
{
	t_list	*s;

	if (d->l >= 2)
	{
		s = d->a->next;
		d->a->next = s->next;
		s->next = NULL;
		ft_lstadd_front(&d->a, s);
		if (i)
			add_move(d, "sa\n");
	}
}

void	sb(t_data *d, int i)
{
	t_list	*s;

	if (d->lb >= 2)
	{
		s = d->b->next;
		d->b->next = s->next;
		s->next = NULL;
		ft_lstadd_front(&d->b, s);
		if (i)
			add_move(d, "sb\n");
	}
}

void	ss(t_data *d)
{
	sa(d, 0);
	sb(d, 0);
	add_move(d, "ss\n");
}
