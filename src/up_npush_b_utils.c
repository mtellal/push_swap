/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_npush_b_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:55:11 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/08 18:12:03 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	monte_b(t_data *d, int len)
{
	while (len > 0)
	{
		rb(d, 1);
		len--;
	}
}

void	descend_b(t_data *d, int len)
{
	while (len > 0)
	{
		rrb(d, 1);
		len--;
	}
}

void	monte_all(t_data *d, int ia, int ib)
{
	int	len;

	if (ib > ia)
		len = ib;
	else
		len = ia;
	while (len > 0)
	{
		if (ia > 0 && ib > 0)
			rr(d);
		else if (ia > 0)
			ra(d, 1);
		else if (ib > 0)
			rb(d, 1);
		len--;
		ia--;
		ib--;
	}
}

void	descend_all(t_data *d, int ia, int ib)
{
	int	len;

	if (ia > ib)
		len = ia;
	else
		len = ib;
	while (len > 0)
	{
		if (ia > 0 && ib > 0)
			rrr(d);
		else if (ia > 0)
			rra(d, 1);
		else if (ib > 0)
			rrb(d, 1);
		len--;
		ia--;
		ib--;
	}
}
