NAME = get_next_line

CRCS = main.c get_next_line.c


all: $(NAME)

$(NAME):
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -I libft/includes -o main.o -c main.c
	clang -o $(NAME) main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
	-rm -f *.o

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re