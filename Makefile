# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 18:20:05 by baboulou          #+#    #+#              #
#    Updated: 2023/05/05 00:16:15 by baboulou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client
NAME1_B = server_bonus
NAME2_B = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_S = server.c
SRC_C = client.c
SRC_C_B = client_bonus.c
SRC_S_B = server_bonus.c
SRC_UTILS = utils.c
OBJ_S = $(patsubst %.c, %.o, $(SRC_S))
OBJ_C = $(patsubst %.c, %.o, $(SRC_C))
OBJ_S_B = $(patsubst %.c, %.o, $(SRC_S_B))
OBJ_C_B = $(patsubst %.c, %.o, $(SRC_C_B))
OBJ_UTILS = $(patsubst %.c, %.o, $(SRC_UTILS))
HEADERS = minitalk.h

all:		$(NAME1) $(NAME2) $(HEADERS)

bonus:		$(NAME1_B) $(NAME2_B) $(HEADERS)

$(NAME1):	$(OBJ_S) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_S) ${OBJ_UTILS} -o $(NAME1)

$(NAME2):	$(OBJ_C) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_C) $(OBJ_UTILS) -o $(NAME2)

$(NAME1_B):	$(OBJ_S_B) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_S_B) $(OBJ_UTILS) -o $(NAME1_B)

$(NAME2_B):	$(OBJ_C_B) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_C_B) $(OBJ_UTILS) -o $(NAME2_B)

%.o:		%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_S) $(OBJ_C) $(OBJ_UTILS) $(OBJ_S_B) $(OBJ_C_B)

fclean:		clean
	rm -f $(NAME1) $(NAME2) $(NAME1_B) $(NAME2_B)

re:			fclean all

.PHONY:		all clean fclean re bonus 
