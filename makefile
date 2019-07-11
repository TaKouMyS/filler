# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 18:16:49 by amamy             #+#    #+#              #
#    Updated: 2019/05/28 18:16:53 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = amamy.filler
SHELL = /bin/sh
CC = clang
CFLAGS += -Wall -Werror -Wextra -g
OBJDIR = obj
SRCDIR = src
SRC_READ_DIR = $(SRCDIR)/read
SRC_CHECKS_DIR = $(SRCDIR)/checks
SRC_PLAY_DIR = $(SRCDIR)/play
LIBDIR	= libft
HEAD	= $(SRCDIR)/filler.h

SRCS 	= $(SRCDIR)/main.c					\
		$(SRCDIR)/free.c					\
		$(SRCDIR)/ft_star_line.c			\
		$(SRC_READ_DIR)/read.c				\
		$(SRC_READ_DIR)/read_map.c			\
		$(SRC_READ_DIR)/read_piece.c		\
		$(SRC_CHECKS_DIR)/checks.c			\
		$(SRC_CHECKS_DIR)/check_map.c		\
		$(SRC_CHECKS_DIR)/check_piece.c		\
		$(SRC_CHECKS_DIR)/check_shape.c		\
		$(SRC_PLAY_DIR)/play.c				\
		$(SRC_PLAY_DIR)/analyse.c			\
		$(SRC_PLAY_DIR)/go_up.c				\
		$(SRC_PLAY_DIR)/go_down.c			\
		$(SRC_PLAY_DIR)/go_cut.c			\
		$(SRC_CHECKS_DIR)/check_play.c

ALLFLAGS = -I$(LIBDIR) -I$(SRCDIR) -o
OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIB		= $(LIBDIR)/libft.a
RM = rm -rf
PRINT = printf

_GREEN=\e[32m
_YELLOW=\e[33m
_CYAN=\e[36m
_END=\e[0m

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@$(PRINT) "Compilation OK! "
	@$(CC) -o $@ $^
	@$(PRINT) "[$(_GREEN)✓$(_END)]\n"

$(LIB): | $(OBJDIR)
	@$(PRINT) "Libft : "
	@make -C $(LIBDIR)

$(OBJDIR)/%.o: %.c $(HEAD)
	@$(PRINT) "Sources : "
	@$(CC) -c $(CFLAGS) $(ALLFLAGS) $@ $<
	@$(PRINT) "$(_CYAN)$<\n$(_END)"


$(OBJDIR) :
	@mkdir  $@ $@/$(SRCDIR) $@/$(LIBDIR) $@/$(SRC_READ_DIR) $@/$(SRC_CHECKS_DIR) $@/$(SRC_PLAY_DIR)

$(OBJ) : | $(OBJDIR)

clean:
	@$(PRINT) "clean... "
	@$(RM) $(OBJDIR)
	@$(PRINT) "[$(_YELLOW)✓$(_END)]\n"

fclean: clean
	@$(PRINT) "fclean... "
	@$(RM) $(NAME)
	@make fclean -C $(LIBDIR)
	@$(PRINT) "[$(_BLUE)✓$(_END)]\n"

re: fclean all clean

.PHONY: clean fclean all re
.SUFFIXES: .c .o .h
