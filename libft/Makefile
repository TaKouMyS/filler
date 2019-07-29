# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 20:19:54 by amamy             #+#    #+#              #
#    Updated: 2019/07/29 15:26:30 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SHELL = /bin/sh
CC = clang
CFLAGS += -Wall -Werror -Wextra -g
OBJDIR = obj
FT_IS_DIR = is
FT_LST_DIR = lst
FT_MEM_DIR = mem
FT_MISC_DIR = misc
FT_PUT_DIR = put
FT_STR_DIR = str
INCLUDES = includes
HEAD = $(INCLUDES)/libft.h

SRCS =	$(FT_IS_DIR)/ft_isalnum.c			\
		$(FT_IS_DIR)/ft_isalpha.c			\
		$(FT_IS_DIR)/ft_isascii.c			\
		$(FT_IS_DIR)/ft_isdigit.c			\
		$(FT_IS_DIR)/ft_isprint.c			\
		$(FT_LST_DIR)/ft_lstadd.c			\
		$(FT_LST_DIR)/ft_lstdel.c			\
		$(FT_LST_DIR)/ft_lstdelone.c		\
		$(FT_LST_DIR)/ft_lstendadd.c		\
		$(FT_LST_DIR)/ft_lstiter.c			\
		$(FT_LST_DIR)/ft_lstmap.c			\
		$(FT_LST_DIR)/ft_lstnew.c			\
		$(FT_MEM_DIR)/ft_memalloc.c			\
		$(FT_MEM_DIR)/ft_memccpy.c			\
		$(FT_MEM_DIR)/ft_memchr.c			\
		$(FT_MEM_DIR)/ft_memdel.c			\
		$(FT_MEM_DIR)/ft_memcmp.c			\
		$(FT_MEM_DIR)/ft_memcpy.c			\
		$(FT_MEM_DIR)/ft_memmove.c			\
		$(FT_MEM_DIR)/ft_memset.c 			\
		$(FT_MISC_DIR)/ft_atoi.c			\
		$(FT_MISC_DIR)/ft_bzero.c			\
		$(FT_MISC_DIR)/ft_disp_ar.c			\
		$(FT_MISC_DIR)/ft_itoa_base.c		\
		$(FT_MISC_DIR)/ft_itoa.c			\
		$(FT_MISC_DIR)/ft_nb_len_base.c		\
		$(FT_MISC_DIR)/ft_nb_words.c		\
		$(FT_MISC_DIR)/ft_no_space.c		\
		$(FT_MISC_DIR)/ft_print_list.c		\
		$(FT_MISC_DIR)/ft_tolower.c			\
		$(FT_MISC_DIR)/ft_toupper.c			\
		$(FT_MISC_DIR)/get_next_line.c		\
		$(FT_PUT_DIR)/ft_putchar_fd.c		\
		$(FT_PUT_DIR)/ft_putchar.c			\
		$(FT_PUT_DIR)/ft_putendl_fd.c		\
		$(FT_PUT_DIR)/ft_putendl.c			\
		$(FT_PUT_DIR)/ft_putnbr_fd.c		\
		$(FT_PUT_DIR)/ft_putnbr.c			\
		$(FT_PUT_DIR)/ft_putstr_fd.c		\
		$(FT_PUT_DIR)/ft_putstr.c			\
		$(FT_STR_DIR)/ft_strcat.c			\
		$(FT_STR_DIR)/ft_strchr.c			\
		$(FT_STR_DIR)/ft_strclr.c			\
		$(FT_STR_DIR)/ft_strcmp.c			\
		$(FT_STR_DIR)/ft_strcpy.c			\
		$(FT_STR_DIR)/ft_strdel.c			\
		$(FT_STR_DIR)/ft_strdup.c			\
		$(FT_STR_DIR)/ft_strequ.c			\
		$(FT_STR_DIR)/ft_striter.c			\
		$(FT_STR_DIR)/ft_striteri.c			\
		$(FT_STR_DIR)/ft_strjoin.c			\
		$(FT_STR_DIR)/ft_strlcat.c			\
		$(FT_STR_DIR)/ft_strlen.c			\
		$(FT_STR_DIR)/ft_strmap.c			\
		$(FT_STR_DIR)/ft_strmapi.c			\
		$(FT_STR_DIR)/ft_strncat.c			\
		$(FT_STR_DIR)/ft_strncmp.c			\
		$(FT_STR_DIR)/ft_strncpy.c			\
		$(FT_STR_DIR)/ft_strndup.c			\
		$(FT_STR_DIR)/ft_strnequ.c			\
		$(FT_STR_DIR)/ft_strnew.c			\
		$(FT_STR_DIR)/ft_strnstr.c			\
		$(FT_STR_DIR)/ft_strrchr.c			\
		$(FT_STR_DIR)/ft_strrealloc.c		\
		$(FT_STR_DIR)/ft_strsplit.c			\
		$(FT_STR_DIR)/ft_strstr.c			\
		$(FT_STR_DIR)/ft_strsub.c			\
		$(FT_STR_DIR)/ft_strtrim.c			\

ALLFLAGS = -I$(INCLUDES) -o
OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
RM = rm -rf
PRINT = printf

_GREEN=\e[32m
_YELLOW=\e[33m
_CYAN=\e[36m
_END=\e[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(PRINT) "\nCreating library... :"
	@ar rcs $(NAME) $(OBJ)
	@printf "[$(_GREEN)✓$(_END)]\n\n"

$(OBJDIR)/%.o: %.c $(HEAD)
	@$(PRINT) "Libft : "
	@$(CC) -c $(CFLAGS) $(ALLFLAGS) $@ $<
	@$(PRINT) "$(_CYAN)$<\n$(_END)"

$(OBJDIR) :
	@mkdir  $@ $@/$(FT_IS_DIR) $@/$(FT_LST_DIR) $@/$(FT_MEM_DIR) \
			$@/$(FT_MISC_DIR) $@/$(FT_PUT_DIR) $@/$(FT_STR_DIR)

$(OBJ) : | $(OBJDIR)

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SUFFIXES: .c .o .h
