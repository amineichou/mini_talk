FLAGS = -Wall -Wextra -Werror
CC = cc
NAME = server client
SRC = server.c client.c
UTILS = utils.c

all: $(NAME)

$(NAME): $(SRC:.c=.o) $(UTILS:.c=.o)
    $(CC) $(FLAGS) server.o utils.o -o server
    $(CC) $(FLAGS) client.o utils.o -o client

%.o: %.c
    $(CC) $(FLAGS) -c $< -o $(basename $@)

clean:
    rm -f $(NAME) *.o

fclean: clean

re: fclean all

.PHONY: all clean fclean re
