CC			= cc
CFLAGS		= -Wall -Wextra -Werror
DIR			= srcs/
NAME		= hashtable.a
SRC			= 	./hashtable.c
OBJS		= ${SRC:.c=.o}
HEAD		= ./includes/
INCLUDE_LIBFT = ./../includes/
AR			= ar rcs
RM			= rm -f
LIBFT_PATH  = ./../

all: ${NAME}

.c.o:
		${CC} ${CFLAGS} -c -I ${HEAD} -I ${INCLUDE_LIBFT} $< -o ${<:.c=.o}

$(NAME): $(OBJS)
		cp $(LIBFT_PATH)libft_core.a ${NAME}
		$(AR) $(NAME) ${OBJS}

test:
		${CC} -I ${HEAD} -I ${INCLUDE_LIBFT}  $< ${SRC} ../libft_core.a
		./a.out

clean:      
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

bonus: all