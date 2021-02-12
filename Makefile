NAME = cub3D
CC = gcc
CFLAGS = -I. -Wall -Wextra -Werror
SRCS =\
	./sources/cub3d.c \
	./sources/cub3d_calc.c \
	./sources/cub3d_calc_wall.c \
	./sources/cub3d_calc_sprite.c \
	./sources/cub3d_draw.c \
	./sources/cub3d_key.c \
	./sources/cub3d_init.c \
	./sources/cub3d_write_bmp.c \
	./sources/etc.c \
	./sources/cubfile_check/check_map_closed.c \
	./sources/cubfile_check/check_map_char.c \
	./sources/cubfile_check/file_error_check.c \
	./sources/cubfile_check/fetch_each_line.c \
	./sources/cubfile_check/check_identify_rfc.c \
	./sources/cubfile_check/check_identify_texture.c \
	./sources/cubfile_check/get_next_line.c \
	./sources/cubfile_check/free.c
INCS = \
	./include/cub3d.h \
	./include/key_macos.h \
	./include/mlx.h \
	./include/libft.h \
	./include/bitmap.h
OBJS = $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(MAKE) -C ./sources/libft
	$(CC) $(CFLAGS) -o $(NAME) -L. -L./sources/libft $(OBJS) -lmlx -lft -I./include -lXext -lX11 -lm 

all: $(NAME)

clean:
	rm -f *.o
	rm -f */*.o
	rm -f */*/*.o

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./sources/libft

re: fclean all

.PHONY: all clean fclean re .c.o
