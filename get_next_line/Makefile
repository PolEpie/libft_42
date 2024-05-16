CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fPIE
DIR		= srcs/
NAME	= libgnl.a
SRC		= 	./get_next_line_bonus.c \
			./get_next_line_utils_bonus.c
OBJS	= ${SRC:.c=.o}
HEAD	= ./../includes/
AR		= ar rcs
RM		= rm -f

all: ${NAME}

.c.o:
		${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${AR} ${NAME} ${OBJS}

so:
		gcc *.o --shared -o libft.so

clean:      
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

test: ${NAME}
		${CC} ${CFLAGS} -I ${HEAD} main.c -L -lgnl -L -lft_core ${NAME} -o test
		./test

re: fclean all
