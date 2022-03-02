NAME = test

all : $(NAME)

$(NAME) : test.cpp
	@clear
	@c++ -Wall -Wextra -Werror -std=c++98 test.cpp -o $(NAME)

clean:
	@ rm -rf *.gch
	@ rm -rf *.dSYM
	@rm -rf $(NAME)

fclean : clean

re: fclean all