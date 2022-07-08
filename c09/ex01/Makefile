SRCS = srcs/ft_putchar.c \
	   srcs/ft_putstr.c \
	   srcs/ft_strlen.c \
	   srcs/ft_strcmp.c \
	   srcs/ft_swap.c

NAME	= 	libft.a

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

RM		= 	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I includes $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
