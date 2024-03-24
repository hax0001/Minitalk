# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 23:45:41 by nait-bou          #+#    #+#              #
#    Updated: 2024/03/24 15:12:16 by nait-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
SERVER = server
CLIENT = client
SERVER_B = server_bonus
CLIENT_B = client_bonus

SF = server.c
SOF = $(SF:.c=.o)
CF = client.c
COF = $(CF:.c=.o)

SBF = server_bonus.c
SBOF = $(CBF:.c=.o)
CBF = client_bonus.c
CBOF = $(CBF:.c=.o)



all: $(SERVER) $(CLIENT)

$(LIBFT):
	make -C ./libft

$(SERVER): $(SOF) $(LIBFT)
	$(CC) $(CFLAGS) $(SF) $(LIBFT) -o server

$(CLIENT): $(COF) $(LIBFT)
	$(CC) $(CFLAGS) $(CF) $(LIBFT) -o client

bonus: $(SERVER_B) $(CLIENT_B)

$(SERVER_B): $(SBOF) $(LIBFT)
	$(CC) $(CFLAGS) $(SBF) $(LIBFT) -o server_bonus

$(CLIENT_B): $(CBOF) $(LIBFT)
	$(CC) $(CFLAGS) $(CBF) $(LIBFT) -o client_bonus

clean:
	rm -f $(COF) $(SOF) $(SBOF) $(CBOF)
	cd ./libft && make clean

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)
	cd ./libft && make fclean

re: fclean all
