# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manki <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/01 17:31:36 by manki             #+#    #+#              #
#    Updated: 2019/08/20 19:48:00 by manki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

CHECKER_NAME = checker
PUSH_SWAP_NAME = push_swap

C_SRC_PATH = ./c_src
PS_SRC_PATH = ./ps_src
BOTH_SRC_PATH = ./src_both
INC_PATH = ./inc
C_OBJ_PATH = ./obj
PS_OBJ_PATH = ./obj
BOTH_OBJ_PATH = ./obj
LIB_PATH = ./libft

CHECKER_SRC_NAME = checker.c

PUSH_SWAP_SRC_NAME = push_swap.c ft_lstmax.c ft_sort_a.c ft_reverse_sort_b.c \
					 ft_check_almost_sort.c

BOTH_SRC_NAME = ft_swap.c ft_push.c ft_rotate.c ft_reverse_rotate.c \
				ft_check_arg.c ft_ps_display.c ft_apply_instruction.c \
				ft_list_is_sort.c ft_nbdiff.c

INC_NAME = push_swap.h
LIB_NAME = mylibft.a

C_OBJ_NAME = $(CHECKER_SRC_NAME:.c=.o)
PS_OBJ_NAME = $(PUSH_SWAP_SRC_NAME:.c=.o)
BOTH_OBJ_NAME = $(BOTH_SRC_NAME:.c=.o)

CHECKER_SRC = $(addprefix $(C_SRC_PATH)/, $(CHECKER_SRC_NAME))
PUSH_SWAP_SRC = $(addprefix $(PS_SRC_PATH)/, $(PUSH_SWAP_SRC_NAME))
BOTH_SRC = $(addprefix $(BOTH_SRC_PATH)/, $(BOTH_SRC_NAME))
C_OBJ = $(addprefix $(C_OBJ_PATH)/, $(C_OBJ_NAME))
PS_OBJ = $(addprefix $(PS_OBJ_PATH)/, $(PS_OBJ_NAME))
BOTH_OBJ = $(addprefix $(BOTH_OBJ_PATH)/, $(BOTH_OBJ_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))

FLAGS = -Wall -Wextra -Werror
CC = gcc

##################
##    COLORS    ##
##################

_GREY=$ \033[30m
_RED=$ \033[31m
_GREEN=$ \033[32m
_YELLOW=$ \033[33m
_BLUE=$ \033[34m
_PURPLE=$ \033[35m
_CYAN=$ \033[36m
_WHITE=$ \033[37m
_END=$ \033[0m

##################
##   TARGETS    ##
##################

.PHONY: all clean

all: $(LIB) $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(C_OBJ_PATH)/%.o: $(C_SRC_PATH)/%.c
	@mkdir $(C_OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

$(PS_OBJ_PATH)/%.o: $(PS_SRC_PATH)/%.c
	@mkdir $(PS_OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

$(BOTH_OBJ_PATH)/%.o: $(BOTH_SRC_PATH)/%.c
	@mkdir $(BOTH_OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

$(CHECKER_NAME): $(C_OBJ) $(BOTH_OBJ)
	@$(CC) $(FLAGS) $(CHECKER_SRC) $(BOTH_SRC) $(LIB) -o $(CHECKER_NAME)
	@echo "✅$(_GREEN)checker created 😎$(_END)"

$(PUSH_SWAP_NAME): $(PS_OBJ) $(BOTH_OBJ)
	@$(CC) $(FLAGS) $(PUSH_SWAP_SRC) $(BOTH_SRC) $(LIB) -o $(PUSH_SWAP_NAME)
	@echo "✅$(_GREEN)push_swap created 😎$(_END)"

$(LIB):
	@make -C libft all
	@echo "✅$(_GREEN)mylibft.a created 😎$(_END)"

clean:
	@make -C libft clean
	@/bin/rm -f $(C_OBJ) $(PS_OBJ) $(BOTH_OBJ)
	@echo "❌$(_RED) OBJECT FILES DELETED 😱$(_END)"

fclean: clean
	@make -C libft fclean
	@echo "❌$(_RED) $(LIB) DELETED 😱$(_END)"
	@/bin/rm -f $(CHECKER_NAME)
	@echo "❌$(_RED) $(CHECKER_NAME) DELETED 😱$(_END)"
	@/bin/rm -f $(PUSH_SWAP_NAME)
	@echo "❌$(_RED) $(PUSH_SWAP_NAME) DELETED 😱$(_END)"
	@/bin/rm -rf $(C_OBJ_PATH)
	@echo "❌$(_RED) $(C_OBJ_PATH) DELETED 😱$(_END)"

re: fclean all

norme:
	@norminette $(INC_PATH) $(C_SRC_PATH) $(PS_SRC_PATH) $(BOTH_SRC_PATH)
