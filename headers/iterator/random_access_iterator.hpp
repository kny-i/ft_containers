#ifndef RANDOM_ACCESS
#define RANDOM_ACCESS

#include "iterator.hpp"
#include <iterator>
namespace ft {
	template <typename T>
class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T> {
protected:
	T* current_;
public:
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type value_type;

	};
}
#endif