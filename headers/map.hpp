#ifndef MAP
#define MAP

#include "pair.hpp"
#include "algorithm.hpp"
#include "reverse_iterator.hpp"
#include "avltree.hpp"
#include <iostream>
namespace ft {

	template <class Key, class T, class Compare>
	class map_value_compare {
	private:
		typedef Compare key_compare;
		key_compare comp_;

	public:
		map_value_compare() : comp_() {}
		explicit map_value_compare(key_compare c) : comp_(c) {}

		bool operator()(const T& x, const T& y) const {
			return comp_(x.first, y.first);
		}
		bool operator()(const T& x, const Key& y) const {
			return (comp_(x.first, y));
		}
		bool operator()(const Key& x, const T& y) const {
			return (comp_(x, y.first));
		}
	};

	template <class Key, class T, class Compare = std::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::reference pointer;
		typedef typename allocator_type::const_reference const_pointer;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		typedef map_value_compare<key_type, value_type, key_compare>
				map_value_compare;
		typedef AVLTree<key_type, value_type, map_value_compare, allocator_type>
				tree_type;

		tree_type tree_;

	public:
		typedef typename tree_type::iterator iterator;
		typedef typename tree_type::const_iterator const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		explicit map(const key_compare& comp = key_compare(),
					 const allocator_type& alloc = allocator_type())
				: tree_(map_value_compare(comp), alloc) {}

		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
				: tree_(map_value_compare(comp), alloc) {
			insert(first, last);
		}

		map(const map& other) : tree_(other.tree_) {}

		~map() {}

		map& operator=(const map& other) {
			tree_ = other.tree_;
			return *this;
		}

		const_iterator begin() const { return tree_.begin(); }
		iterator begin() { return tree_.begin(); }
		iterator end() { return tree_.end(); }
		const_iterator end() const { return tree_.end(); }
		reverse_iterator rbegin() { return reverse_iterator(tree_.end()); }
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(tree_.end());
		}
		reverse_iterator rend() { return reverse_iterator(tree_.begin()); }
		const_reverse_iterator rend() const {
			return const_reverse_iterator(tree_.begin());
		}

		bool empty() const { return tree_.size() == 0; }
		size_type size() const { return tree_.size(); }
		size_type max_size() const { return tree_.max_size(); }
		mapped_type& operator[](const key_type& k) {
			return tree_.insert(value_type(k, mapped_type())).first->second;
		}
		ft::pair<iterator, bool> insert(const value_type& val) {
			return tree_.insert(val);
		}

		iterator insert(iterator hint,const value_type& value) {
			return tree_.insert(hint, value);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			tree_.insert(first, last);
		}

		void erase(iterator position) { tree_.erase(position); }
		size_type erase(const key_type& k) { return tree_.erase(k); }
		void erase(iterator first, iterator last) { tree_.erase(first, last); }
		void swap(map& x) { tree_.swap(x.tree_); }
		void clear() { tree_.clear(); }
		key_compare key_comp() const { return key_compare(); }
		map_value_compare value_comp() const { return map_value_compare(key_compare()); }
		iterator find(const key_type& k) { return tree_.find(k); }
		const_iterator find(const key_type& k) const { return tree_.find(k); }
		size_type count(const key_type& k) const { return tree_.count(k); }
		iterator lower_bound(const key_type& k) { return tree_.lower_bound(k); }
		const_iterator lower_bound(const key_type& k) const {
			return tree_.lower_bound(k);
		}
		iterator upper_bound(const key_type& k) { return (tree_.upper_bound(k)); }
		const_iterator upper_bound(const key_type& k) const {
			return tree_.upper_bound(k);
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
			return tree_.equal_range(k);
		}
		ft::pair<iterator, iterator> equal_range(const key_type& k) {
			return tree_.equal_range(k);
		}
		allocator_type get_allocator() const { return allocator_type(); }
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs) {
		return (lhs.size() == rhs.size() &&
				std::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc>& lhs,
				   const map<Key, T, Compare, Alloc>& rhs) {
		return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
											rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc>& lhs,
				   const map<Key, T, Compare, Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
		x.swap(y);
	}

}
#endif