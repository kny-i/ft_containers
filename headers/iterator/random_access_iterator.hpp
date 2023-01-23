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

	random_access_iterator(const random_access_iterator &other) : current_(other.current_) {}

	random_access_iterator &operator=(const random_access_iterator &other) {
		if (this == &other) return (*this);
		current_ = other.current_;
		return (*this);
	}
	// destructor
	~random_access_iterator() {}

	pointer base() const { return current_; }
	reference operator*() const { return *current_; }
	pointer operator->() const { return &(operator*()); }
	reference operator[](difference_type n) const { return *(*this + n); }
	random_access_iterator& operator++() {
		++current_;
		return *this;
	}
	random_access_iterator& operator--() {
		--current_;
		return *this;
	}
	random_access_iterator operator++(int) {
		random_access_iterator tmp = *this;
		++current_;
		return tmp;
	}
	random_access_iterator operator--(int) {
		random_access_iterator tmp = *this;
		--current_;
		return tmp;
	}
	random_access_iterator operator+(difference_type n) const {
		return random_access_iterator(current_ + n);
	}
	random_access_iterator operator-(difference_type n) const {
		return random_access_iterator(current_ - n);
	}
	random_access_iterator& operator+=(difference_type n) {
		current_ += n;
		return *this;
	}
	random_access_iterator& operator-=(difference_type n) {
		current_ -= n;
		return *this;
	}

	operator random_access_iterator<const T>() const {
		return (random_access_iterator<const T>(current_));
	}

	};
	// Non-member functions
	template <class Iterator1, class Iterator2>
	bool operator==(const ft::random_access_iterator<Iterator1>& lhs,
					const ft::random_access_iterator<Iterator2>& rhs) {
		return lhs.base() == rhs.base();
	}
	template <class Iterator1, class Iterator2>
	bool operator!=(const ft::random_access_iterator<Iterator1>& lhs,
					const ft::random_access_iterator<Iterator2>& rhs) {
		return !(lhs == rhs);
	}
	template <class Iterator1, class Iterator2>
	bool operator<(const ft::random_access_iterator<Iterator1>& lhs,
				   const ft::random_access_iterator<Iterator2>& rhs) {
		return lhs.base() < rhs.base();
	}
	template <class Iterator1, class Iterator2>
	bool operator<(const ft::random_access_iterator<Iterator1>& lhs,
				   const std::allocator<Iterator2>& rhs) {
		return lhs.base() < rhs.base();
	}
	template <class Iterator1, class Iterator2>
	bool operator<=(const ft::random_access_iterator<Iterator1>& lhs,
					const ft::random_access_iterator<Iterator2>& rhs) {
		return !(rhs < lhs);
	}
	template <class Iterator1, class Iterator2>
	bool operator>(const ft::random_access_iterator<Iterator1>& lhs,
				   const ft::random_access_iterator<Iterator2>& rhs) {
		return rhs < lhs;
	}
	template <class Iterator1, class Iterator2>
	bool operator>=(const ft::random_access_iterator<Iterator1>& lhs,
					const ft::random_access_iterator<Iterator2>& rhs) {
		return !(lhs < rhs);
	}
	template <class Iter>
	ft::random_access_iterator<Iter> operator+(
			typename ft::random_access_iterator<Iter>::difference_type n,
			const ft::random_access_iterator<Iter>& it) {
		return ft::random_access_iterator<Iter>(it.base() + n);
	}
	template <class Iterator>
	typename ft::random_access_iterator<Iterator>::difference_type operator-(
			const ft::random_access_iterator<Iterator>& lhs,
			const ft::random_access_iterator<Iterator>& rhs) {
		return lhs.base() - rhs.base();
	}

}

#endif