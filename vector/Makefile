NAME = test

all : $(NAME)

$(NAME) : test.cpp
	@clear
	@c++ -g -Wall -Wextra -Werror -fsanitize=address test.cpp -o $(NAME)

clean:
	@ rm -rf *.gch
	@ rm -rf *.dSYM
	@rm -rf $(NAME)

fclean : clean

re: fclean all