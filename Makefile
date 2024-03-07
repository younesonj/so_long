
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = check_images.c check_path.c move_next_cheker.c split_function.c check_map.c move_next.c \
		so_long_utils2.c game.c draw_map.c libft_fun.c read_map.c so_long_utils.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c \
		printf/ft_hex.c printf/ft_putchar.c printf/ft_putstr.c printf/ft_Upphex.c \
		printf/ft_printf.c  printf/ft_putadress.c  printf/ft_putnbr.c printf/ft_putunsigned.c

OBJS = $(SRCS:.c=.o)

LIBS = -lmlx -lX11 -lXext 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)	
	
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re 