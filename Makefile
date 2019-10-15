CC =  gcc

NAME = libftprintf.a

SRC = ft_printf.c numeric.c parse.c print_tool.c tools.c
LIB_OBG = lib/libft/*.o
OBJ = $(SRC:.c=.o)

HEADER = lib/libft/includes

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJ)
	cp lib/libft/libft.a libft.a
	ar x libft.a
	ar rc $(NAME) $(LIB_OBG) *.o
	ranlib $(NAME)

$(OBJ):%.o:%.c
	$(CC) $(FLAGS) -I$(HEADER) -I. -o $@ -c $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
