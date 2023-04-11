# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 16:22:00 by llion             #+#    #+#              #
#    Updated: 2023/04/11 18:25:02 by llion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= philo
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -ggdb3
RM			= rm -rf
SRC			= philo.c	\
			  ft_atoi.c	\
			  actions.c	\
			  init.c
HEADERS		= -I include -lpthread -D_REETRANT
OBJ			= $(addprefix obj/,$(SRC:.c=.o))

all:		$(NAME)

obj/%.o:	src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	@$(CC) $(HEADERS) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "\033[32m[OK]\033[0m\t\tcompiled\n"

debug:		$(OBJ)
	@$(CC) $(HEADERS) $(CFLAGS) $(OBJ) -fsanitize=address -o $(NAME)
	@printf "\033[31m[DB]\033[0m\t\tcompiled\n"

thread:		$(OBJ)
	@$(CC) $(HEADERS) $(CFLAGS) $(OBJ) -fsanitize=thread -o $(NAME)
	@printf "\033[34m[TH]\033[0m\t\tcompiled\n"

clean:
	@$(RM) $(OBJ)
	@printf "\033[32m[OK]\033[0m\t\tobjects cleaned\n"

fclean:		clean
	@$(RM) $(NAME)
	@printf "\033[32m[OK]\033[0m\t\t$(NAME) cleaned\n"

re:			fclean all

.PHONY: all clean fclean re
