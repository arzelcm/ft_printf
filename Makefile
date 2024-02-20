# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 13:52:40 by arcanava          #+#    #+#              #
#    Updated: 2024/02/15 21:40:05 by arcanava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

#----COLORS----#
DEF_COLOR = \033[1;39m
WHITE_BOLD = \033[1m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PINK = \033[1;35m
CIAN = \033[1;36m

#----COMPILER----#
CC = cc
CCFLAGS = -Wall -Werror -Wextra

#----ARCHIVER----#
AR = ar
RCS = rcs

#----LIBFT----#
LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a

#----DIRS----#
BIN_DIR = bin/
SRCS_DIR = src/
INC_DIR = inc/
BONUS_SRCS_DIR = src_bonus/
BONUS_INC_DIR = inc_bonus/

#----MANDATORY----#
SRCS =	ft_printf.c \
		basic_handle_helper.c \
		complex_handle_helper.c
OBJS = $(SRCS:%.c=%.o)
DEPS = $(OBJS:%.o=%.d)
 
#----BONUS----#
BSRCS = ft_printf_bonus.c \
		basic_parses_bonus.c \
		complex_parses_bonus.c \
		basic_padding_helper_bonus.c \
		complex_padding_helper_bonus.c \
		format_helper_bonus.c \
		flags_utils_bonus.c \
		number_utils_bonus.c
BOBJS = $(BSRCS:%.c=%.o)
BDEPS = $(BOBJS:%.o=%.d)
ifdef BONUS
	INC_DIR = $(BONUS_INC_DIR)
	SRCS_DIR = $(BONUS_SRCS_DIR)
endif

#----RULES----#
all:
	@$(MAKE) --no-print-directory make_libft
	@$(MAKE) --no-print-directory $(NAME)

ifndef BONUS
$(NAME): $(addprefix $(BIN_DIR), $(OBJS))
	@rm -rf $(addprefix $(BIN_DIR), $(BOBJS)) $(addprefix $(BIN_DIR), $(BDEPS))
	@echo "$(BLUE)\nLinking objects and creating static library...$(DEF_COLOR)"
	@cp $(LIBFT_LIB) $(NAME)
	@$(AR) $(RCS) $(NAME) $(addprefix $(BIN_DIR), $(OBJS))
	@echo "$(GREEN)[✓] PRINTF CREATED!!!$(DEF_COLOR)\n"
else
$(NAME): $(addprefix $(BIN_DIR), $(BOBJS))
	@rm -rf $(addprefix $(BIN_DIR), $(OBJS)) $(addprefix $(BIN_DIR), $(DEPS))
	@echo "$(BLUE)\nLinking objects and creating static library...$(DEF_COLOR)"
	@cp $(LIBFT_LIB) $(NAME)
	@$(AR) $(RCS) $(NAME) $(addprefix $(BIN_DIR), $(BOBJS))
	@echo "$(GREEN)[✓] PRINTF BONUS CREATED!!!$(DEF_COLOR)\n"
endif

$(BIN_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@echo "$(CIAN)Compiling object for $(PINK)$<$(DEF_COLOR)"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CCFLAGS) -I $(INC_DIR) -MMD -g -c $< -o $@
	@echo "$(GREEN)[✓] Object compiled!!!$(DEF_COLOR)"

clean: libft_clean
	@rm -rf $(BIN_DIR)
	@echo "$(YELLOW)bin/ is now clean!!!$(DEF_COLOR)\n"

fclean: clean libft_fclean mainclean
	@rm -f $(NAME)
	@echo "$(YELLOW)Everything clean!!!$(DEF_COLOR)\n"

re: fclean all

bonus: 
	@$(MAKE) --no-print-directory BONUS=1

bonusre: fclean bonus

make_libft:
	@echo "$(CIAN)Compiling $(PINK)libft.a$(CIAN)...$(DEF_COLOR)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) bonus
	@echo "$(GREEN)[✓] All done for $(PINK)libft.a$(GREEN)!!!$(DEF_COLOR)\n"

libft_clean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)bin/ clean for $(PINK)libft.a$(YELLOW)!!!$(DEF_COLOR)\n"

libft_fclean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "$(YELLOW)Everything clean for $(PINK)libft.a$(YELLOW)!!!$(DEF_COLOR)\n"

norme:
	@echo "$(YELLOW)\n------------------------\nChecking norme errors...\n------------------------\n$(DEF_COLOR)"
	@-norminette $(INC_DIR) $(BONUS_INC_DIR) $(SRCS_DIR) $(BONUS_SRCS_DIR)

compmain: bonus
	@echo "\n$(YELLOW)COMPILING MAIN FOR TESTING..."
	@$(CC) $(CCFLAGS) -Wno-format main.c $(NAME) -g -o main

main: compmain
	@echo "$(GREEN)\n------------\nMain result:\n------------\n$(DEF_COLOR)"
	@./main
m: main

n: norme

nm: norme main

mn: nm

leaks: compmain
	@echo "$(YELLOW)\n------------------------\nChecking leaks atExit...\n------------------------\n$(DEF_COLOR)"
	@-leaks -quiet -fullContent -atExit -- ./main

mainclean:
	@rm -f main

test: norme leaks

t: test

.PHONY: all clean fclean re bonus bonusre make_libft libft_clean libft_fclean norme main m n nm mn leaks compmain mainclean test t

-include $(addprefix $(BIN_DIR), $(DEPS))

-include $(addprefix $(BIN_DIR), $(BDEPS))
