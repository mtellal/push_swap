/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:40:28 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/10 15:57:03 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	initialise les deux elements que l'on comparera par la suite
*/

void	init_which_element(t_data *d, t_index *e1, t_index *e2, t_index *tmin)
{
	e1->i1 = 0;
	e1->i2 = calcul_pos_b(d, find_value_index(d->a, e1->i1));
	e2->i1 = 1;
	e2->i2 = calcul_pos_b(d, find_value_index(d->a, e2->i1));
	tmin->i1 = e1->i1 + e1->i2;
	tmin->i2 = e1->i1;
}

/*	e1 = e2 et e2 = e3, pour comparer 1 a 1 chaque element dans a
 *
*/

void	reset(t_data *d, t_index *e1, t_index *e2, t_list **p)
{
	e1->i1 = e2->i1;
	e1->i2 = e2->i2;
	e2->i1 += 1;
	e2->i2 = calcul_pos_b(d, find_value_index(d->a, e2->i1));
	*p = (*p)->next;
}

/*	compare tous les elements de  a, et calcule: 
 *	(nb de coups a joue dans b) + (nb de coups a jouer dans a) 
 *	et determine quel element a le plus petit tota//
*/

int	which_element(t_data *d)
{
	t_list	*p;
	t_index	tmin;
	t_index	e1;
	t_index	e2;
	t_index	t;

	init_which_element(d, &e1, &e2, &tmin);
	p = d->a->next;
	while (d->l > 1 && p)
	{
		calcul_pos_e(d, &t.i1, &e1.i1, &e1.i2);
		calcul_pos_e(d, &t.i2, &e2.i1, &e2.i2);
		if (t.i2 < t.i1 && t.i2 < tmin.i1)
		{
			tmin.i1 = t.i2;
			tmin.i2 = e2.i1;
		}
		else if (t.i1 < t.i2 && t.i1 < tmin.i1)
		{
			tmin.i2 = e1.i1;
			tmin.i1 = t.i1;
		}
		reset(d, &e1, &e2, &p);
	}
	return (tmin.i2);
}
