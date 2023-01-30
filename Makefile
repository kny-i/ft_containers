NAME        = ft_conatiner
SRCDIR      = ./srcs
SRCS        = $(shell find $(SRCDIR) -name "*.cpp" -type f | xargs)
OBJS        = $(SRCS:.cpp=.o)
DEPENDS     = $(OBJS:.o=.d)
CXX         = c++
headers = ./headers
iterator_headers = ./headers/iterator
utils = ./headers/utils
CXXFLAGS    = -std=c++98  -MMD -MP -I$(headers) -I$(iterator_headers) -I$(utils) -fsanitize=address
.PHONY: all
all: $(NAME)

-include $(DEPENDS)

$(NAME): $(OBJS)
	$(CXX)	$(CXXFLAGS) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	rm $(OBJS) $(DEPENDS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f output

.PHONY: re
re: fclean all

.PHONY: debug
debug: CXXFLAGS += -g -fsanitize=integer -fsanitize=address -fsanitize=leak
debug: re

run: all
	@./ft_conatiner
