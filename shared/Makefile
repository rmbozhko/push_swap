NAME = libsh.a

CC = gcc

SRC = sh_add_fts.c sh_instrs_def.c sh_args_validating.c sh_instrs_handle.c

OBJ = $(SRC:.c=.o)
DEBUG = #-DDEBUG
CFLAGS = -c $(DEBUG)#-Wall -Wextra -Werror
HEADER = shared.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[0;36m$(NAME) is compiled\033[0m"

%.o : %.c
	@$(CC) $(CFLAGS) $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
