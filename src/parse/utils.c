/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:40:08 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/10 17:47:53 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_d_range(t_list *d, int i, char **tab)
{
	t_list	*p;

	p = d;
	while (p && i > 0)
	{
		p = d->next;
		ft_lstdelone(d, free_data);
		d = p;
		i--;
	}
	if (tab)
		free_tab(tab);
}
