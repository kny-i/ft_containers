NAME        = ft_conatiner
SRCDIR      = ./srcs
SRCS        = $(shell find $(SRCDIR) -name "*.cpp" -type f | xargs)
OBJS        = $(SRCS:.cpp=.o)
DEPENDS     = $(OBJS:.o=.d)
CXX         = c++
headers = ./headers
iterator_headers = ./headers/iterator
CXXFLAGS    = -std=c++17 -pedantic-errors -MMD -MP -I$(headers) -I$(iterator_headers)
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

.PHONY: re
re: fclean all

.PHONY: debug
debug: CXXFLAGS += -g -fsanitize=integer -fsanitize=address -fsanitize=leak
debug: re
