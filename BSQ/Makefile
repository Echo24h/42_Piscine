SRCS 	=	src/ft_putchar.c \
			src/ft_strlen.c \
			src/ft_parsing.c \
			src/ft_putstr.c \
			src/check_map.c \
			src/functions.c \
			src/functionsbis.c \
			src/init.c \
			src/manage_stand.c \
			src/main.c

NAME	= 	bsq

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

RM		= 	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I includes $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
