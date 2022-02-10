/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:13:24 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/10 16:29:12 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_data *d, char **argv)
{
	d->a = NULL;
	d->b = NULL;
	d->lb = 0;
	d->move = NULL;
	d->argv = argv;
	parse_args(d, argv);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc > 1)
	{
		argc++;
		init(&d, argv);
		if (!is_sorted(&d))
		{
			algo(&d);
			print_move(&d);
		}
		free_and_set(&d, 0);
	}
	return (0);
}
