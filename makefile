# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agoulas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 12:06:01 by agoulas           #+#    #+#              #
#    Updated: 2018/06/29 17:23:19 by agoulas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra -w -pedantic
CFLAGS2 = -Wall -Werror -Wextra -W -pedantic
HEADER = includes
CPPFLAGS = -I $(HEADER)

DIR_S = srcs
DIR_O = build
DIR_LS = libft/src
DIR_OL = libft/build
CLIBFT = -Llibft -lft
CLIBPRT = -L. -lftprintf

SRC = ft_printf.c\
	  ft_itoa_base_printf.c\
	  ft_flags.c\
	  ft_format.c\
	  ft_parsing_f.c\
	  ft_conv.c\
	  ft_conv_aux.c\
	  ft_mod.c\
	  ft_flags_option.c\
	  ft_union_di.c\
	  ft_handle_di.c\
	  ft_test_value_mod.c\
	  ft_test_char_mod.c\
	  ft_handle_c.c\
	  ft_handle_lc.c\
	  ft_union_uoxx.c\
	  ft_return_sign_uoxx.c\
	  ft_handle_uoxx.c\
	  ft_handle_u.c\
	  ft_handle_o.c\
	  ft_handle_x.c\
	  ft_handle_pourc.c\
	  ft_handle_none.c\
	  ft_unicode.c\
	  ft_handle_p.c\
	  ft_handle_s.c\
	  ft_s_aux.c\
	  ft_strwchar.c\

SRC_L = ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_memccpy.c ft_memcmp.c ft_memdel.c ft_memset.c \
		  ft_putnbr.c ft_strcat.c ft_strclr.c ft_strcpy.c ft_strdup.c\
		  ft_striter.c ft_strjoin.c ft_strlen.c ft_strmapi.c\
		  ft_strncmp.c ft_strnequ.c ft_strrchr.c ft_strstr.c\
		  ft_strtrim.c ft_tolower.c ft_bzero.c ft_isalpha.c\
		  ft_isdigit.c ft_memalloc.c ft_memchr.c ft_memcpy.c\
		  ft_memmove.c ft_putchar.c ft_putstr.c ft_strchr.c\
		  ft_strcmp.c ft_strdel.c ft_strequ.c ft_striteri.c\
		  ft_strlcat.c ft_strmap.c ft_strncat.c ft_strncpy.c ft_strnew.c\
		  ft_strrev.c ft_strsub.c ft_toupper.c ft_strsplit.c\
		  ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_strnstr.c\
		  ft_putendl_fd.c ft_putnbr_fd.c ft_putendl.c \
		  ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
		  ft_lstmap.c ft_isupper.c ft_islower.c ft_isspace.c ft_abs.c ft_pow.c\
		  ft_is_prime.c ft_lstadd_last.c ft_lst_del_one.c ft_realloc.c\
		  ft_itoa_base.c ft_putwchar.c ft_strtolower.c ft_strtoupper.c\
		  ft_strcpy_from_to.c ft_wclen.c ft_wcslen.c ft_wctomb.c ft_wcscmp.c\
		  ft_strtolower_rea.c ft_strtoupper_rea.c\

SRCS=$(addprefix $(DIR_S)/, $(SRC))
SRCS_L=$(addprefix $(DIR_LS)/, $(SRC_l))

OBJS=$(addprefix $(DIR_O)/, $(SRC:.c=.o))
OBJS_LIB=$(addprefix $(DIR_OL)/, $(SRC_L:.c=.o))

all :$(NAME)

$(NAME) : $(DIR_O) $(OBJS) 
	@make -C libft
	@ar rc $(NAME) $(OBJS) $(OBJS_LIB)
	@ranlib $(NAME)
	@echo "[$(PURPLE)Make $(NAME) done$(RESET)]"

$(DIR_O):
	@mkdir build/

$(OBJS): $(DIR_O)/%.o: $(DIR_S)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(CPPFLAGS)

clean:
	@/bin/rm -f $(OBJS)

fclean : clean
	@/bin/rm -f $(NAME)
	@/bin/rm  -Rf build/
	@make -C libft fclean

re : fclean all

norme :
	@norminette $(SRCS) $(SRCS_L) $(HEADER)
