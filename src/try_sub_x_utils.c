/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_sub_x_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:02:06 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/09 17:16:15 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_data(void *d)
{
	free(d);
}

/*
 * 	stack a is sorted after algo_5head so 
 * 	free stack a and list of moves, set move to null and set stack a with args 
*/

void	free_and_set(t_data *d, int fill)
{
	t_list	*p;

	p = d->a;
	while (p)
	{
		p = d->a->next;
		ft_lstdelone(d->a, free_data);
		d->a = p;
	}
	p = d->move;
	while (p)
	{
		p = d->move->next;
		ft_lstdelone(d->move, free_data);
		d->move = p;
	}
	if (fill)
	{
		d->a = 0;
		d->move = 0;
		parse_args(d, d->argv);
	}
}
