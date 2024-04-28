# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 11:25:29 by nait-bou          #+#    #+#              #
#    Updated: 2024/04/28 09:23:04 by nait-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

NAME3 = server_bonus

NAME4 = client_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCE1 = Minitalk_utils.c

SOURCE2 = Minitalk_utils_bonus.c

OBJ1 = $(SOURCE1:.c=.o)

OBJ2 = $(SOURCE2:.c=.o)

HD1 = minitalk.h

HD2 = minitalk_bonus.h

all: $(NAME1) $(NAME2)

$(NAME1) : server.c  $(HD1)
	$(CC) $(CFLAGS) server.c $(SOURCE1) -o server
$(NAME2) : client.c $(HD1)
	$(CC) $(CFLAGS) client.c $(SOURCE1) -o client

bonus: $(NAME3) $(NAME4)
$(NAME3) : server_bonus.c $(HD2)
	$(CC) $(CFLAGS) server_bonus.c $(SOURCE2) -o server_bonus
$(NAME4) : client_bonus.c $(HD2)
	$(CC) $(CFLAGS) client_bonus.c $(SOURCE2) -o client_bonus
	
clean:
	@rm -rf $(OBJ1) $(OBJ2)
fclean: clean
	@rm -rf $(NAME1) $(NAME2) $(NAME3) $(NAME4)

re: fclean all bonus
