# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 12:33:35 by paugonca          #+#    #+#              #
#    Updated: 2023/08/28 12:34:33 by paugonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -g

RM			= rm -f
MKD			= mkdir

SRC_NAME	= main.c			\
			  extra_utils.c

SRC			= $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ			= $(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRC))

SRC_PATH	= ./src
OBJ_PATH	= ./obj

all: $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(DEPS) $(OBJ_PATH) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	$(MKD) -p obj

clean:
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
