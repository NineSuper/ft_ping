# @Makefile by tde-los- (http://github.com/NineSuper)
UNAME_S := $(shell uname -s)

NAME = ft_ping

SRC_DIR = src
OBJ_DIR = obj
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

HEADER_DIR = include

SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = lib/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIB = $(LIBFT) $(PRINTF)

# HEADER_FILE = $(wildcard $(HEADER_DIR)/*.h) $(LIBFT_DIR)/libft.h $(PRINTF_DIR)/ft_printf.h
HEADER_FILE = $(wildcard $(HEADER_DIR)/*.h)

INC_SRCH_PATH = -I $(HEADER_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)

CC = gcc
FLAGS = -Wall -Werror -Wextra
#FLAGS =

ifeq ($(UNAME_S),Linux)		# Linux
    LFLAGS =
endif

ifeq ($(UNAME_S),Darwin)	# macOS
    LFLAGS = -L/usr/local/lib
endif

# ------------------------------ Couleurs ------------------------------

BOLD_RED		=		\033[1;31m

BOLD_PURPLE     =       \033[1;35m

BOLD_CYAN       =       \033[1;36m

BOLD_YELLOW     =       \033[1;33m

BOLD			=		\033[1m

NO_COLOR        =       \033[0m

# ------------------------------ Messages ------------------------------

HEADER_NAME		=		$(HEADER_TOP) $(HEADER_TOP_MID) $(HEADER_MID)$(HEADER_BOT)

HEADER_COMP     =       echo "\n👽 $(BOLD_PURPLE)$(NAME) $(NO_COLOR)$(BOLD)by $(BOLD_RED)tde-los-\n\n"

MLX_READY		=		echo "\n\n📥 $(BOLD)Compilation de la $(BOLD_YELLOW)Mlx$(NO_COLOR) $(BOLD)reussi !$(NO_COLOR)\n"

COMP_START      =       printf "\n\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)$(BOLD)Debut de compilation...\r$(NO_COLOR)"

EXE_READY       =       echo "\n🎮 $(BOLD)Compilation de $(BOLD_PURPLE)$(NAME)$(NO_COLOR) $(BOLD)reussi !$(NO_COLOR)\n"

CLEANED         =       echo "\n💧 $(BOLD_CYAN)Clean: $(NO_COLOR)$(BOLD)Suppression des fichiers objets$(NO_COLOR)\n"

FCLEANED        =       echo "\n🧼 $(BOLD_CYAN)Fclean: $(NO_COLOR)$(BOLD)Suppression des fichiers (binaire + objets + libs)$(NO_COLOR)\n"

NORM			= 		echo "\n📢 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme de tous les fichiers en .c !\n$(BOLD_PURPLE)"

NORM_LIB		= 		echo "\n📢 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme du dossier $(BOLD_CYAN)/libft $(BOLD_YELLOW)!\n$(BOLD_YELLOW)"

NORM_H			=		echo "\n📣 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme du .h\n$(BOLD_PURPLE)"

LIBFT_START		=		echo "\n📘 $(BOLD_PURPLE)Libft: $(NO_COLOR)$(BOLD)Compilation de la libft...\n$(NO_COLOR)"

PRINTF_START	=		echo "\n🖊️ $(BOLD_PURPLE)ft_printf: $(NO_COLOR)$(BOLD)Compilation de ft_printf...\n\n$(NO_COLOR)"

# ------------------------------ Regles ------------------------------
MAKEFLAGS += --silent

.DEFAULT_GOAL := all

TOTAL_FILES := $(words $(SRC))
COMPILED_FILES := 0

all: $(OBJ_DIR) $(NAME)
# all: $(NAME) norminette

comp_start:
	# @$(HEADER_COMP)
	@$(COMP_START)

# Compilation des librairies
$(LIBFT):
	$(LIBFT_START)
	@make -C $(LIBFT_DIR)

$(PRINTF):
	$(PRINTF_START)
	@make -C $(PRINTF_DIR)

# Compilation du projet après les libs
$(NAME): $(LIB) $(OBJ)
	$(comp_start)
	@$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(LIB)
	echo "\n"
	@$(EXE_READY)

# Nettoyage des fichiers objets
clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@rm -f $(OBJ)
	$(CLEANED)

# Nettoyage total (binaire + objets + libs)
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)
	$(FCLEANED)

# Recompile tout proprement
re: fclean all

# Vérifie la norme des fichiers .c/.h
norminette:
	$(NORM_LIB)
	norminette
	$(NORM)
	norminette $(SRC)
	$(NORM_H)
	norminette -R checkDefine $(HEADER_FILE)
	echo "\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)$(BOLD)Compilation des fichiers :$(BOLD_CYAN) %-33.33s $(BOLD_YELLOW)[%3d%%] \r$(NO_COLOR)" $? $(shell expr \( $(COMPILED_FILES) \) \* 100 / $(TOTAL_FILES))
	@$(CC) $(FLAGS) -c $(INC_SRCH_PATH) $< -o $@
	@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
	@printf "🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)$(BOLD)Compilation des fichiers :$(BOLD_CYAN) %-33.33s $(BOLD_YELLOW)[%3d%%] \r$(NO_COLOR)" $? $(shell expr \( $(COMPILED_FILES) \) \* 100 / $(TOTAL_FILES))
