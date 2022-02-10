/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_npush_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:55:47 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/08 18:20:27 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_and_down(t_data *d, int index, int i, int nb)
{
	if (nb)
	{
		monte_b(d, index);
		descend_a(d, (d->l - i));
	}
	else
	{
		descend_b(d, (d->lb - index));
		monte_a(d, i);
	}
}

void	up_npush_b(t_data *d)
{
	int	i;
	int	index;

	i = which_element(d);
	index = calcul_pos_b(d, find_value_index(d->a, i));
	if (i >= (d->l - i))
	{
		if (index >= (d->lb - index))
			descend_all(d, (d->l - i), (d->lb - index));
		else
			up_and_down(d, index, i, 1);
	}
	else
	{
		if (index >= (d->lb - index))
			up_and_down(d, index, i, 0);
		else
			monte_all(d, i, index);
	}
	pb(d);
}
