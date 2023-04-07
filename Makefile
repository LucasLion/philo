# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 16:22:00 by llion             #+#    #+#              #
#    Updated: 2023/04/07 08:27:51 by llion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= philo
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
SRC			= philo.c
HEADERS		= -I include
OBJ			= $(addprefix obj/,$(SRC:.c=.o))

all:		$(NAME)

obj/%.o:	src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	@$(CC) $(HEADERS) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "\033[32m[OK]\033[0m\t compiled\n"

debug:		$(OBJ)
	@$(CC) $(HEADERS) $(CFLAGS) $(OBJ) -fsanitize=address -o $(NAME)
	@printf "\033[31m[DB]\033[0m\t compiled\n"

clean:
	@$(RM) $(OBJ)
	@printf "\033[32m[OK]\033[0m\t objects cleaned\n"

fclean:		clean
	@$(RM) $(NAME)
	@printf "\033[32m[OK]\033[0m\t $(NAME) cleaned\n"

re:			fclean all

.PHONY: all clean fclean re
