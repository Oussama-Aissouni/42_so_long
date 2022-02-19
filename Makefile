CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
CFILES = so_long.c move_character.c so_long_utils.c get_next_line.c get_next_line_utils.c

all :
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(CFILES) -o so_long
