##
## EPITECH PROJECT, 2026
## makefile
## File description:
## root makefile
##

CC = clang++

MAIN = src/Main.cpp

SRC = 	$(addprefix src/, 						\
			Interstonar.cpp						\
			Vector3D.cpp						\
			$(addprefix Parsing/, 				\
				Parsing.cpp						\
				ParseConfigFile.cpp				\
				ParseConfigFileCommands.cpp		\
				ParseConfigFileTypes.cpp		\
			)									\
			$(addprefix Astre/, 				\
				Astre.cpp						\
				TypeBox.cpp						\
				TypeCylinder.cpp				\
				TypeSphere.cpp					\
				TypeTorus.cpp					\
			)									\
    	)

OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

TESTS = tests_run

CXXFLAGS = -Wall -Wextra -std=c++20

CPPFLAGS = -iquote include -iquote include/Astre

NAME = interstonar

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) --std=c++20 $(OBJ) $(CPPFLAGS)

debug: CFLAGS += -g
debug: fclean $(OBJ) $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

# $(TESTS): LDFLAGS += --coverage -lcriterion
# $(TESTS):
# 	$(CC) -o $(TESTS) $(SRC) $(PATH_UNI) \
# 		$(LDLIBS) $(CPPFLAGS) $(LDFLAGS)
# 	./$(TESTS)

# uni_clean:
# 	$(RM) $(TESTS)*

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) *.html coverage coverage.css
	$(RM) $(SERVER_NAME) $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
