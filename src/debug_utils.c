/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:04:48 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/08 11:35:23 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return -1 if stack is sorted else return the index of non sorted numbers
*/

int	is_sorted_debug(t_data *d)
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
			return (i);
		p = p->next;
		i++;
	}
	return (-1);
}

// norme solution as UsUaL

void	print_lists_init(t_data *d, int *j, int *l, t_list **pa)
{
	*j = 0;
	if (d->l > d->lb)
		*l = d->l;
	else
		*l = d->lb;
	printf(" stack b         stack a\n");
	*pa = d->a;
}

//print stacks in the terminal

void	print_lists(t_data d)
{
	int		j;
	t_list	*pa;
	t_list	*pb;
	int		l;

	print_lists_init(&d, &j, &l, &pa);
	pb = d.b;
	while (j < l)
	{
		if (j < d.lb)
		{
			printf(" %i             ",*(int *)pb->content);
			pb = pb->next;
		}
		else
			printf("                ");
		if (j < d.l)
		{
			printf(" %i \n", *(int *)pa->content);
			pa = pa->next;
		}
		else
			printf("\n");
		j++;
	}
}

/*
 *	*print list of all moves (ra, sa, pa etc...), 
 *	u can check the number of instructions with ft_lstsize (see main)
 */

void	print_move(t_data *d)
{
	int		l;
	int		i;
	t_list	*p;

	i = 0;
	p = d->move;
	l = ft_lstsize(d->move);
	while (i < l)
	{
		ft_putstr_fd(p->content, 1);
		p = p->next;
		i++;
	}
}

/*
 * exemple of debugging stacks in the main, 
 * you can use print_move to see the list of moves
*/

int	main_debug(int argc, char **argv)
{
	t_data	d;

	argc++;
	init(&d, argv);
	algo(&d);
	print_lists(d);
	if (is_sorted_debug(&d) == -1)
		printf("//////////////// trie ////////////\n");
	else
		printf("!!!! non trie  index %i !!!!\n", is_sorted(&d));
	printf("\n %i \n", ft_lstsize(d.move));
	return (0);
}
