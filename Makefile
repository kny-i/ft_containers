name = ft_containers

CXX = g++

srcs = $(shell find ./srcs -type f -name *.cpp )

objs = $(srcs:%.cpp=objs/%.o)
objs = $(srcs:%.cpp=objs/%.d)

objs_dir = ./objs/
deps_dir = ./deps/
srcs_dit = ./srcs/

objs = $(addprefix $(objs_dir), $(objs))
srcs = $(addprefix $(srcs_dir), $(srcs))

CXXFLAGS += -std=++98

deps_flags = -MMD -MP

$(name):$(objs)
	$(CXX) $(CXXFLAGS) $(objs) -o $@

$(objs):$(srcs) $(objs_dir) $(deps_dir)
	$(CXX) $(CXXFLAGS) -Iincs
