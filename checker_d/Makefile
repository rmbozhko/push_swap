NAME = checker
CC = gcc
SHARED = ../shared

SRC = checker.c checker_valid.c checker_bonus_output.c checker_instrs.c

OBJ = $(SRC:.c=.o)
DEBUG = #-DDEBUG
CFLAGS = -c -Wall -Wextra -Werror
HEADER = checker.h

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -L../libft -lft -L./${SHARED} -lsh -I$(HEADER) -o $(NAME)
	@echo "\033[0;35m${NAME} is compiled\033[0m"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
