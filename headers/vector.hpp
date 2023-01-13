#ifndef VECTOR
#define VECTOR


#include <iostream>
#include <memory>

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
		typedef pointer iterator;
		typedef const_pointer const_iterator;
//		typedef ft::reverse_iterator<iterator> reverse_iterator;
//		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
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
//			clear();
//			deallocate();
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
	size_type size() const {return end() - begin();}

	iterator erase(iterator position) { return erase(position, position + 1);}
	iterator erase(iterator first, iterator last) {
			size_type erase_size = std::distance(first, last);
			pointer new_last = last_pointer_ - erase_size;
			std::copy(last.base(), last, first.base());
			destroy_range(new_last, last);
			last_pointer_ = new_last;
			return first;
	}

	template<class InputIt>
	void insert(iterator pos, InputIt first, InputIt last, typename std::enable_if<!std::is_integral<InputIt>::value, InputIt>::type* = NULL)
	{
			size_type n = std::distance(first, last);
			difference_type pos_dist = std::distance(begin(), pos);
			size_type new_size = size() + n;
			if ()
	}
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

}

#endif