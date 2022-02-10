/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:46:13 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/08 11:44:19 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_value(t_list *d)
{
	int		max;
	t_list	*p;

	p = d;
	if (!p)
		return (0);
	max = *(int *)p->content;
	p = p->next;
	while (p)
	{
		if (max < *(int *)p->content)
			max = *(int *)p->content;
		p = p->next;
	}
	return (max);
}

int	find_max(t_list *d)
{
	int		max;
	int		i;
	int		fi;
	t_list	*p;

	i = 1;
	fi = 0;
	p = d;
	max = *(int *)p->content;
	p = p->next;
	while (p)
	{
		if (max < *(int *)p->content)
		{
			max = *(int *)p->content;
			fi = i;
		}
		i++;
		p = p->next;
	}
	return (fi);
}

int	find_max_range(t_list *d, int debut, int fin)
{
	int		max;
	int		i;
	int		fi;
	t_list	*p;

	i = 1;
	fi = 0;
	p = d;
	max = *(int *)p->content;
	p = p->next;
	while (p && i < fin)
	{
		if (i >= debut && max < *(int *)p->content)
		{
			max = *(int *)p->content;
			fi = i;
		}
		i++;
		p = p->next;
	}
	return (fi);
}

int	index_sup(t_list *d, int e)
{
	t_list	*p;
	int		i;
	int		e1;
	int		e2;

	i = 0;
	p = d;
	if (!p)
		return (0);
	while (p->next)
	{
		e1 = *(int *)p->content;
		e2 = *(int *)p->next->content;
		if (e1 > e && e > e2)
			return (i);
		p = p->next;
		i++;
	}
	return (i);
}

int	index_sup_range(t_list *d, int ec, int debut, int fin)
{
	t_list	*p;
	int		i;

	i = 0;
	p = d;
	if (!p)
		return (0);
	while (p)
	{
		if (ec < *(int *)p->content && i >= debut && i <= fin)
			return (i);
		p = p->next;
		i++;
	}
	return (i);
}
