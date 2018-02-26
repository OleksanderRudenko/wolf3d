NAME = wolf3d

FILES = main image inites draw_wall draw_f_c

SRC = $(addsuffix .c,$(FILES))
OBJ = $(addsuffix .o,$(FILES))

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	clang -Wextra -Wall $(OBJ) -lm `sdl2-config --cflags --libs` libft/libft.a -O3 -o $(NAME)
	rm -f $(OBJ)

%.o: %.c
	clang -c -Wextra -Wall -o $@ $<

libft/libft.a:
	make -C libft/

clean:
	make -C libft/ clean
	rm -f $(OBJ)
	
fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)
	
re: fclean all
