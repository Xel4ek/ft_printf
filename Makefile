CC =  gcc

NAME = libftprintf.a

SRC = apply_flags.c data.c e_double_tool.c e_double.c \
        f_double.c ft_printf.c int_funcions.c parse.c \
         parse_tool.c print_tool.c string_tool.c tools.c
SRCDIR = src
OBJDIR = obj
LIBDIR = lib/libft
LIB = libft.a

OBJ =$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

HEADERS = -Ilib/libft/includes -I.
HEADER = ft_printf.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	cp $(LIBDIR)/$(LIB) ./$(NAME)
	ar rc $(NAME) %(OBJDIR)/%(OBJ)
	ranlib $(NAME)

$(OBJ):$(OBJDIR)%o:$(SRCDIR)%c
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(HEADERS) -o $@ -c $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
