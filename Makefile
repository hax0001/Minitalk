# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 23:45:41 by nait-bou          #+#    #+#              #
#    Updated: 2024/03/09 14:40:22 by nait-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
RM = rm -rf

SERVER = server
CLIENT = client

SF = server.c
SOF = $(SV_SRCS:.c=.o)

CF = client.c
COF = $(CLIENT_SRCS:.c=.o)



all: $(SERVER) $(CLIENT)

$(LIBFT):
	make -C ./libft

$(SERVER): $(SOF) $(LIBFT)
	$(CC) $(CFLAGS) $(SF) $(LIBFT) -o server

$(CLIENT): $(COF) $(LIBFT)
	$(CC) $(CFLAGS) $(CF) $(LIBFT) -o client

clean:
	rm -f $(COF) $(SOF)
	cd ./libft && make clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	cd ./libft && make fclean

re: fclean all
