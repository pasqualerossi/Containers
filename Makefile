NAME = ft_containers

SRC = tests/containers/vector_test.cpp \
	  tests/containers/stack_test.cpp \
	  tests/containers/map_test.cpp \
	  main.cpp

OBJ = $(SRC:.cpp=.o)

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) main.o

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) vector stack map

re: fclean all

vector: $(OBJ)
	@$(CC) $(CFLAGS) -o vector tests/containers/vector_test.o

stack: $(OBJ)
	@$(CC) $(CFLAGS) -o stack tests/containers/stack_test.o

map: $(OBJ)
	@$(CC) $(CFLAGS) -o map tests/containers/map_test.o

.PHONY: all clean fclean re