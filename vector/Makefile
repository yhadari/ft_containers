NAME = test

all : $(NAME)

$(NAME) : *.cpp
	@clear
	@c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o $(NAME)

clean:
	@ rm -rf *.gch
	@rm -rf $(NAME)

fclean : clean

re: fclean all