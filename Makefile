# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/25 15:02:32 by kkinzers          #+#    #+#              #
#    Updated: 2019/07/19 19:29:09 by kkinzers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

LIB_H = -L ./lib
LIB_DIR = ./libft
SRCDIR	= ./src
INCDIR	= ./includes
OBJDIR	= ./obj

SRC = wolf.c draw.c read_map.c validator.c get_next_line.c events.c init.c \
	  drawfl.c phy.c

SRCO = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

HEADER = wolf3d.h
HEADER_FLAGS = -I $(HEADER)

FLAGS = -O2 -Wall -Wextra -Werror \
		-I ~/Library/frameworks/SDL2.framework/Versions/A/Headers \
		-F ~/Library/frameworks \
		-I ~/Library/frameworks/SDL2_image.framework/Versions/A/Headers
FRAME_FLAGS = -framework SDL2 -framework SDL2_image

LIB = $(LIB_DIR)libft.a
LIB_FLAGS = -lft -L $(LIB_DIR)

all: obj $(LIB_DIR) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(LIB):
	@make -C $(LIB_DIR)
$(NAME): $(LIB) $(SRCO)
	@gcc $(FLAGS) $(SRCO) $(LIB_FLAGS) $(FRAME_FLAGS) -o  $(NAME)
$(OBJDIR)/%.o:$(SRCDIR)/%.c
	gcc -c $(FLAGS) $< -o $@ -I $(INCDIR)
clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIB_DIR)
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_DIR)
re: fclean all
