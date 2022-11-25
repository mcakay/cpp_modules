NAME = harl2_0

SRCS = main.cpp Harl.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	clang++ -Wall -Wextra -Werror -o $(NAME) $(OBJS)

%.o: %.cpp
	clang++ -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re