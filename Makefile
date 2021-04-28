CC		=	gcc
NAME	=	cub3D
CFLAGS	=	-Wall -Wextra -Werror
LIB =	libft.a
MLX =	libmlx.dylib

MLXDIR = ./mlx
LIBDIR = ./libft

MLXFLAGS	= -framework OpenGL -framework AppKit
HDRS	=	get_next_line.h \
			ft_struct.h

SRCS	:=	draw_map.c draw_map2.c draw_txtur.c draw_wall.c ft_parser2.c ft_parses.c key_hook.c make_map_rectl.c \
			make_map3.c maping.c new_bmp.c plr_luch.c cub3d.c cub3d2.c get_next_line.c get_next_line2.c \
			get_next_line_utils.c main.c
OBJS	=	$(SRCS:.c=.o)
RM		=	rm -f

all:	$(NAME)

$(LIB):
	$(MAKE) -j4 -C libft
	@cp libft/$(LIB) .

$(MLX):
	$(MAKE) -C mlx
	@cp mlx/$(MLX) .

%.o: %.c
	gcc	$(CFLAGS) -I $(LIBDIR) -I$(MLXDIR) -c $< -o $@

$(NAME): $(LIB) $(MLX) $(OBJS)
	gcc $(CFLAGS) -I. -I$(LIBDIR) -I$(MLXDIR) $(OBJS) $(LIB) $(MLX) $(MLXFLAGS) -o $(NAME)

bonus: $(NAME)
clean:
		$(RM) $(OBJS)
		make clean -C libft
		make clean -C mlx
fclean: clean
		$(RM) $(NAME)
		rm -f $(LIB)
		rm -f $(MLX)
re:		fclean all
.PHONY: all clean fclean re
