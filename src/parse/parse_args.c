/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:33:16 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/10 17:49:57 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_args(char **argv)
{
	int	i;

	if (!(argv + 1))
		return (0);
	i = 1;
	while (argv && argv[i])
		i++;
	if (i == 1)
		stop("Error\n");
	return (i);
}

int	only_digit(char *c)
{
	int	i;

	i = 0;
	while (c[i] == '-' || c[i] == '+')
		i++;
	if (i >= 2)
		return (0);
	while (c && c[i])
	{
		if (!ft_isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*malloc_digit(int i)
{
	int	*n;

	n = (int *)malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = i;
	return (n);
}

void	create_tab(t_data *d, int l, char **argv)
{
	int	i;

	i = 0;
	argv += 1;
	while (i < l)
	{
		if (!only_digit(argv[i]))
		{
			free_d_range(d->a, i, 0);
			stop("Error\n");
		}
		check_max_min_int(d->a, argv[i], i, 0);
		ft_lstadd_back(&d->a, ft_lstnew(malloc_digit(ft_atoi(argv[i]))));
		i++;
	}
}

void	parse_args(t_data *d, char **argv)
{
	d->l = len_args(argv) - 1;
	if (d->l == 1)
		create_tab_arg(d, argv);
	else
		create_tab(d, d->l, argv);
	if (!not_uniq(d->a))
	{
		free_and_set(d, 0);
		stop("Error\n");
	}
}
