
all:
	@make -C libft
	@make -C shared
	@make -C checker_d && cp checker_d/checker .
	@make -C push_swap_d && cp push_swap_d/push_swap .

clean:
	@make clean -C libft
	@make clean -C shared
	@make clean -C checker_d
	@make clean -C push_swap_d

fclean: clean
	@make fclean -C libft
	@make fclean -C shared
	@make fclean -C checker_d && rm -f checker 
	@make fclean -C push_swap_d && rm -f push_swap 

re: fclean all
