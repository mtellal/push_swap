/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:38:25 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/10 09:48:02 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_2(t_data *d)
{
	if (*(int *)d->a->content > *(int *)d->a->next->content)
		sa(d, 1);
}

void	algo_3(t_data *d)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = *(int *)d->a->content;
	a2 = *(int *)d->a->next->content;
	a3 = *(int *)d->a->next->next->content;
	if (a1 > a2 && a2 > a3)
	{
		sa(d, 1);
		rra(d, 1);
	}
	else if (a1 > a2 && a2 < a3 && a1 < a3)
		sa(d, 1);
	else if (a1 > a2 && a2 < a3 && a3 < a1)
		ra(d, 1);
	else if (a1 < a2 && a3 < a1)
		rra(d, 1);
	else if (a1 < a2 && a3 < a2)
	{
		sa(d, 1);
		ra(d, 1);
	}
}

void	algo_short(t_data *d)
{
	while (d->l > 3)
		pb(d);
	algo_3(d);
	while (d->lb > 0)
	{
		calcul_pos_a(d, *(int *)d->b->content);
		pa(d);
	}
	up_or_down_a(d, find_min(d->a));
}

void	algo_5head(t_data *d, int len)
{
	while (d->l > len)
		up_npush_b(d);
	if (len != 0)
	{
		sort_a(d);
		while (d->lb > 0)
		{
			calcul_pos_a(d, *(int *)d->b->content);
			pa(d);
		}
	}
	else
	{
		while (d->lb > 0)
			pa(d);
	}
	up_or_down_a(d, find_min(d->a));
}

void	algo(t_data *d)
{
	if (d->l == 2)
		algo_2(d);
	if (d->l == 3)
		algo_3(d);
	if (d->l > 3 && d->l < 10)
		algo_short(d);
	if (d->l >= 10 && d->l < 250)
		trysub700(d);
	if (d->l >= 250)
		trysub7000(d);
}
