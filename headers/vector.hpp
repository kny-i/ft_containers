#ifndef VECTOR
#define VECTOR
#include <iostream>
#include <memory>
#include <iterator.hpp>
#include <reverse_iterator.hpp>
#include <random_access_iterator.hpp>
#include <algorithm.hpp>
#include <enableif.hpp>
#include <is_integral.hpp>
namespace ft {
	template<class T, class Allocator = std::allocator<T> >
	class vector {
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::reference reference;
		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
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
		//enable if はきく
		template <typename InputIt>
		vector(typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last, const Allocator& alloc = Allocator())
				: first_pointer_(NULL), last_pointer_(NULL), storage_last_(NULL), alloc_(alloc) {
			reserve(recommend_size(last - first));
			for (InputIt it = first;it != last; ++it) {
				push_back(*it);
			}
		}
		/* copy constructor */
		vector(vector const& other)
		: first_pointer_(), last_pointer_(), storage_last_(), alloc_(other.alloc_) {
			*this = other;
		}

		/* operator overload */
		vector &operator=(const vector &other) {
			if (this != &other) {
				clear();
				assign(other.begin(), other.end());
			}
			return *this;
		}

		/* destructor */
		~vector() {
			clear();
			deallocate();
		}
		void assign(size_type count, const T& value) {
			/* reallocate */
			if (count > capacity()) {
				clear();
				deallocate();
				first_pointer_ = allocate(count);
				last_pointer_ = first_pointer_;
				storage_last_ = first_pointer_ + count;
				for (size_type i = 0; i < count; ++i) {
					construct(last_pointer_++, value);
				}
			}
			/* expand last_pointer */
			else if (count > size()) {
				pointer p = first_pointer_;
				for (size_type i = 0; i < count; ++i) {
					if (i > size()) {
						/* update last_pointer */
						construct(last_pointer_++, value);
					} else {
						*p++ = value;
					}
				}
			}
			/* update value inside */
			else {
				clear();
				for (size_type i = 0; i < count; i++) {
					construct(last_pointer_++,value);
				}
			}
		}


		template<class InputIt>
		void assign(typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last){
			size_type count = std::distance(first, last);
			/* reallocate */
			if (count > capacity()) {
				clear();
				deallocate();
				first_pointer_ = allocate(count);
				last_pointer_ = first_pointer_;
				storage_last_ = first_pointer_ + count;
				for (InputIt head = first; head != last; ++head) {
					construct(last_pointer_++, *head);
				}
			}
				/* expand last_pointer */
			else if (count > size()) {
				pointer p = first_pointer_;
				for (size_type i = 0; i < count; ++i) {
					if (i > size()) {
						/* update last_pointer */
						construct(last_pointer_++, *first++);
					} else {
						*p++ = *first++;
					}
				}
			}
				/* update value inside */
			else {
				clear();
				for (InputIt head = first; head != last; head++) {
					construct(last_pointer_++, *head);
				}
			}
		}

	reference at(size_type i) {
			if (i >= size())
				throw std::out_of_range("vector");
			return first_pointer_[i];
		}
	const_reference at(size_type i) const {
		if (i >= size())
			throw std::out_of_range("vector");
		return first_pointer_[i];
	}

	reference operator[](size_type i) {return first_pointer_[i];}
	const_reference operator[](size_type i) const {return first_pointer_[i];}
	reference front(){return *begin();}
	const_reference front() const {return *begin();}
	reference back() {return *(end() - 1);}
	const_reference back() const {return *(end() - 1);}
	pointer data() {return first_pointer_;}
	const_pointer data() const {return first_pointer_;}

	iterator begin() { return iterator(first_pointer_);}
	const_iterator begin() const { return const_iterator(first_pointer_);}
	iterator end() { return iterator(last_pointer_);}
	const_iterator end() const { return const_iterator(last_pointer_);}
	reverse_iterator rbegin()  {return reverse_iterator(last_pointer_);}
	reverse_iterator rbegin() const {return reverse_iterator(last_pointer_);}
	reverse_iterator rend()  {return reverse_iterator(first_pointer_);}
	reverse_iterator rend() const {return reverse_iterator(first_pointer_);}

	size_type size() const {return end() - begin();}
	bool empty() const {return begin() == end();}
	void clear() {
		destroy_range(first_pointer_, last_pointer_);
		last_pointer_ = first_pointer_;
	}

	void push_back(const_reference value) {
			if (last_pointer_ == storage_last_) {
				reserve(recommend_size(size() + 1));
			}
			construct(last_pointer_, value);
			++last_pointer_;
		}
	void pop_back() { destroy(--last_pointer_);}

	iterator erase(iterator position) { return erase(position, position + 1);}

	iterator erase(iterator first, iterator last) {
			size_type erase_size = std::distance(first, last);
			pointer new_last = last_pointer_ - erase_size;
			//copy がiteratorに対応してないためbaseを渡している
			//last.baseからlast_pointer_までfirst.baseからコピーする
			std::copy(last.base(), last_pointer_, first.base());
			destroy_range(new_last, last_pointer_);
			last_pointer_ = new_last;
			return first;
	}

