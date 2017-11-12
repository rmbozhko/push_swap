NAME = checker
CC = gcc

SRC = get_next_line.c checker.c checker_valid.c checker_additional.c checker_bonus.c checker_instrs.c checker_instrs_additional.c

OBJ = $(SRC:.c=.o)
DEBUG = #-DDEBUG
CFLAGS = -c $(DEBUG)#-Wall -Wextra -Werror
HEADER = checker.h

all: $(NAME)

$(NAME): $(OBJ)
	#@make -C libft 
	@$(CC) $(OBJ) -L./libft -lft -I$(HEADER) -o $(NAME)
	@echo "\033[0;37mChecker is compiled\033[0m"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) $<

clean:
	#@make clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	#@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all
