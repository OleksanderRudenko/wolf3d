NAME = wolf

FILES = main image inites
#add -Werror
FLAGS = -I ~/Library/Frameworks/SDL2.framework/Versions/A/Headers -F ~/Library/Frameworks/ -framework SDL2 
FLAG2 = -Wall -Wextra

SRC = $(addsuffix .c,$(FILES))
OBJ = $(addsuffix .o,$(FILES))
CC = gcc

all: $(NAME)

$(NAME): libft/libft.a 
	$(CC) $(FLAGS) $(FLAG2) libft/libft.a $(SRC) -o $(NAME)

libft/libft.a:
	make -C libft/

clean:
	rm -f $(OBJ)
	make clean -C ./libft/
	
fclean : clean
	rm -f $(NAME)
	make fclean -C ./libft/
	
re: fclean all
