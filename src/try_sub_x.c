/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_sub_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:15:52 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/10 11:29:22 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trysub_init(t_data *d, int *min_m, int *len)
{
	*len = 4;
	algo_5head(d, (d->l * 3) / 100);
	*min_m = ft_lstsize(d->move);
	if (*min_m < 700)
		*len = 21;
	else if (*min_m < 7000)
		*len = 11;
	free_and_set(d, 1);
}

void	move_sub_x(t_data *d, int *lent, int *len, int nb)
{
	free_and_set(d, 1);
	*lent = *len;
	if (nb == 700)
		*len = 21;
	else
		*len = 11;
}

void	trysub700(t_data *d)
{
	int		min_m;
	int		len;
	int		lent;

	lent = 3;
	trysub_init(d, &min_m, &len);
	while (len <= 20)
	{
		algo_5head(d, (d->l * len) / 100);
		if (min_m > ft_lstsize(d->move))
		{
			min_m = ft_lstsize(d->move);
			lent = len;
		}
		if (min_m < 700)
			move_sub_x(d, &lent, &len, 700);
		else
			free_and_set(d, 1);
		len++;
	}
	algo_5head(d, (d->l * lent) / 100);
}

void	trysub7000(t_data *d)
{
	int	min_m;
	int	len;
	int	lent;

	lent = 3;
	trysub_init(d, &min_m, &len);
	while (len <= 10)
	{
		algo_5head(d, (d->l * len) / 100);
		if (min_m > ft_lstsize(d->move))
		{
			min_m = ft_lstsize(d->move);
			lent = len;
		}
		if (min_m < 7000)
			move_sub_x(d, &lent, &len, 7000);
		else
			free_and_set(d, 1);
		len++;
	}
	algo_5head(d, (d->l * lent) / 100);
}
