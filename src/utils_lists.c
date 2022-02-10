/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:18:05 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/08 10:38:22 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_value_index(t_list *d, int index)
{
	t_list	*p;
	int		i;

	i = 0;
	p = d;
	while (p && i <= index)
	{
		if (i == index)
			return (*(int *)p->content);
		p = p->next;
		i++;
	}
	return (0);
}

int	up_or_down_min(t_list *d)
{
	int	len;
	int	m;
	int	index;

	len = ft_lstsize(d);
	m = (int)(len / 2);
	index = find_min(d);
	if (index >= m)
		return (0);
	else
		return (1);
}

void	add_move(t_data *d, char *s)
{
	if (!d->move)
		d->move = ft_lstnew(ft_strdup(s));
	else
		ft_lstadd_back(&d->move, ft_lstnew(ft_strdup(s)));
}

int	is_sorted(t_data *d)
{
	t_list	*p;
	int		i;

	p = d->a;
	if (!d->a)
		return (0);
	i = 0;
	while (d->a && p->next)
	{
		if (*(int *)p->content > *(int *)p->next->content)
			return (0);
		p = p->next;
		i++;
	}
	return (1);
}
