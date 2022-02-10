/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:53:37 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/08 11:10:50 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_total_move(int *t, int ia, int ib)
{
	if (ib > ia)
		*t = ib;
	else
		*t = ia;
}

void	calcul_pos_e(t_data *d, int *te1, int *ia, int *ib)
{
	if (*ia > (d->l - *ia))
	{
		*ia = (d->l - *ia);
		if (*ib > (d->lb - *ib))
		{
			*ib = (d->lb - *ib);
			set_total_move(te1, *ia, *ib);
		}
		else
			*te1 = *ia + *ib;
	}
	else
	{
		if (*ib > (d->lb - *ib))
			*te1 = *ia + (d->lb - *ib);
		else
		{
			if (*ib > *ia)
				*te1 = *ib;
			else
				*te1 = *ia;
		}
	}
}

int	calcul_pos_b(t_data *d, int e1)
{
	int	index;
	int	b1;
	int	max_valb;
	int	min_valb;

	index = 0;
	if (d->b)
	{
		b1 = *(int *)d->b->content;
		min_valb = find_min_value(d->b);
		max_valb = find_max_value(d->b);
		if (e1 > max_valb)
			index = find_max(d->b);
		else if (e1 < min_valb)
			index = find_min(d->b) + 1;
		else if (e1 > b1 && e1 < max_valb)
			index = index_sup(d->b, e1) + 1;
		else if (e1 < b1 && e1 > min_valb)
			index = index_inf(d->b, e1);
	}
	return (index);
}
