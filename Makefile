NAME        = ft_conatiners
SRCDIR      = ./srcs
SRCS        = $(shell find $(SRCDIR) -name "main.cpp" -type f | xargs)
OBJS        = $(SRCS:.cpp=.o)
DEPENDS     = $(OBJS:.o=.d)
CXX         = c++
headers = ./headers
iterator_headers = ./headers/iterator
utils = ./headers/utils
CXXFLAGS    = -std=c++98  -MMD -MP -I$(headers) -I$(iterator_headers) -I$(utils) -Wall -Wextra -Werror -pedantic

.PHONY: all
all: $(NAME)

-include $(DEPENDS)

$(NAME): $(OBJS)
	$(CXX)	$(CXXFLAGS) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	rm -rf $(OBJS) $(DEPENDS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -fr output


.PHONY: re
re: fclean all

.PHONY: debug
debug: CXXFLAGS += -fsanitize=address -g3
debug: re

.PHONY: run
run: all
	 @./$(NAME)


.PHONY: leaks
leaks:  all
	leaks -q --atExit -- ./$(NAME)


.PHONY: test
test: ./srcs/ft.cpp ./srcs/std.cpp
	$(CXX) $(CXXFLAGS) srcs/ft.cpp -o srcs/ft
	$(CXX) $(CXXFLAGS) srcs/std.cpp -o srcs/std
	./srcs/ft
	./srcs/std
	echo "\n"
	diff output/vec_mine output/vec_std
	@echo $$?
	diff output/map_mine output/map_std
	@echo $$?
	diff output/stack_mine output/stack_std
	@echo $$?
	@echo "->If there are there 0, Test has done Without problem."

.PHONY: test_clean
test_clean:
	rm -rf ./srcs/ft.d
	rm -rf ./srcs/std.d
	rm -rf ./srcs/ft.o
	rm -rf ./srcs/std.o

.PHONY: test_fclean
test_fclean: test_clean
	rm -rf ./srcs/ft
	rm -rf ./srcs/std
	rm -rf ./output

