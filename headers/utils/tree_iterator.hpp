#ifndef TREE_ITE
#define TREE_ITE

#include <iterator>
#include <iterator.hpp>

namespace ft {

	template <class T, class Node>
	class tree_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {
	public:
		// この部分見直しする
		typedef typename ft::iterator<std::bidirectional_iterator_tag,
				T>::iterator_category iterator_category;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type
				value_type;
		typedef
		typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type
				difference_type;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer
				pointer;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::reference
				reference;

	private:
		typedef Node node_type;
		typedef node_type* node_pointer;
		node_pointer node_;

	public:
		tree_iterator() : node_(NULL) {}

		tree_iterator(const tree_iterator<T, Node>& other) : node_(other.base()) {}

		explicit tree_iterator(node_pointer node) : node_(node) {}

		tree_iterator& operator=(const tree_iterator& other) {
			if (this != &other) {
				node_ = other.node_;
			}
			return *this;
		}

		virtual ~tree_iterator() {}

		reference operator*() const { return node_->value_; }

		pointer operator->() const { return (&(node_->value_)); }

		tree_iterator& operator++() {
			node_ = node_->next_node();
			return *this;
		}

		tree_iterator operator++(int) {
			tree_iterator tmp(*this);
			node_ = node_->next_node();
			return (tmp);
		}

		tree_iterator& operator--() {
			node_ = node_->prev_node();
			return (*this);
		}

		tree_iterator operator--(int) {
			tree_iterator tmp(*this);
			node_ = node_->prev_node();
			return tmp;
		}

		node_pointer base() const { return (node_); }
	};

	template <class T1, class Node1, class T2, class Node2>
	bool operator==(const tree_iterator<T1, Node1>& lhs,
					const tree_iterator<T2, Node2>& rhs) {
		return (lhs.base() == rhs.base());
	}

	template <class T1, class Node1, class T2, class Node2>
	bool operator!=(const tree_iterator<T1, Node1>& lhs,
					const tree_iterator<T2, Node2>& rhs) {
		return (!(lhs == rhs));
	}

}  // namespace ft


#endif