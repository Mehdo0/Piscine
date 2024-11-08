NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/main.c srcs/utilities.c srcs/solve.c srcs/get_map.c srcs/get_map_info.c srcs/get_board.c
OBJS = $(SRCS:.c=.o)
HEADERS = includes/ft.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
