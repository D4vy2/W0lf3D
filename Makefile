NAME = wolf3d

CC = gcc
LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_DIR = libft
MLX_DIR = minilibx_macos
SRC_DIR = src/
OBJ_DIR = obj/

SRC = main.c ft_open_file.c read_map.c ft_check_ret.c \
      controls.c calcul.c draw.c check_error.c color_hook.c \
      calcul_map_max.c move.c

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

DEL = rm -rf

INCLUDE = minilibx_macos/
LIBRARY = minilibx_macos/

FLAG = -lmlx

FRAMEWORK = -framework OpenGL -framework Appkit

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "compiling $<"
	@mkdir -p $(@D)
	@$(CC) -o $@ -c $<

$(NAME): $(OBJ)
	@(cd $(LIBFT_DIR) && $(MAKE))
	@(cd $(MLX_DIR) && $(MAKE))
	@$(CC) -o $(NAME) -I $(INCLUDE) -L $(LIBRARY) $(FLAG) $(FRAMEWORK) $(OBJ) $(LIBFT) -O3
	@echo
	@echo "      --> $(NAME) created."
	@echo

clean:
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	@(cd $(MLX_DIR) && $(MAKE) $@)
	@$(DEL) $(OBJ)
	@echo 
	@echo " clean -> .o deleted."
	@echo 

fclean: 
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	@(cd $(MLX_DIR) && $(MAKE) $@)
	@$(DEL) $(OBJ) $(NAME)
	@echo
	@echo "      --> $(NAME) deleted."
	@echo

re: fclean all
	@echo
	@echo "re -> $(NAME) reloaded."
	@echo

.PHONY: clean fclean all re
