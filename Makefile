NAME        = ft_conatiners
SRCDIR      = ./srcs
SRCS        = $(shell find $(SRCDIR) -name "ft.cpp" -type f | xargs)
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
