# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msidqi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 00:08:25 by msidqi            #+#    #+#              #
#    Updated: 2018/11/25 22:04:07 by msidqi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft.a
EXE = fdf
SRC = Sources/*.c
OBJ = *.o
LIB = libsh.a
CC = gcc -Wall -Wextra -Werror 
FLAGS = -lmlx -framework OpenGl -framework Appkit

all : $(EXE)

$(LIB) :
	$(CC) -c $(SRC) $(INCLUDE)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)
$(LIBFT) : 
	make re -C Sources/libft
$(EXE) : $(LIB) $(LIBFT)
	$(CC) -o fdf $(SRC) fdf.c $(LIB) $(FLAGS) Sources/libft/libft.a

clean : 
	rm -rf $(OBJ) $(LIB)
	make clean -C Sources/libft
fclean : clean
	rm -rf $(LIB) $(EXE)
	make fclean -C Sources/libft
re : fclean all
