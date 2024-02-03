FLAGS = -Wall -Wextra -Werror
CC = cc
SERVER = server
CLIENT = client
SERVER_SRC = server.c
CLIENT_SRC = client.c
UTILS = utils.c

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRC) $(UTILS) minitalk.h
	$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS) -o $(SERVER)

$(CLIENT): $(CLIENT_SRC) $(UTILS) minitalk.h
	$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS) -o $(CLIENT)

clean:
	rm -f $(SERVER) $(CLIENT)

re: clean all

.PHONY: all clean re
