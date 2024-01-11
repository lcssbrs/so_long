PROG	= so_long

SRCS 	= src/solong.c src/read_map.c src/flood.c src/check_arg.c src/check_utils.c src/mlx.c src/mlx_img.c src/check_args.c src/mlx_move.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= src/solong.c

HEADER	= -Iinclude

CC 		= gcc
CFLAGS 	= -g -Wall -Wextra -Werror 

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER}-I/usr/include -Imlx_linux -O3 -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./Libft
					@make re -C ./printf
					@$(CC) ${OBJS} -LLibft -lft -Lprintf -lprintf -Lmlx -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${PROG}
					@echo "\033[32mSo Long Compiled!\n"

clean:
					@make clean -C ./Libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./Libft
					@rm -f $(NAME)
					@rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING!\n"

re:			fclean all

.PHONY: all clean fclean re
