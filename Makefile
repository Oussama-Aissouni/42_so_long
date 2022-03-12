CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
CFILES = mandatory/so_long.c mandatory/move_character.c\
	mandatory/so_long_utils.c mandatory/get_next_line.c\
	mandatory/get_next_line_utils.c mandatory/map_checker.c\
	mandatory/map_parser.c mandatory/map_parser_utils.c mandatory/ft_printf.c\
	mandatory/map_checker_utils.c
CFILESBONUS = bonus/so_long.c bonus/move_character.c\
	bonus/so_long_utils.c bonus/get_next_line.c\
	bonus/get_next_line_utils.c bonus/map_checker.c\
	bonus/map_parser.c bonus/map_parser_utils.c\
	bonus/map_checker_utils.c bonus/animation.c bonus/ft_itoa.c
NAME = so_long
NAME_BONUS = so_long_bonus

all : $(NAME)

$(NAME) : $(CFILES)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(CFILES) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(CFILESBONUS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(CFILESBONUS) -o $(NAME_BONUS)

clean :
	@rm -f so_long

fclean : clean
	@rm -f $(NAME_BONUS)

re : clean all
