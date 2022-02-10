/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:49:01 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/08 10:49:51 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	monte_a(t_data *d, int len)
{
	while (len > 0)
	{
		ra(d, 1);
		len--;
	}
}

void	descend_a(t_data *d, int len)
{
	while (len > 0)
	{
		rra(d, 1);
		len--;
	}
}

void	up_or_down_a(t_data *d, int index)
{
	if (index > (d->l - index))
		descend_a(d, (d->l - index));
	else
		monte_a(d, index);
}

int	calcul_pos_a(t_data *d, int e1)
{
	int	index;
	int	min_vala;
	int	max_vala;
	int	imin;
	int	imax;

	index = 0;
	min_vala = find_min_value(d->a);
	max_vala = find_max_value(d->a);
	imin = find_min(d->a);
	imax = find_max(d->a);
	if (d->a)
	{
		if (e1 > max_vala)
			up_or_down_a(d, imin);
		else if (e1 < min_vala)
			up_or_down_a(d, imin);
		else if (e1 > *(int *)d->a->content && e1 < max_vala)
			index = index_sup_range(d->a, e1, 0, imax);
		else if (e1 < *(int *)d->a->content && e1 > min_vala)
			index = index_sup_range(d->a, e1, imin + 1, d->l);
		up_or_down_a(d, index);
	}
	return (index);
}

void	sort_a(t_data *d)
{
	int		mina;
	int		maxa;
	int		i;
	int		si;
	t_list	*p;

	i = 0;
	while (!is_sorted(d))
	{
		p = d->a;
		si = i;
		while (si > 0)
		{
			p = p->next;
			si--;
		}
		mina = find_max_range(p, 0, d->l - i) + i;
		up_or_down_a(d, mina);
		pb(d);
		maxa = find_min(d->a) - i;
		up_or_down_a(d, maxa);
		i++;
		pa(d);
	}
}
