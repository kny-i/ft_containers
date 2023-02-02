#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
/* std::ptrdiff */
#include <cstddef>

namespace ft {
	template<class Category, class T, class	Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		/* Member types */
		typedef Category iterator_category;
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
	};
}

#endif
