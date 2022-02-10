/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:39:01 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/08 15:16:12 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value(t_list *d)
{
	int		min;
	t_list	*p;

	p = d;
	if (!p)
		return (0);
	min = *(int *)p->content;
	p = p->next;
	while (p)
	{
		if (min > *(int *)p->content)
			min = *(int *)p->content;
		p = p->next;
	}
	return (min);
}

int	find_min(t_list *d)
{
	int		min;
	int		i;
	int		fi;
	t_list	*p;

	i = 1;
	fi = 0;
	p = d;
	min = *(int *)p->content;
	p = p->next;
	while (p)
	{
		if (min > *(int *)p->content)
		{
			min = *(int *)p->content;
			fi = i;
		}
		i++;
		p = p->next;
	}
	return (fi);
}

int	find_min_range(t_list *d, int debut, int fin)
{
	int		min;
	int		i;
	int		fi;
	t_list	*p;

	i = 1;
	fi = 0;
	p = d;
	min = *(int *)p->content;
	p = p->next;
	while (p && i < fin)
	{
		if (i >= debut && min > *(int *)p->content)
		{
			min = *(int *)p->content;
			fi = i;
		}
		i++;
		p = p->next;
	}
	return (fi);
}

int	index_inf(t_list *d, int e)
{
	t_list	*p;
	int		i;

	i = 0;
	p = d;
	if (!p)
		return (0);
	while (p)
	{
		if (*(int *)p->content < e)
			return (i);
		p = p->next;
		i++;
	}
	return (i);
}

int	index_inf_range(t_list *d, int e, int debut, int fin)
{
	t_list	*p;
	int		i;

	i = 0;
	p = d;
	if (!p)
		return (0);
	while (p)
	{
		if (*(int *)p->content < e && i >= debut && i < fin)
			return (i + 1);
		p = p->next;
		i++;
	}
	if (i == fin)
		return (debut);
	return (i);
}