	private:
	void deallocate() { alloc_.deallocate(first_pointer_, capacity());}

	pointer allocate(size_type value_type) {
			if (value_type > max_size()) {
				throw std::length_error("vector allocate no more size");
			}
			return alloc_.allocate(value_type);
	}
	public:
	size_type max_size() const {
			return alloc_.max_size();
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
			pointer old_first = first_pointer_;
			pointer old_last = last_pointer_;

			size_type old_capacity = capacity();

			first_pointer_ = ptr;
			last_pointer_ = first_pointer_;
			storage_last_ = first_pointer_ + value_size;
			for (pointer old_iter = old_first; old_iter != old_last; ++old_iter, ++last_pointer_) {
				construct(last_pointer_, *old_iter);
			}
			for (iterator riter = old_last,  rend = old_first; riter != rend; --riter) {
				destroy(&*riter);
			}
			alloc_.deallocate(old_first, old_capacity);
		}


	size_type capacity() const { return storage_last_ - first_pointer_ ;}

	private:
	size_type recommend_size(size_type new_size)
	{
			size_type maxsize = max_size();
			if (maxsize < new_size) {
				throw std::length_error ("vector recommend size error");
			}
			//すでにある容量の倍を確保していく
			size_type cap = capacity();
			if (maxsize <= cap * 2) {
				//2倍確保できない時
				return (maxsize);
			}
			//capの2倍以上は獲得したい
			//https://uquest.tktk.co.jp/embedded/learning/lecture17.html#:~:text=%E3%83%A1%E3%83%A2%E3%83%AA%E3%81%AE%E3%83%95%E3%83%A9%E3%82%B0%E3%83%A1%E3%83%B3%E3%83%86%E3%83%BC%E3%82%B7%E3%83%A7%E3%83%B3%E3%81%A8%E3%81%AF,%E3%81%97%E3%81%BE%E3%81%A3%E3%81%9F%E3%81%93%E3%81%A8%E3%82%92%E6%8C%87%E3%81%99%E3%80%82
			//本家は2倍から
			return (std::max<size_type>(new_size, cap * 2));
	}

	public:
		/* insert a value into specdfic pos */
	iterator insert(iterator pos, const value_type &value) {
			size_type diss = pos - begin();
			insert(pos, 1, value);
			return begin() + diss;
		}

	void insert(iterator new_pos, size_type value_size, const value_type &value)
	{
		if (value_size == 0)
			return;
		difference_type pos_dist = std::distance(begin(), new_pos);
		size_type new_size = size() + value_size;
		if (capacity() < new_size) {
			reserve(recommend_size(new_size));
			//rserveを通るとpointerの更新が必要になる可能性がある
			new_pos = begin() + pos_dist;
		}
		//[][][]|[][]|
		pointer new_last = last_pointer_ + value_size;
			construct_range(last_pointer_, new_last);
		//↓がbを3つ挿入したいケース
		//    ↓
		//[a][x][x][x][ ][ ][ ] : constructでメモリを確保
		//[a][x][x][x][x][x][x] : 上で作った領域にvalue_size個分後ろからコピー
		//[a][b][b][b][x][x][x] : その上で、入れたかった場所に欲しいものを入れる
		//copy_backwardはfirstからlastまでの要素をnew_lastから、後ろからコピーしてる
			std::copy_backward(new_pos, end(), new_last);
			std::fill(new_pos, new_pos + value_size, value);
			last_pointer_ = new_last;
	}

		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
		insert(iterator pos, InputIterator first, InputIterator last) {
		size_type n = std::distance(first_pointer_, last_pointer_);
		difference_type pos_dist = std::distance(begin(), pos);
		size_type new_size = size() + n;
		if (capacity() < new_size) {
			reserve(recommend_size(new_size));
			pos = begin() + pos_dist;
		}
		pointer new_last = last_pointer_ + n;
		construct_range(last_pointer_, new_last);
		std::copy_backward(pos, end() ,new_last);
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

	private:
	void construct(pointer ptr) { alloc_.construct(ptr, T()); }

	void construct(pointer ptr, const_reference value) {
		alloc_.construct(ptr, value);
	}

	void construct_range(pointer first, pointer last) {
		for (pointer p = first; p < last; p++) {
			alloc_.construct(p);
		}
	}

	public:
	allocator_type get_allocator() const { return alloc_;}


	void resize(size_type count, T value = T()) {
		//sizeが10でcount が2なら後ろから3つ削除する
		if (count < size()) {
			size_type diff = size() - count;
			erase(begin() + diff, end());
			last_pointer_ = first_pointer_ + count;
		} else if (count > size()) {
			reserve(recommend_size(count));
			while (size() < count) {
				construct(last_pointer_++, value);
			}
		}
	}

	private:
	void destroy(pointer ptr) {alloc_.destroy(ptr);}

	void destroy_range(iterator first, iterator last) {
		for (iterator p = first; p < last; p++) {
			alloc_.destroy(&*(p));
		}
	}
	//iterator の無効果の話
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
