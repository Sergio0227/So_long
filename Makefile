SRC = 	main.c \
		map_parser.c \
		map_parser2.c \
		so_long_utils.c \

NAME = so_long
OBJS = ${SRC:.c=.o}
CC		= cc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libft
MLX_PATH = ./minilibx-linux


all: mlx ${NAME} 

libft:
	${MAKE} -C ${LIBFT_PATH}

mlx: 
	wget https://cdn.intra.42.fr/document/document/24017/minilibx-linux.tgz
	tar -xzvf minilibx-linux.tgz
	${RM} minilibx-linux.tgz
	${MAKE} -C ${MLX_PATH}

.c.o: 
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}


so_long: ${OBJS} libft mlx
	${CC} ${OBJS} -Werror -Wextra -Wall -o so_long -L./minilibx-linux -lmlx_Linux -lX11 -lXext -L./libft -lft

clean:
	${MAKE} -C ${LIBFT_PATH} clean
	${MAKE} -C ${MLX_PATH} clean
	${RM} ${OBJS}

fclean:	clean
	${MAKE} -C ${LIBFT_PATH} fclean
	${RM} ${NAME}
	${RM} so_long
	${RM}r minilibx-linux

re: fclean all

.PHONY: all clean fclean re libft
