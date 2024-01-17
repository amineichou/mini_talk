CFLAGS = -Wall -Wextra -Werror
UTILS = utils.c
BUILT = server client
CC = cc

all: $(BUILT)

server : server.c
	$(CC) $(CFLAGS) server.c $(UTILS) -o server

client : client.c
	$(CC) $(CFLAGS) client.c $(UTILS) -o client

clean:
	rm -f $(BUILT)

fclean: clean all

re: clean all

.Phonny : server client clean re