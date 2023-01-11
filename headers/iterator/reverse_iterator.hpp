#pragma once

#include <iterator.hpp>

namespace ft {
	template <class Iter>
	class reverse_iterator
			: public iterator<typename ft::iterator_traits<Iter>::iterator_category,
					typename ft::iterator_traits<Iter>::value_type,
					typename ft::iterator_traits<Iter>::difference_type,
					typename ft::iterator_traits<Iter>::pointer,

					typename ft::iterator_traits<Iter>::reference> {
	private:
		typedef ft::iterator_traits<Iter> traits_type;
		/* Member type */
	public:
		typedef Iter iterator_type;
		typedef typename traits_type::iterator_category iterator_category;
		typedef typename traits_type::value_type value_type;
		typedef typename traits_type::difference_type difference_type;
		typedef typename traits_type::pointer pointer;
		typedef typename traits_type::reference reference;
		/* member functions */
		reverse_iterator() : current_() {}
		reverse_iterator(iterator_type itr_type) : current_(itr_type) {};
		template<class U>
		reverse_iterator(const reverse_iterator<U> &rhs) :current_(rhs.base()) {};
		template<class U>
		reverse_iterator &operator=(reverse_iterator<U> const &rhs) {
			if (current_ != rhs) {
				current_ = rhs.base();
			}
			return *this;
		}
		//base is getter for (Iter) current_.
		iterator_type base() const {
			return current_;
		}
		reference operator*() const {
			Iter it = current_;
			--it;
			return *it;
		}
		pointer operator->() const {
			return &(operator*());
		}
		reference operator[](difference_type diff) const {
			return *(*this + diff);
		}
		reverse_iterator &operator++() {
			--current_;
			return *this;
		}
		reverse_iterator operator++(int) {
			reverse_iterator tmp(*this);
			--current_;
			return tmp;
		}

		reverse_iterator operator--(int) {
			reverse_iterator tmp(*this);
			++current_;
			return tmp;
		}
		reverse_iterator &operator--() {
			++current_;
			return *this;
		}
		reverse_iterator operator+(difference_type diff) const {
			return reverse_iterator(current_ - diff);
		}
		reverse_iterator &operator+=(difference_type diff) const {
			current_ -= diff;
			return *this;
		}
		reverse_iterator &operator-=(difference_type diff) const {
			current_ += diff;
			return *this;
		}
	protected:
		/* member objects */
		Iter current_;
	};
	/* non-member functions */
	template <class Iterator1, class Iterator2>
	bool operator==(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
		return lhs.base() == rhs.base();
	}
	template <class Iterator1, class Iterator2>
	bool operator!=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
		return lhs.base() != rhs.base();
	}
	template <class Iterator1, class Iterator2>
	bool operator<(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
		return lhs.base() < rhs.base();
	}
	template <class Iterator1, class Iterator2>
	bool operator>(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
		return lhs.base() > rhs.base();
	}
	template <class Iterator1, class Iterator2>
	bool operator<=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
		return lhs.base() <= rhs.base();
	}
	template <class Iterator1, class Iterator2>
	bool operator>=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
		return lhs.base() >= rhs.base();
	}
	template <class Iter>
	reverse_iterator<Iter> operator+(
			typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it) {
		return reverse_iterator<Iter>(it.base() - n);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return rhs.base() - lhs.base();
	}
}


