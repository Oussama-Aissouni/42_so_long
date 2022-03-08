CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
CFILES = so_long.c move_character.c so_long_utils.c get_next_line.c \
get_next_line_utils.c map_checker.c	map_parser.c map_parser_utils.c
NAME = so_long

all : $(NAME)
	
$(NAME) :
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(CFILES) -o $(NAME)

clean :
	@rm $(NAME)

fclean : clean

re : clean all