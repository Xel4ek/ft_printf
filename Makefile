CC =  gcc

NAME = libftprintf.a

SRC = ft_printf.c main.c numeric.c pars.c print_tool.c tools.c

OBJ = $(SRC:.c=.o)

HEADER = /

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ):%.o:%.c
	$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
