# Variables
NAME            = so_long
FT_PRINTF_DIR   = ./ft_printf
FT_PRINTF_LIB   = $(FT_PRINTF_DIR)/libftprintf.a

# Se añade el archivo utils.c, que contendría las definiciones de pre_save_imgs, print_moves, error_moves y error_item.
SOURCES         = so_long.c read_map.c loop_hook.c close_window.c check_map.c draw_map.c ft_free.c errors.c pre_save_imgs.c
GNL_SOURCES     = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

OBJECTS         = $(SOURCES:.c=.o)
GNL_OBJECTS     = $(GNL_SOURCES:.c=.o)

# Herramientas
CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g3
RM              = rm -rf

# MiniLibX
MLX_DIR         = ./minilibx-linux
MLX             = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS       = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Colores
GREEN           = \033[1;32m
RED             = \033[1;31m
YELLOW          = \033[1;33m
BLUE            = \033[1;34m
CYAN            = \033[1;36m
RESET           = \033[0m
PURPLE          = \033[1;35m

# Reglas
all: banner $(NAME)

$(NAME): $(OBJECTS) $(GNL_OBJECTS) $(FT_PRINTF_LIB) $(MLX)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $(NAME) >/dev/null 2>&1
	@echo "$(GREEN)✔ $(NAME) compiled successfully!$(RESET)"

$(MLX):
	@echo "$(CYAN)Building MiniLibX...$(RESET)"
	@make -C $(MLX_DIR) >/dev/null 2>&1

$(FT_PRINTF_LIB):
	@echo "$(CYAN)Building ft_printf...$(RESET)"
	@make -C $(FT_PRINTF_DIR) >/dev/null 2>&1

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -Iincludes -c $< -o $@ >/dev/null 2>&1

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJECTS) $(GNL_OBJECTS) >/dev/null 2>&1
	@echo "$(RED)Cleaning MiniLibX...$(RESET)"
	@make -C $(MLX_DIR) clean >/dev/null 2>&1
	@echo "$(RED)Cleaning ft_printf...$(RESET)"
	@make -C $(FT_PRINTF_DIR) clean >/dev/null 2>&1

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME) >/dev/null 2>&1
	@echo "$(RED)Cleaning MiniLibX...$(RESET)"
	@make -C $(MLX_DIR) clean >/dev/null 2>&1  # Cambiar fclean a clean
	@echo "$(RED)Cleaning ft_printf...$(RESET)"
	@make -C $(FT_PRINTF_DIR) fclean >/dev/null 2>&1

re: fclean all

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