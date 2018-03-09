NAME = wolf3d

FILES =	main \
		image \
		inites \
		key_fucktion \
		draw_f_c \
		draw_wall \
		menu \
		sprite \
		face \
		draw_objects \
		const_dest \
		text \
		deletes \
		load_map \
		errors

#add-Werror
SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
OBJ_LIST = $(addsuffix .o, $(FILES))
SPEED = -O3

FLAGS = -Wall -Wextra
INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks/
FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer

HEADERS = -I./includes -I./libft/

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	@gcc -o $(NAME) $(FLAG) $(SPEED) $(OBJ) $(FRAMEWORKS) libft/libft.a
	@echo "\033[1;32m 🌈  $(NAME) \033[1;0m\033[32m created.\033[0m"
libft/libft.a:
	@make -C ./libft/
obj/%.o: src/%.c
	@gcc -o $@ $(FLAG2) $(HEADERS) $(INCLUDES) -c $^
clean:
	@rm -f $(OBJ)
	@make clean -C ./libft/
	@echo "\032[31m[ ✔ ] Objects files have been destroyed \033[91m$(OBJ_LIST)"

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ)
	@make fclean -C ./libft/
	@echo "\033[22;35m🔥  Objects files have been destroyed \033[91m$(OBJ_LIST)"
	@echo "\033[1;31m$(NAME) \033[22;35m destroyed."
re: fclean all
