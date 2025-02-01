NAME = so_long.a
SOURCES = $()
GNL_SOURCES = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

OBJECTS = $(SOURCES:.c=.o)
GNL_OBJECTS = $(SOURCES:.c=.o)                                                  

CC = cc                                                                      
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf                                                                     

all: $(NAME)

$(NAME) : $(OBJECTS) $(GNL_OBJECTS)
	 $(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


%.o: %.c
	gcc $(CFLAGS) -Imlx -Iincludes -c $< -o $@

clean:
		$(RM) $(OBJECTS) $(GNL_OBJECTS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re