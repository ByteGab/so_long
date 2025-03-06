NAME = so_long
SOURCES = so_long.c read_map.c loop_hook.c close_window.c check_map.c
GNL_SOURCES = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

OBJECTS = $(SOURCES:.c=.o)
GNL_OBJECTS = $(GNL_SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

GREEN  = \033[1;32m
RED    = \033[1;31m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
CYAN   = \033[1;36m
RESET  = \033[0m
PURPLE = \033[1;35m

all: banner $(NAME)

$(NAME): $(OBJECTS) $(GNL_OBJECTS) $(MLX)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✔ $(NAME) compiled successfully!$(RESET)"

$(MLX):
	@echo "$(CYAN)Building MiniLibX...$(RESET)"
	make -C $(MLX_DIR)

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -Imlx -Iincludes -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	$(RM) $(OBJECTS) $(GNL_OBJECTS)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	$(RM) $(NAME)
	@echo "$(RED)Cleaning MiniLibX...$(RESET)"
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re

banner:
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀        ⣠⣦⠀⠀⠀"
	@echo "$(BLUE)⢀⡀⠀⠀⠀⠀⠀⠀⠀⣾⡇⠀⠀⠀⠀⣠⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⣽⣿⣧⠀⠀⠀"
	@echo "$(BLUE)⢿⣿⣷⣄⡀⠀⠀⠀⢠⣿⡇⠀⠀⢠⣾⣿⡏⠀⠀⠀⢀⣠⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⢋⣼⣛⣿⡿⠀⠀⠀"
	@echo "$(BLUE)⠈⢿⣿⣿⣿⣟⣲⣦⣿⡿⢷⡦⣴⣿⣿⡟⢀⣀⣤⣴⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⣠⠤⠄⠒⠒⠒⠤⣄⢀⡞⣤⡿⣓⣾⠟⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠈⠛⠿⣿⣿⣿⠏⠀⠈⠀⠈⢻⣿⣯⣭⣤⣿⣿⡿⠋⠀⠀⠀⠀⣀⠠⠔⠚⠁⠀⠀⠀⠀⠀⠀⠐⠚⢿⣿⠧⣙⣾⡏⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⣿⣿⡿⠀⠀⠀⠀⢀⣾⣿⣿⣹⡿⠿⠋⢀⡠⠤⠤⠔⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡈⢻⣿⡟⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⢻⣿⡇⠀⠠⠀⢀⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣿⠁⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⢸⣿⠁⠀⠀⠀⢰⣿⣿⣿⠿⣶⠢⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⡄⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⢈⡏⠀⠀⠀⢠⣼⣿⣿⡿⠘⠛⠛⢓⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⠀⠀⠀⠀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⡾⣆⣀⣠⣴⣿⣿⣿⠿⠁⠀⠩⠀⠈⢿⣦⣀⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⡿⠋⠁⠀⠀⠠⠀⠀⢀⢈⡙⡏⠉⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠻⠿⢻⠏⠀⠀⠀⠀⢀⠀⠃⡠⠘⠀⠙⢿⡆⠈⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢱⠀⠀⠀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⡜⠀⢰⠄⠀⠀⢸⣶⠚⠁⠀⠀⠀⠸⣧⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡆⠀⠀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠀⢰⠃⠀⠀⢦⠀⠀⢸⣟⠄⠀⠀⠀⠀⢰⠈⢳⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠒⠦⣢⣄⠀⠀⣇⠀⠀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠀⠘⣷⠄⢀⠈⠢⣄⢺⠿⠀⢀⡀⠀⢀⠘⣖⣾⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠁⠀⠀⠀⠘⢾⡆⠀⢨⢦⡀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⢸⡶⢤⡐⡄⠀⠹⣷⣤⣟⣳⣤⣦⡸⡍⠈⠀⢸⠀⠀⠀⠀⠀⠀⠀⣀⣶⡇⠀⠀⠀⠀⠀⠀⠀⢳⣰⣀⠑⢻⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⢰⡿⡧⣵⣈⠲⠤⣿⣿⠿⠿⠿⠿⢳⠿⠀⠘⣾⡀⠀⠀⢀⣀⢴⡞⣧⠘⡿⡄⠀⠀⠀⠀⠀⠀⠀⠹⡛⠀⠈⣇⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⣿⠋⠉⡟⠲⢼⣇⣀⣀⣤⣾⣿⠀⠀⠀⡟⠓⠋⠉⠉⠀⠀⣿⣿⡄⢠⡇⠀⠀⠀⠀⠀⠀⠀⠀⢣⡀⠀⢸⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⠀⠀⣿⠂⠐⠀⡸⠁⠀⠀⠈⠉⠁⠀⠈⣿⠀⠀⢰⡇⠀⠀⠀⠀⠀⠀⣿⠸⠁⢸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠈⠇⠀⠘⡄"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⠀⢠⡇⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⢠⡏⠀⠀⣼⠀⠀⠀⠀⠀⠀⣰⠋⠀⢀⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠿"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⠀⡞⠀⠀⢰⠃⠀⠀⠀⠀⠀⠀⠀⠀⣼⣇⠠⣀⣿⠀⠀⠀⠀⠀⢠⠇⠀⠀⡜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣷⢿⡇⠀⠀⠀⠀⢠⣾⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣆⣠"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⢺⡧⠀⢰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣟⣦⠸⡆⠀⠀⠀⣴⡟⠁⠀⣤⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⣿⠁⠀⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠿⠧⠀⡇⠀⠀⠀⣿⣿⣶⣾⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⢀⡇⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⢰⠣⢀⣧⠀⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⣼⡇⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⢁⡎⠀⢸⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⢠⣏⠁⠀⣾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠠⣿⣿⣀⣠⠼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⢸⣿⢢⣶⣾⠀⠀⠀⠀⠀⠀⠀⠐⠚⠚⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⢀⣈⣛⠚⡉⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀$(RESET)"