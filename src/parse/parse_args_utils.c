/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:32:48 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/10 17:48:04 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	check_max_min_int(t_list *d, char *argv, int i, char **tab)
{
	int		l;
	int		err;

	l = ft_strlen(argv);
	err = 0;
	if (*argv == '-' && ft_memcmp(argv + 1, "2147483648", l) > 0 && l >= 11)
		err = 1;
	if (ft_memcmp(argv, "2147483647", l) > 0 && l >= 10)
		err = 1;
	if (err)
	{
		free_d_range(d, i, tab);
		stop("Error\n");
	}
}

int	not_uniq(t_list *d)
{
	int		i;
	int		j;
	t_list	*p;
	t_list	*debut;

	i = 0;
	debut = d;
	while (d)
	{
		p = debut;
		j = 0;
		while (p)
		{
			if (*(int *)p->content == *(int *)d->content && i != j)
				return (0);
			j++;
			p = p->next;
		}
		i++;
		d = d->next;
	}
	return (1);
}

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

void	create_tab_arg(t_data *d, char **argv)
{
	int		i;
	char	**tab;

	i = 0;
	argv += 1;
	tab = ft_split(argv[0], ' ');
	d->l = len_tab(tab);
	while (i < d->l)
	{
		if (!only_digit(tab[i]))
		{
			free_d_range(d->a, i, tab);
			stop("Error\n");
		}
		check_max_min_int(d->a, tab[i], i, tab);
		ft_lstadd_back(&d->a, ft_lstnew(malloc_digit(ft_atoi(tab[i]))));
		i++;
	}
	free_tab(tab);
}
