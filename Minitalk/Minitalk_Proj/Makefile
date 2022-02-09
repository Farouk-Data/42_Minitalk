SRC_SERVER = ft_printf.c	\
	ft_printf_utils.c	\
	ft_printf_utils2.c	\
	utils.c  \
	server.c  \

SRC_SERVER_B = ft_printf.c	\
	ft_printf_utils.c	\
	ft_printf_utils2.c	\
	utils.c  \
	server_bonus.c  \

SRC_CLIENT = ft_printf.c	\
	ft_printf_utils.c	\
	ft_printf_utils2.c	\
	utils.c  \
	client.c  \

SRC_CLIENT_B = ft_printf.c	\
	ft_printf_utils.c	\
	ft_printf_utils2.c	\
	utils.c  \
	client_bonus.c  \

OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS_SERVER_B = $(SRC_SERVER_B:.c=.o)
OBJS_CLIENT_B = $(SRC_CLIENT_B:.c=.o)

SERVER = server
CLIENT = client
SERVER_B = server_bonus
CLIENT_B = client_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

%.o :%.c utils.h printf.h
	$(CC) -c $(CFLAGS) $< -o $@

$(SERVER) : $(OBJS_SERVER)
	$(CC) $(OBJS_SERVER) -o $(SERVER)

$(CLIENT) : $(OBJS_CLIENT)
	$(CC) $(OBJS_CLIENT) -o $(CLIENT)

$(SERVER_B) : $(OBJS_SERVER_B)
	$(CC) $(OBJS_SERVER_B) -o $(SERVER_B)

$(CLIENT_B) : $(OBJS_CLIENT_B)
	$(CC) $(OBJS_CLIENT_B) -o $(CLIENT_B)

all : $(SERVER) $(CLIENT) 

bonus : $(CLIENT_B) $(SERVER_B) 

clean :
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_B) $(OBJS_CLIENT_B)   

fclean : clean
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B) 

re : fclean $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B) 

.PHONY : all clean fclean re
