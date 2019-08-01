# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manki <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 14:37:29 by manki             #+#    #+#              #
#    Updated: 2019/08/01 19:13:54 by manki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

							#################
							#	VARIABLES	#
							#################

NAME = mylibft.a

SRC_PATH = ./src
LIB_PATH = ./lib
LIBFT_PATH = ./libft/
INC_PATH = ./inc
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj
OBJLIBFT_PATH = ./obj

SRC_NAME = ft_printf.c ft_analysis.c ft_basics.c ft_putdot.c \
		   ft_fill_di_output.c ft_fill_uoxx_output.c ft_float3.c \
		   ft_fill_c_output.c ft_fill_s_output.c ft_option.c ft_list.c \
		   ft_fill_p_output.c ft_utils_f.c ft_strmul.c ft_get_fvalue.c \
		   ft_floats.c ft_afficher.c ft_round.c ft_bitwise.c ft_stradd.c \
		   ft_strdiv.c

LIB_NAME = ft_atoi.c ft_isdigit.c ft_lltoa.c ft_lltoa_base.c ft_ulltoa.c \
		   ft_ulltoa_base.c ft_memcpy.c ft_memset.c ft_putchar.c \
		   ft_putstr.c ft_strchr.c ft_strcmp.c ft_strdel.c \
		   ft_strlen.c ft_strncpy.c ft_strcat.c \
		   ft_ctob.c ft_realloc.c ft_memalloc.c ft_lstdel.c \
		   ft_memdel.c ft_max.c ft_dbl_len.c ft_strncat.c

LIBFT_NAME = ft_abs.c ft_memcmp.c ft_striter.c ft_bzero.c ft_memmove.c \
			 ft_striteri.c ft_isalnum.c ft_print_words_tables.c ft_strjoin.c \
			 ft_isalpha.c ft_putchar_fd.c ft_strlcat.c ft_isascii.c \
			 ft_putendl.c ft_strlcpy.c ft_isblank.c ft_putendl_fd.c \
			 ft_strlowcase.c ft_iscntrl.c ft_putnbr.c ft_strmap.c \
			 ft_isgraph.c ft_putnbr_base.c ft_strmapi.c ft_islower.c \
			 ft_putnbr_fd.c ft_strncasecmp.c ft_isprime.c ft_putstr_fd.c \
			 ft_strncmp.c ft_isprint.c ft_sort_integer_table.c ft_strndup.c \
			 ft_isspace.c ft_sort_wordtab.c ft_strnequ.c ft_isupper.c \
			 ft_sqrt.c ft_strnew.c ft_isxdigit.c ft_str_is_alpha.c \
			 ft_strnstr.c ft_itoa.c ft_str_is_lowercase.c ft_strrchr.c \
			 ft_list_push_back.c ft_str_is_numeric.c ft_strrev.c \
			 ft_list_push_front.c ft_str_is_printable.c ft_strsplit.c \
			 ft_str_is_uppercase.c ft_strstr.c \
			 ft_strcapitalize.c ft_strsub.c ft_lstiter.c ft_strcasecmp.c \
			 ft_strtrim.c ft_strcasestr.c ft_strupcase.c \
			 ft_lstmap.c ft_strclr.c ft_tolower.c ft_strcpy.c \
			 ft_toupper.c ft_memccpy.c ft_strdup.c get_next_line.c \
			 ft_memchr.c ft_strequ.c

INC_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJLIB_NAME = $(LIB_NAME:.c=.o)

OBJLIBFT_NAME = $(LIBFT_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
LIBFT = $(addprefix $(LIBFT_PATH)/,$(LIBFT_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))
OBJLIBFT = $(addprefix $(OBJLIBFT_PATH)/,$(OBJLIBFT_NAME))

FLAGS = -Wall -Wextra -Werror
CC = gcc

							#############
							#	COLORS	#
							#############

_GREY=			$ \033[30m
_RED=			$ \033[31m
_GREEN=			$ \033[32m
_YELLOW=		$ \033[33m
_BLUE=			$ \033[34m
_PURPLE=		$ \033[35m
_CYAN=			$ \033[36m
_WHITE=			$ \033[37m
_END=			$ \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
		@mkdir $(OBJLIB_PATH) 2> /dev/null || true
		@$(CC) $(FLAGS) -o $@ -c $<

$(OBJLIBFT_PATH)/%.o: $(LIBFT_PATH)/%.c
		@mkdir $(OBJLIBFT_PATH) 2> /dev/null || true
		@$(CC) $(FLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ) $(OBJLIB) $(OBJLIBFT)
		@ar rc $(NAME) $(OBJ) $(OBJLIB) $(OBJLIBFT)
		@ranlib $(NAME)

clean:
		@/bin/rm -f $(OBJ) $(OBJLIB)

fclean: clean
		@/bin/rm -rf $(OBJ_PATH)
		@/bin/rm -f $(NAME)

re: fclean all

norme:
		norminette $(SRC) $(LIB) $(INC)
