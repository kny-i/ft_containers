#ifndef RANDOM_ACCESS
#define RANDOM_ACCESS

#include "iterator.hpp"
#include <iterator>
namespace ft {
	template <typename T>
class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T> {
protected:
	T *current_;
public:
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type value_type;
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type difference_type;
	typedef T *pointer;
	typedef T &reference;

	random_access_iterator() : current_(NULL) {}

	random_access_iterator(pointer x) : current_(x) {}

	random_access_iterator(const random_access_iterator &other) : current_(other._current) {}

	random_access_iterator &operator=(const random_access_iterator &other) {
		if (this == &other) return (*this);
		current_ = other._current;
		return (*this);
	}
	// destructor
	~random_access_iterator() {}

	pointer base() const { return _current; }
	reference operator*() const { return *_current; }
	pointer operator->() const { return &(operator*()); }
	reference operator[](difference_type n) const { return *(*this + n); }
	random_access_iterator& operator++() {
		++_current;
		return *this;
	}
	random_access_iterator& operator--() {
		--_current;
		return *this;
	}
	random_access_iterator operator++(int) {
		random_access_iterator tmp = *this;
		++_current;
		return tmp;
	}
	random_access_iterator operator--(int) {
		random_access_iterator tmp = *this;
		--_current;
		return tmp;
	}
	random_access_iterator operator+(difference_type n) const {
		return random_access_iterator(_current + n);
	}
	random_access_iterator operator-(difference_type n) const {
		return random_access_iterator(_current - n);
	}
	random_access_iterator& operator+=(difference_type n) {
		_current += n;
		return *this;
	}
	random_access_iterator& operator-=(difference_type n) {
		_current -= n;
		return *this;
	}

	operator random_access_iterator<const T>() const {
		return (random_access_iterator<const T>(_current));
	}
	};
}

#endif