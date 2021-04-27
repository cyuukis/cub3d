gcc -g draw_map.c draw_map2.c draw_txtur.c draw_wall.c ft_parser2.c ft_parses.c key_hook.c make_map_rectl.c make_map3.c maping.c new_bmp.c plr_luch.c
main.c cub3d.c cub3d2.c get_next_line.c get_next_line2.c  get_next_line.h  ft_struct.h ../libft11/*.c ../libft11/*.h  libmlx.dylib -framework OpenGL -framework Appkit

CC      =   gcc
NAME    =   cub3D
CFLAGS  =   -Wall -Wextra -Werror
LIB =   libft.a
MLX =   libmlx.a
FLAGS    =   -framework OpenGL -framework AppKit
HDRS    =   /minilibx_mms_20200219/get_next_line.h /minilibx_mms_20200219/ft_struct.h
SRCS    := get_cub_settings_1.c get_cub_settings_2.c \
            get_map.c parse_map_1.c parse_map_2.c \
            render_cub.c render_wall.c render_sprites.c \
            take_screenshot.c create_bmp_file.c \
            cub3d_utils_1.c cub3d_utils_2.c \
            key_handler.c main.c
OBJS    =   $(SRCS:.c=.o)
RM      =   rm -f
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
    gcc $(CFLAGS) -I $(HDRS) -I libft $(OBJS) $(LIB) $(MLX) $(FLAGS) -o $(NAME)
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
