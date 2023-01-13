#ifndef STACK_HPP
#define STACK_HPP
#include <vector>


namespace ft {
	template <class T, typename Container = std::vector<T> >
	class stack {
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

		explicit stack(const container_type &)
	};

}

#endif