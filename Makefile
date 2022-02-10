# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 15:51:33 by mtellal           #+#    #+#              #
#    Updated: 2022/02/08 18:34:25 by mtellal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap 

SRC = src/main.c src/errors.c src/algo.c src/utils_lists.c src/best_move.c src/algo_utils.c \
      src/up_npush_b.c src/try_sub_x.c src/find_min.c src/find_max.c src/debug_utils.c src/best_move_utils.c \
      src/try_sub_x_utils.c src/up_npush_b_utils.c src/parse/parse_args_utils.c \
      src/parse/parse_args.c \
      src/operations/swap.c src/operations/push.c src/operations/rotate.c src/operations/reverse.c

HEADER = -I include -I libft

LIB = -L libft -lft

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	$(GCC) $(CFLAGS) -g -o $@ -c $< $(HEADER)

$(NAME): $(OBJ)
	make -C libft
	$(GCC) $(CFLAGS) -g -o $(NAME) $(OBJ) $(HEADER) $(LIB)

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME) 

re: fclean all
