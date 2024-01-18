CFLAGS = -Wall -Wextra -Werror
UTILS = utils.c
BUILT = server client
CC = cc

all: $(BUILT)

server : server.c $(UTILS)
	$(CC) $(CFLAGS) server.c -o server

client : client.c $(UTILS)
	$(CC) $(CFLAGS) client.c -o client

clean:
	rm -f $(BUILT)

fclean: clean all

re: clean all

.PHONY : server client clean re