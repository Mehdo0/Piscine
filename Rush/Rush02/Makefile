NAME = rush-02

SRCS = ex00/main.c ex00/read_dictionary.c ex00/final_step.c ex00/parse_dict.c \
       ex00/ft_u3.c ex00/ft_u2.c ex00/ft_u1.c ex00/ft_dissection.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

# Default rule
all: ${NAME}

# Rule to create the executable
${NAME}: ${OBJS}
	cc -o ${NAME} ${OBJS} -Iincludes

# Rule to compile .c files to .o files
%.o: %.c
	cc ${CFLAGS} -Iincludes -c $< -o $@

# Clean up object files
clean:
	rm -f ${OBJS}

# Clean up all generated files
fclean: clean
	rm -f ${NAME}

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
