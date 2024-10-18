NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

LDFLAGS =  -lmlx -framework OpenGL -framework AppKit

LIBFT_PATH = mainlibft/

LIBFT = $(LIBFT_PATH)libft.a

SRC = so_long.c so_map.c so_check_map.c so_check_map2.c so_flood.c\
		so_make_map.c so_init.c so_movement.c so_movement2.c\

OBJS = $(SRC:.c=.o)

RM = rm -f

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(LDFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re