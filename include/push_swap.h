/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:17:55 by mtellal           #+#    #+#             */
/*   Updated: 2022/02/10 17:48:54 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft.h"

typedef struct s_index {
	int	i1;
	int	i2;
}		t_index;

typedef struct s_data {
	int		l;
	int		lb;
	char	**argv;
	t_list	*a;
	t_list	*b;
	t_list	*move;
}		t_data;

//////      MAIN    //////

void	init(t_data *d, char **argv);
int		main(int argc, char **argv);

//////  PARSE_ARGS  //////

int		len_args(char **argv);
int		only_digit(char *c);
int		*malloc_digit(int i);
void	create_tab(t_data *d, int l, char **argv);
void	parse_args(t_data *d, char **argv);

//////  PARSE_ARGS_UTILS /////

void	check_max_min_int(t_list *l, char *argv, int i, char **tab);
int		not_uniq(t_list *d);
int		len_tab(char **tab);
void	create_tab_arg(t_data *d, char **argv);
void	free_d_range(t_list *d, int i, char **tab);
void	free_tab(char **tab);

//////  UTILS_LISTS //////

int		find_value_index(t_list *d, int index);
int		up_or_down_min(t_list *d);
void	add_move(t_data *d, char *s);
int		is_sorted(t_data *d);

//////   FIND_MIN   //////
int		find_min(t_list *d);
int		find_min_range(t_list *d, int debut, int fin);
int		find_max_range(t_list *d, int debut, int fin);
int		index_inf(t_list *d, int e);
int		index_inf_range(t_list *d, int e, int debut, int fin);

//////   FIND_MAX   //////
int		find_value_index(t_list *d, int index);
int		find_max(t_list *d);
int		index_sup(t_list *d, int e);
int		index_sup_range(t_list *d, int ec, int debut, int fin);
int		find_max_value(t_list *d);

//////    ERRORS    //////

void	stop(char *msg);

//////     ALGO     //////

void	algo_2(t_data *d);
void	algo_3(t_data *d);
void	algo_short(t_data *d);
void	algo_5head(t_data *d, int len);
void	algo(t_data *d);

//////  TRY_SUB_X   //////

void	trysub700(t_data *d);
void	trysub7000(t_data *d);

///// TRY_SUB_X_UTILS /////

void	free_data(void *d);
void	free_and_set(t_data *d, int fill);

//////  UP_NPUSH_B  //////

void	up_npush_b(t_data *d);

/////  UP_NPUSH_UTILS /////

void	monte_b(t_data *d, int len);
void	descend_b(t_data *d, int len);
void	monte_all(t_data *d, int ia, int ib);
void	descend_all(t_data *d, int ia, int ib);

//////  BEST_MOVE   ///////

int		which_element(t_data *d);

//// BEST_MOVE_UTILS //////

int		calcul_pos_b(t_data *d, int e1);
void	calcul_pos_e(t_data *d, int *te1, int *ia, int *ib);
void	set_total_move(int *t, int ia, int ib);

//////  ALGO_UTILS  ///////

void	up_or_down_a(t_data *d, int index);
int		calcul_pos_a(t_data *d, int e1);
void	monte_a(t_data *d, int len);
void	descend_a(t_data *d, int len);
void	sort_a(t_data *d);

//////   FIND_MIN   //////

int		find_min_value(t_list *d);
int		find_min(t_list *d);
int		find_min_range(t_list *d, int debut, int fin);
int		index_inf(t_list *d, int e);
int		index_inf_range(t_list *d, int e, int debut, int fin);

//////   FIND_MAX   //////

int		find_max_value(t_list *d);
int		find_max(t_list *d);
int		find_max_range(t_list *d, int debut, int fin);
int		index_sup(t_list *d, int e);
int		index_sup_range(t_list *d, int ec, int debut, int fin);

//////  OPERATIONS  //////

void	sa(t_data *d, int i);
void	sb(t_data *d, int i);
void	ss(t_data *d);
void	pa(t_data *d);
void	pb(t_data *d);
void	ra(t_data *d, int i);
void	rb(t_data *d, int i);
void	rr(t_data *d);
void	rra(t_data *d, int i);
void	rrb(t_data *d, int i);
void	rrr(t_data *d);

/////  DEBUG_UTILS  //////

int		is_sorted_debug(t_data *d);
void	print_lists(t_data d);
void	print_move(t_data *d);
int		main_debug(int argc, char **argv);

#endif
