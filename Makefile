gcc -g draw_map.c draw_map2.c draw_txtur.c draw_wall.c ft_parser2.c ft_parses.c key_hook.c make_map_rectl.c make_map3.c maping.c new_bmp.c plr_luch.c
main.c cub3d.c cub3d2.c get_next_line.c get_next_line2.c  get_next_line.h  ft_struct.h ../libft11/*.c ../libft11/*.h  libmlx.dylib -framework OpenGL -framework Appkit

CC      =   gcc
NAME    =   cub3D
CFLAGS  =   -Wall -Wextra -Werror
LIB =   libft.a
MLX =   libmlx.a
SRC_PATH = ./minilibx_mms_20200219/
FLAGS    =   -framework OpenGL -framework AppKit
SRCS    := draw_map.c draw_map2.c draw_txtur.c draw_wall.c ft_parser2.c \
ft_parses.c key_hook.c make_map_rectl.c make_map3.c maping.c new_bmp.c plr_luch.c \
main.c cub3d.c cub3d2.c get_next_line.c get_next_line2.c
SOURCES = $(addprefix $(SRC_PATH), $(SRCS))
OBJS    =   $(SOURCES:.c=.o)

all:    $(NAME)
%.o:%.c
    gcc $(CFLAGS) -c $< -o $@
$(LIB):
    $(MAKE) -C libft
    @mv libft/libft.a .
$(MLX):
    $(MAKE) -C mlx
    @mv mlx/libmlx.a .
$(NAME): $(OBJS) $(LIB) $(MLX)
    gcc $(CFLAGS) -I libft $(OBJS) $(LIB) $(MLX) $(FLAGS) -o $(NAME)
bonus: $(NAME)
clean:
        rm -f $(OBJS)
        make clean -C libft
        make clean -C mlx
fclean: clean
        rm -f $(NAME)
        rm -f $(LIB)
        rm -f $(MLX)
re:     fclean all
.PHONY: all clean fclean re
