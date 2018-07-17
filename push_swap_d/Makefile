NAME = push_swap
CC = gcc
SHARED = ../shared

SRC = push_swap.c ps_sorting.c ps_quicksort.c

OBJ = $(SRC:.c=.o)
DEBUG = -DDEBUG
CFLAGS = -c #-Wall -Wextra -Werror
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -L./../libft -lft -L./${SHARED} -lsh -I$(HEADER) -o $(NAME)
	@echo "\033[0;34m${NAME} is compiled\033[0m"

debug:
	@$(CC) $(SRC) $(DEBUG) -L./../libft -lft -L./${SHARED} -lsh -I$(HEADER) -o $(NAME)
	@echo "\033[0;34m${NAME} is compiled\033[0m"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
te: fclean debug