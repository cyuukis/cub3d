CC		=   gcc
NAME    =   cub3D
CFLAGS  =   -Wall -Wextra -Werror
LIB =   libft.a
MLX =   libmlx.a
MLXFLAGS    =   -framework OpenGL -framework AppKit
HDRS    =   ./includ/
SRCS    := src/draw_map.c src/draw_map2.c src/draw_txtur.c src/draw_wall.c src/ft_parser2.c src/ft_parses.c src/key_hook.c src/make_map_rectl.c
src/make_map3.c src/maping.c src/new_bmp.c src/plr_luch.c src/main.c src/cub3d.c src/cub3d2.c src/get_next_line.c src/get_next_line2.c
OBJS    =   $(SRCS:.c=.o)
RM      =   rm -f
all:    $(NAME)
%.o:%.c
    gcc $(CFLAGS) -c $< -o $@
$(LIB):
    $(MAKE) bonus -C libft
    @mv libft/$(LIB) .
$(MLX):
    $(MAKE) -C mlx
    @mv mlx/$(MLX) .
$(NAME): $(OBJS) $(LIB) $(MLX)
    gcc $(CFLAGS) -I $(HDRS) -I libft $(OBJS) $(LIB) $(MLX) $(MLXFLAGS) -o $(NAME)
bonus: $(NAME)
clean:
        $(RM) $(OBJS)
        make clean -C libft
        make clean -C mlx
fclean: clean
        $(RM) $(NAME)
        rm -f $(LIB)
        rm -f $(MLX)
re:     fclean all
.PHONY: all clean fclean re
