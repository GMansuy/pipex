
# VARIABLES

NAME		= pipex
NAME_BONUS	= pipex_bonus

LIB_DIR		= libft
LIB			= libft/libft.a

SRC_DIR		= src/
OBJ_DIR		= obj/
BONUS_DIR	= src_bonus/

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -I./srcs/includes -MMD -MP

RM			= rm -rf
AR			= ar rcs

# SOURCES
SRC_FILES	=	main child pipes get_files get_cmd free error init 
C_FILES		=	$(addsuffix .c, $(SRC_FILES))
SRCS 		=	$(addprefix $(SRC_DIR), $(C_FILES))
OBJS 		=	$(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))
DEPS		=	$(OBJS:.o=.d)

SRC_FILES_BONUS	=	main child pipes get_files get_cmd free heredoc error init 
C_BONUS			=	$(addsuffix _bonus.c, $(SRC_FILES_BONUS))
SRCS_BONUS 		=	$(addprefix $(BONUS_DIR), $(C_BONUS))
OBJS_BONUS 		=	$(addprefix $(OBJ_DIR), $(C_BONUS:.c=.o))
DEPS_BONUS		=	$(OBJS_BONUS:.o=.d)


# 	MANDATORY
all: 		obj $(NAME)
			

$(NAME):	$(LIB) $(OBJS)
			$(CC) $(CFLAGS) $^ -o $@ $(LIB)
			@echo "$(RED)$(NAME) compiled !$(CYAN)"

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.c 
			$(CC) $(CFLAGS) -c -o $@ $< 
			@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)...	$(RED)[Done]$(NOC)"

#	BONUS
bonus:		obj $(NAME_BONUS)

$(NAME_BONUS): $(LIB) $(OBJS_BONUS)
			$(CC) $(CFLAGS) $^ -o $(NAME_BONUS) $(LIB)
			@echo "$(RED)$(NAME_BONUS) BONUS compiled !$(CYAN)"

$(OBJ_DIR)%.o: 	$(BONUS_DIR)%.c 
			$(CC) $(CFLAGS) -c -o $@ $<
			@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)...	$(RED)[Done]$(NOC)"

$(LIB):
			@echo "$(MAGENTA)Creating libft files...$(DEF_COLOR)"
			make -C ./libft

# 	RULES
obj:
			@mkdir -p $(OBJ_DIR)

clean:
			@make clean -C $(LIB_DIR)
			@$(RM) $(OBJ_DIR) $(DEPS_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		
			@make clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(NAME_BONUS)
			@$(RM) -f $(LIB_DIR)/libft.a

re:			
			@make fclean
			@make all
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"

.PHONY: all clean fclean re	

.SILENT: lib

-include $(DEPS)

# COLORS

NOC = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
