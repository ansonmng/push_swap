SRCS	=	push_swap.c \
			push_swap_utils.c \
			sort.c \
			sort_utils.c \
			sort_big_utils.c \
			instructions.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I. -g

RM		=	rm -rf

NAME	=	push_swap

LINKS	=	./libft/libft.a

all: ${NAME}

${NAME} : ${OBJS} libft
		gcc -o ${NAME} ${OBJS} ${LINKS} 
		
libft :
	make bonus -C libft

clean:
	${RM} ${OBJS}
	make -C libft fclean

fclean: clean
	${RM} ${NAME} libft/libft.a libft.a

re: fclean all

.PHONY: all libft clean fclean re

