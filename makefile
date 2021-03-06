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
SRC_HEATMAP_DIR = $(SRCDIR)/heatmap
LIBDIR	= libft
HEAD	= $(SRCDIR)/filler.h

SRCS 	= $(SRCDIR)/main.c					\
		$(SRCDIR)/free.c					\
		$(SRCDIR)/play.c					\
		$(SRC_READ_DIR)/read.c				\
		$(SRC_READ_DIR)/read_map.c			\
		$(SRC_READ_DIR)/read_piece.c		\
		$(SRC_READ_DIR)/get_first_piece.c	\
		$(SRC_CHECKS_DIR)/check_piece.c		\
		$(SRC_CHECKS_DIR)/check_shape.c		\
		$(SRC_CHECKS_DIR)/check_play.c		\
		$(SRC_HEATMAP_DIR)/make_heatmap.c	\
		$(SRC_HEATMAP_DIR)/init_heatmap.c


ALLFLAGS = -I$(LIBDIR)/includes -I$(SRCDIR) -o
OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIB		= $(LIBDIR)/libft.a
RM = rm -rf
PRINT = printf

_GREEN=\e[32m
_YELLOW=\e[33m
_CYAN=\e[36m
_END=\e[0m

all: $(NAME)
	@echo "                                               __ _ _ _           "
	@echo "                                              / _(_) | |          "
	@echo "   __ _ _ __ ___   __ _ _ __ ___  _   _      | |_ _| | | ___ _ __ "
	@echo "  / _\` | '_ \` _ \ / _\` | '_ \` _ \| | | |     |  _| | | |/ _ \ '__|"
	@echo " | (_| | | | | | | (_| | | | | | | |_| |  _  | | | | | |  __/ |   "
	@echo "  \__,_|_| |_| |_|\__,_|_| |_| |_|\__, | (_) |_| |_|_|_|\___|_|   "
	@echo "                                   __/ |                          "
	@echo "                                  |___/                           "

$(NAME): $(LIB) $(OBJ)
	@$(PRINT) "Compilation OK! "
	@$(CC) $(CFLAGS) $(OBJ) $< -o $@
	@$(PRINT) "[$(_GREEN)✓$(_END)]\n"

$(LIB): | $(OBJDIR)
	@$(PRINT) "Compiling objects :\n"
	@make -C $(LIBDIR)

$(OBJDIR)/%.o: %.c $(HEAD)
	@$(PRINT) "Filler : "
	@$(CC) -c $(CFLAGS) $(ALLFLAGS) $@ $<
	@$(PRINT) "$(_CYAN)$<\n$(_END)"


$(OBJDIR) :
	@mkdir  $@ $@/$(SRCDIR) $@/$(LIBDIR) $@/$(SRC_READ_DIR) \
		$@/$(SRC_CHECKS_DIR) $@/$(SRC_HEATMAP_DIR)

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
