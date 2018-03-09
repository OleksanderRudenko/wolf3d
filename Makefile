NAME = wolf3d

FILES = main image inites key_fucktion draw_f_c draw_wall menu sprite face draw_objects const_dest text deletes load_map
#add -Werror
FLAGS = -I Frameworks/SDL2.framework/Versions/A/Headers -F ~/Library/Frameworks/ -framework SDL2
FLAG2 = -Wall -Wextra
FLAG3 = -I Frameworks/SDL2_image.framework/Versions/A/Headers -F ~/Library/Frameworks/ -framework SDL2_image
FLAG4 = -I Frameworks/SDL2_ttf.framework/Versions/A/Headers -F ~/Library/Frameworks/ -framework SDL2_ttf
FLAG5 = -I Frameworks/SDL2_mixer.framework/Versions/A/Headers -F ~/Library/Frameworks/ -framework SDL2_mixer

SRC = $(addsuffix .c,$(FILES))
OBJ = $(addsuffix .o,$(FILES))
CC = gcc

all: $(NAME)

$(NAME): libft/libft.a 
	$(CC) $(FLAGS) $(FLAG2) $(FLAG3) $(FLAG4) $(FLAG5) libft/libft.a $(SRC) -o $(NAME)
	
libft/libft.a:
	make -C libft/

clean:
	rm -f $(OBJ)
	make clean -C ./libft/
	
fclean : clean
	rm -f $(NAME)
	make fclean -C ./libft/
	
re: fclean all
