NAME			=	so_long

source			=	main.c \
					get_next_line.c \
					get_next_line_utils.c \
					create_matrix.c \
					key_events.c \
					load_images.c \
					mlx_utils.c \
					put_images.c \
					check_input.c \
					check_norms.c

HEAD			=	include/so_long.h

# LIBFT			=	libft/libft.a

OBJS			=	${addprefix source/,${source:.c=.o}}

MLX_FLAGS		=	-lmlx -framework OpenGL -framework AppKit -lm

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -g -I $(HEAD)

.c.o			:
					${CC} ${CFLAGS}  -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS} ${LIBFT} ${HEAD}
					make -C mlx
					${CC} ${CFLAGS} ${LD_FLAGS} ${MLX_FLAGS} ${OBJS} -o ${NAME} 
					# ${CC} ${CFLAGS} ${LD_FLAGS} ${MLX_FLAGS} ${OBJS} -o ${NAME} $(LIBFT) 


# $(LIBFT)		:
# 					make -C ./libft

all				:	${NAME}


clean			:
					make clean -C mlx
					# make clean -C libft
					@rm -rf ${OBJS}

fclean			:	clean
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re