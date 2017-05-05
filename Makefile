# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/05 11:19:06 by kdrumm            #+#    #+#              #
#    Updated: 2017/05/05 16:34:58 by kdrumm           ###   ########.us        #
#                                                                              #
# **************************************************************************** #

NAME = ft_db
CFLAGS = -Wall -Wextra -Werror
LIBFT = -L libft/ -lft
HEADER = ft_db.h
SRCS = main.c init.c print.c records.c columns.c search.c speak.c

.PHONY: all norme clean fclean re

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(addprefix src/, $(SRCS)) $(LIBFT)

norme:
	norminette src/$(SRCS) includes/$(HEADER)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
