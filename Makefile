# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 14:55:04 by hwolf             #+#    #+#              #
#    Updated: 2019/10/19 19:48:13 by hwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC =  gcc
CFLAGS = -Wall -Wextra -Werror

SRC = apply_flags.c data.c e_double_tool.c e_double.c \
        f_double.c ft_printf.c int_funcions.c parse.c \
         parse_tool.c print_tool.c string_tool.c tools.c

SRCDIR = src
OBJDIR = obj
LIBDIR = lib/libft
LIB = libft.a

OBJ =$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

HEADERS = -Ilib/libft/includes -Iincludes
HEADER = includes/ft_printf.h

.PHONY: all clean fclean re help

all: $(NAME)

help:
	@echo "Usage :"
	@echo "\tmake //create library"
	@echo "\tmake clean // remove *.o files"
	@echo "\tmake flean //remove *.o files and library"
	@echo "\tmake re // redo library"

clean:
	rm -rf $(OBJDIR)
	@make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBDIR)

re: fclean all

$(NAME): $(OBJDIR) $(OBJ) $(HEADER) $(LIBDIR)/$(LIB)
	cp $(LIBDIR)/$(LIB) ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(LIBDIR)/$(LIB):
	make -C $(LIBDIR)
	@make clean -C $(LIBDIR)

$(OBJ):$(OBJDIR)/%o:$(SRCDIR)/%c
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(OBJDIR):
	mkdir -p $(OBJDIR)
