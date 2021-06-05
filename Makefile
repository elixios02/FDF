# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paim <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/10 14:55:05 by paim              #+#    #+#              #
#    Updated: 2016/09/19 17:17:20 by paim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c\
	  parse.c\
	  splitatoi.c\
	  couleur.c\
	  error.c\
	  printpoint.c\
	  printbresenham.c

OBJ = $(SRC:.c=.o)

.PHONY: clean fclean re libft minilibx

all: $(NAME)

$(NAME) : libft minilibx
	@clang $(SRC) -o $(NAME) -L./libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "Easy compil ma poule"

minilibx:
	@make -C minilibx_macos

libft:
	@make -C libft

clean:
	@make -C minilibx_macos/ clean
	@make -C libft/ clean
	@rm -f $(OBJ)
	@echo "T'inquiete pas ca delete juste les .o :)"

fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "La tu peux stresser parcque je delete touuuuuuuuuuuut"

re: fclean all
