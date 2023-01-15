#ifndef VECTOR
#define VECTOR


#include <iostream>
#include <memory>
#include <iterator>
#include <reverse_iterator.hpp>
#include <random_access_iterator.hpp>

namespace ft {
	template<class T, class Allocator = std::allocator<T> >
	class vector {
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef typename ft::random_access_iterator<value_type> iterator;
		typedef typename ft::random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<value_type> reverse_iterator;
		typedef ft::reverse_iterator<const value_type> const_reverse_iterator;
		/* empty constructor */
		vector() : first_pointer_(NULL), last_pointer_(NULL), storage_last_(NULL), alloc_(allocator_type()) {}

		/*  */
		explicit vector(const Allocator &alloc) : first_pointer_(NULL), last_pointer_(NULL), storage_last_(NULL), alloc_(alloc) {}

		/*  */
		explicit vector(size_type count, const T &val = T(), const Allocator &alloc = Allocator())
		: first_pointer_(NULL), last_pointer_(NULL), storage_last_(NULL), alloc_(alloc) {
			resize(count, val);
		}

		/* range constructor */
//		template <typename InputIt>
//		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(),
//		typename ft::enable_if<!ft::is_integral<InputIt>::value,InputIt>::type* = NULL)
//		: first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(alloc) {
//			reserve(ft::distance(first, last));
//			for (InputIt i = first; i != last; ++i) {
//				push_back(*i);
//			}
		/* copy constructor */
//		vector(vector const& other)
//		: first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(other.alloc_) {
//			reserve(other.size());
//
//			pointer dest = first_;
//			for (const_iterator src = other.begin(), last = other.end(); src != last;
//				 ++dest, ++src) {
//				construct(dest, *src);
//			}
//			last_ = first_ + other.size();
//		}
		/* operator overload */
//		vector &operator=(const vector &other) {
//			if (this != &other) {
//				clear();
//				resize(other.size());
//				for (size_type i = 0; i < other.size(); i++) {
//					first_pointer_[i] = other[i];
//				}
//			}
//			return *this;
//		}
		/* destructor */
		~vector() {
			clear();
			deallocate();
			;
		}
//		void assign(size_type count, const T& value) {
//			clear();
//			reserve(count);
//			insert(begin(), count, value);
//		}
//		void clear() {
//			;
//		}

	iterator begin() { return iterator(first_pointer_);}
	const_iterator begin() const { return const_iterator(first_pointer_);}
	iterator end() { return iterator(last_pointer_);}
	const_iterator end() const { return const_iterator(last_pointer_);}
	reverse_iterator rbegin()  {return reverse_iterator(last_pointer_);}
	reverse_iterator rbegin() const {return reverse_iterator(last_pointer_);}
	reverse_iterator rend()  {return reverse_iterator(last_pointer_);}
	reverse_iterator rend() const {return reverse_iterator(last_pointer_);}
	size_type size() const {return end() - begin();}
	bool empty() const {return begin() == end();}
	void clear() {
		destroy_range(first_pointer_, last_pointer_);
		last_pointer_ = first_pointer_;//why
		}

	iterator erase(iterator position) { return erase(position, position + 1);}
	iterator erase(iterator first, iterator last) {
			size_type erase_size = std::distance(first, last);
			pointer new_last = last_pointer_ - erase_size;
			std::copy(last.base(), last, first.base());
			destroy_range(new_last, last);
			last_pointer_ = new_last;
			return first;
	}

	void deallocate() { alloc_.deallocate(first_pointer_, capacity());}
	pointer allocate(size_type value_type) {
			if (value_type > max_size()) {
				throw std::length_error("vector allocate no more size");
			}
			return alloc_.allcate(value_type);
		}
	size_type max_size() const {
			return std::min<size_type>(alloc_.max_size(), std::numeric_limits<difference_type>::max());
		}
	void reserve(size_type value_size) {
			if (value_size <= capacity()) {
				return;
			}
			if (value_size > max_size()) {
				throw std::length_error ( "allocator<T>::allocate(size_t n) 'n' exceeds maximum supported "
										  "size");
			}
			pointer ptr = allocate(value_size);
		}

	size_type capacity() const { return storage_last_ - first_pointer_ ;}


	size_type recommend_size(size_type new_size)
	{
			size_type maxsize = max_size();
			if (maxsize < new_size) {
				throw std::length_error ("vector recommend size error");
			}
			size_type cap = capacity();
			if (maxsize / 2 <= cap) {
				return (maxsize);
			}
			return (std::max<size_type>(new_size, cap * 2));
	}

	template<class InputIt>
	void insert(iterator pos, InputIt first, InputIt last, typename std::enable_if<!std::is_integral<InputIt>::value, InputIt>::type* = NULL)
	{
			size_type n = std::distance(first, last);
			difference_type pos_dist = std::distance(begin(), pos);
			size_type new_size = size() + n;
			if (capacity() < new_size) {
				reserve(recommend_size(new_size));
				pos = begin() + pos_dist;
			}
			pointer new_last = last_pointer_ + n;
			construct_range(last_pointer_, new_last);
			std::copy_backward(pos, end(), new_last);
			std::copy(first, last, pos);
			last_pointer_ = new_last;
	}

	void swap(vector &other) {
			pointer tmp_first = other.first_pointer_;
			pointer tmp_last = other.last_pointer_;
			pointer tmp_storage_last = other.storage_last_;

			other.first_pointer_ = first_pointer_;
			other.last_pointer_ = last_pointer_;
			other.storage_last_ = storage_last_;
			first_pointer_ = tmp_first;
			last_pointer_ = tmp_last;
			storage_last_ = tmp_storage_last;
		}


	allocator_type get_allocator() const { return alloc_;}

	void resize(size_type value_size, const_reference value) {
		if (value_size < size()) {
			erase(begin() + value_size, end());
		} else if (value_size > size()){
			insert(end(), value_size - size(), value);
		}
	}

	void destroy_range(pointer first, pointer last) {
		for (pointer p = first; p < last; p++) {
			alloc_.destroy(p);
		}
	}
	private:
		pointer first_pointer_;
		pointer last_pointer_;
		pointer storage_last_;
		allocator_type alloc_;

	};
	// non-member funcs
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (lhs.size() == rhs.size() &&
				ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
											rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs) {
		lhs.swap(rhs);
	}

}

#endif