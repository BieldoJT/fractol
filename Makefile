NAME = fractol



SRC_DIR = ./src/


LIBFT = ./libraries/Libft/libft.a

MINILIBX = make_minilibx

CC = cc

CC_FLAGS = -Wall -Werror -Wextra -g

MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

VALGRIND = @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

MANDATORY_SCRS =  $(addprefix $(SRC_DIR),\
				main.c\
				init.c\
				convert.c\
				hooks.c\
				utils.c)


all: ${LIBFT} ${MINILIBX} ${NAME}

${NAME}:
		${CC} ${MANDATORY_SCRS} ${LIBFT} ${CC_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
		@echo "\n${NAME} is compiled."
		@echo

make_minilibx:
		make -C minilibx-linux/

${LIBFT}:
		make bonus -C libraries/Libft

clean:
		make clean -C libraries/Libft
		make clean -C minilibx-linux/

fclean: clean
		rm -rf ${NAME}

re: fclean all



.PHONY:			all clean fclean re rebonus
