NAME = push_swap
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = 	\
		algorithms/sort_radix.c algorithms/sort_three_elements.c algorithms/sort_under_five_elements.c \
		commands/swap.c commands/push.c commands/rotate.c commands/revrotate.c \
		utils/clean.c utils/custom_atoi.c utils/index.c utils/initialize.c \
		utils/parse.c utils/print.c utils/sort.c utils/validate.c main.c

all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
