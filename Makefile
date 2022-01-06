# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fharing <fharing@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 14:03:15 by fharing           #+#    #+#              #
#    Updated: 2021/08/09 12:00:41 by fharing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar cr
NAME_LIB= libft.a
NAME = libmlx.a
SOURCES = ./src/main.c ./src/checkmap.c ./src/helper.c ./src/move.c ./src/putimage.c \
./src/putimage_2.c ./src/readmap.c ./src/readmap_2.c
OBJECTS = $(SOURCES:.c=.o)

#build everything
all: $(NAME)

#make libft
LIB:
	make -C ./libft
	cp ./libft/libft.a $(NAME_LIB)
	make -C ./mlx
	cp ./mlx/libmlx.a $(NAME)

#creates a static library
$(NAME): LIB $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) libft.a libmlx.a -framework OpenGL -framework AppKit -o so_long

#removes all *.o files
clean:
	$(RM) $(OBJECTS)
	make clean -C ./libft
	make clean -C ./mlx

#removes all *.o files + libft.a + libmlx.a
fclean: clean
	$(RM) $(NAME)
	$(RM) ./libft/libft.a
	$(RM) ./mlx/libmlx.a
	$(RM) libmlx.a
	$(RM) libft.a
	$(RM) so_long

#removes all *.o files + libft.a + libmlx.a and rebuild everything
re: fclean all
