NAME = map

all : $(NAME)

$(NAME) : main.cpp
	@clear
	@c++ -Wall -Wextra -Werror -std=c++98 main.cpp -o $(NAME)

clean:
	@ rm -rf *.gch
	@ rm -rf *.dSYM
	@rm -rf $(NAME)

fclean : clean

re: fclean all