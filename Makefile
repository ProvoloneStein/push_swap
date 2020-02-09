# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstein <pstein@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 16:25:48 by pstein            #+#    #+#              #
#    Updated: 2019/12/26 16:58:54 by pstein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PUSH_SWAP = push_swap

CHECKER = checker

FLAGS = -Wall -Wextra -Werror -I. -I ./libft/srcs -I ./libft/printf

LIB = -L libft/ -lft

PUSH_SWAP_SRC_DIR= src_push_swap/

CHECKER_SRC_DIR= src_checker/

HEADER= push_swap.h

CPUSH_SWAP= push_swap.c dop_alg.c dop_sorting.c free_and_errors.c make_list.c \
			make_list2.c opt_from_right.c ps_errors.c sort_three.c sorting_dop.c \
			sorting.c swap.c swap2.c valid.c 

CCHECKER= checker.c free_and_errors.c make_list.c \
		make_list2.c swap.c swap2.c valid.c viz.c 

PUSH_SWAP_SRC = $(addprefix $(PUSH_SWAP_SRC_DIR),$(CPUSH_SWAP))

CHECKER_SRC = $(addprefix $(CHECKER_SRC_DIR),$(CCHECKER))

PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:%.c=%.o)

CHECKER_OBJ = $(CHECKER_SRC:%.c=%.o)

.PHONY: all clean fclean re

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(PUSH_SWAP_OBJ) $(HEADER)
	make -C libft
	gcc $(FLAGS) $(PUSH_SWAP_OBJ) -o $(PUSH_SWAP) $(LIB)

$(PUSH_SWAP_SRC_DIR)%.o : $(PUSH_SWAP_SRC_DIR)%.c $(HEADER)
	gcc -c $(FLAGS) $< -o $@

$(CHECKER): $(CHECKER_OBJ) $(HEADER)
	make -C libft
	gcc $(FLAGS) $(CHECKER_OBJ) -o $(CHECKER) $(LIB)

$(CHECKER_SRC_DIR)%.o : $(CHECKER_SRC_DIR)%.c $(HEADER)
	gcc -c $(FLAGS) $< -o $@

clean:	
	@rm -f $(CHECKER_OBJ)
	@rm -f $(PUSH_SWAP_OBJ)
fclean: clean	
	make fclean -C libft/	
	rm -fv $(PUSH_SWAP) $(CHECKER)

re: fclean all