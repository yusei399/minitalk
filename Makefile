CC = cc
CFLAGS = -Wall -Wextra -Werror
MANDATORY_SERVER_SRCS = ft_atoi.c  server.c ft_putnbr.c ft_putchar.c
BONUS_SERVER_SRCS = ft_atoi.c  server_bonus.c ft_putnbr.c ft_putchar.c
MANDATORY_SERVER_OBJS = $(MANDATORY_SERVER_SRCS:.c=.o)
BONUS_SERVER_OBJS = $(BONUS_SERVER_SRCS:.c=.o)
SERVER = server
MANDATORY_CLIENT_SRCS = client.c ft_atoi.c ft_putnbr.c ft_putchar.c
BONUS_CLIENT_SRCS = client_bonus.c ft_atoi.c ft_putnbr.c ft_putchar.c
MANDATORY_CLIENT_OBJS = $(MANDATORY_CLIENT_SRCS:.c=.o)
BONUS_CLIENT_OBJS = $(BONUS_CLIENT_SRCS:.c=.o)
CLIENT = client
NAME = minitalk

ifdef BONUS
    CLIENT_OBJS = $(BONUS_CLIENT_OBJS)
    SERVER_OBJS = $(BONUS_SERVER_OBJS)
else
    CLIENT_OBJS = $(MANDATORY_CLIENT_OBJS)
    SERVER_OBJS = $(MANDATORY_SERVER_OBJS)
endif

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER) 

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(BONUS_SERVER_OBJS) $(BONUS_CLIENT_OBJS)

fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re: fclean all

bonus:
	@make BONUS=1 all

.PHONY: make clean fclean re bonus



# CC = cc
# GCC_FLAGS = -Wall -Wextra -Werror
# MANDATORY_SERVER_SRC = ft_atoi.c  server.c ft_putnbr.c ft_putchar.c
# BONUS_SERVER_SRC = ft_atoi.c  server_bonus.c ft_putnbr.c ft_putchar.c
# MANDATORY_SERVER_OBJ = $(MANDATORY_SERVER_SRC:.c=.o)
# BONUS_SERVER_OBJ = $(BONUS_SERVER_SRC:.c=.o)
# SERVER = server
# MANDATORY_CLIENT_SRC = client.c ft_atoi.c ft_putnbr.c ft_putchar.c
# BONUS_CLIENT_SRC = client_bonus.c ft_atoi.c ft_putnbr.c ft_putchar.c