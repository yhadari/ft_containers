NAME = test

all : $(NAME)

$(NAME) : *.cpp
	@clear
	@c++ -Wall -Wextra -Werror *.cpp -o $(NAME)

clean:
	@ rm -rf *.gch
	@rm -rf $(NAME)

fclean : clean

re: fclean all