# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 15:24:49 by hwolf             #+#    #+#              #
#    Updated: 2019/09/20 16:29:45 by hwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =   ft_atoi_base.c  \
        ft_atoi.c  \
        ft_bzero.c  \
        ft_isalnum.c  \
        ft_isalpha.c  \
        ft_isascii.c  \
        ft_isdigit.c  \
        ft_isprint.c  \
        ft_itoa_base.c  \
        ft_itoa.c  \
        ft_lstadd.c  \
        ft_lstappend.c  \
        ft_lstdel.c  \
        ft_lstdelone.c  \
        ft_lstiter.c  \
        ft_lstlen.c  \
        ft_lstmap.c  \
        ft_lstnew.c  \
        ft_memalloc.c  \
        ft_memccpy.c  \
        ft_memchr.c  \
        ft_memcmp.c  \
        ft_memcpy.c  \
        ft_memdel.c  \
        ft_memmove.c  \
        ft_memset.c  \
        ft_putchar.c  \
        ft_putchar_fd.c  \
        ft_putendl.c  \
        ft_putendl_fd.c  \
        ft_putnbr.c  \
        ft_putnbr_fd.c  \
        ft_putstr.c  \
        ft_putstr_fd.c  \
        ft_sort_str_table.c  \
        ft_strcapitalize.c  \
        ft_strcat.c  \
        ft_strchr.c  \
        ft_strclr.c  \
        ft_strcmp.c  \
        ft_strcpy.c  \
        ft_strdel.c  \
        ft_strdup.c  \
        ft_strequ.c  \
        ft_striter.c  \
        ft_striteri.c  \
        ft_strjoin.c  \
        ft_strlcat.c  \
        ft_strlen.c  \
        ft_strmap.c  \
        ft_strmapi.c  \
        ft_strncat.c  \
        ft_strncmp.c  \
        ft_strncpy.c  \
        ft_strnequ.c  \
        ft_strnew.c  \
        ft_strnstr.c  \
        ft_strrchr.c  \
        ft_strsplit.c  \
        ft_strstr.c  \
        ft_strsub.c  \
        ft_strtrim.c  \
        ft_tolower.c  \
        ft_toupper.c  \
        get_next_line.c  \



SRC_DIR = src
OBJ_DIR = ./
HEADERS = includes

OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = libft.a

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(OBJ):$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(HEADERS) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
