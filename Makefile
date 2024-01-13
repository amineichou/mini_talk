CFLAGS = -Wall -Wextra -Werror ft_printf/libftprintf.a libft/libft.a
SRC = client.c server.c
OBJ = client server
CC = cc

all: $(OBJ)

$(OBJ): 
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

re: clean all
