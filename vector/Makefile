NAME = test

all : $(NAME)

$(NAME) : *.cpp
	@clear
	@c++ -g -Wall -Wextra -Werror *.cpp -o $(NAME)

clean:
	@ rm -rf *.gch
	@ rm -rf *.dSYM
	@rm -rf $(NAME)

fclean : clean

re: fclean all