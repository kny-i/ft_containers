#ifndef AVL_TREE
#define AVL_TREE

#include <memory>
#include "node.hpp"
#include "tree_iterator.hpp"
namespace ft {
	template <class Key, class T,  class Compare = std::less<Key>,
	        class Allocator = std::allocator<std::pair<const Key, T> > >
	class avltree {
	public:
		typedef Key key_type;
		typedef T value_type;
		typedef Compare map_value_compare;
		typedef Allocator allocator_type;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		typedef node<T> node_type;
		typedef node_type* node_pointer;
		typedef typename Allocator::template rebind<node_type>::other node_allocator_type;

		typedef tree_iterator<value_type , node_type > iterator;
		typedef tree_iterator<const value_type, const node_type> const_iterator;

	private:
		map_value_compare compare_;
		node_allocator_type node_alloc_;
		size_type size_;
		node_pointer begin_;
		node_pointer end_;

	public:
		avltree(map_value_compare comp, allocator_type alloc)
		: compare_(comp), node_alloc_(alloc), size_(0) {
			end_ = create_node();
			end_->left_ = NULL;
			begin_ = end_;
		}

		avltree(const avltree& other)
				: compare_(other.compare_), node_alloc_(other.node_alloc_), size_(0) {
			end_ = create_node();
			end_->left_ = NULL;
			begin_ = end_;
			insert(other.begin(), other.end());
		}
		avltree& operator=(const avltree& other) {
			if (this != &other) {
				clear();
				compare_ = other.comp_;
				node_alloc_ = other.node_alloc_;
				insert(other.begin(), other.end());
			}
			return (*this);
		}

		~avltree() {
			delete_tree();
			delete_node(end_);
		}

		/* is that constructor? */
		iterator begin() {return (iterator(begin_));}
		iterator begin() const {return (const_iterator(begin_));}
		iterator end() { return (iterator(end_)); }
		const_iterator end() const { return (const_iterator(end_)); }

		size_type size() const { return size_; }

		size_type max_size() const {
			return (std::min<size_type>(node_alloc_.max_size(),
										std::numeric_limits<difference_type>::max()));
		}

		std::pair<iterator, bool> insert(const value_type& val) {
			node_pointer parent_node = end_;
			node_pointer node = root();

			while (node) {
				parent_node = node;
				if (comp_(val, parent_node->value_)) {
					node = parent_node->left_;
				} else if (comp_(parent_node->value_, val)) {
					node = parent_node->right_;
				} else {
					// 同じvalが存在、insert失敗
					return (std::make_pair(iterator(parent_node), false));
				}
			}

			node_pointer new_node = create_node_at(val, parent_node);

			rebalance_tree(new_node);

			return std::make_pair(iterator(new_node), true);
		}

		iterator insert(iterator position, const value_type& val) {
			node_pointer pos_node = position.base();
			node_pointer parent_node;

			// hint(position)の一つ前にinsertする時
			if (pos_node == end_ || comp_(val, pos_node->value_)) {
				node_pointer prev_node =
						(pos_node == begin_) ? NULL : pos_node->prev_node();
				if (pos_node == begin_ || comp_(prev_node->value_, val)) {
					parent_node = (pos_node->left_ == NULL) ? pos_node : prev_node;
				} else {
					return (insert(val).first);
				}
				// 一つ後にinsertする時
			} else if (comp_(pos_node->value_, val)) {
				node_pointer next_node = pos_node->next_node();
				if (next_node == end_ || comp_(val, next_node->value_)) {
					parent_node = (pos_node->right_ == NULL) ? pos_node : next_node;
				} else {
					return (insert(val).first);
				}
			} else {
				return (iterator(pos_node));
			}
			node_pointer new_node = create_node_at(val, parent_node);
			rebalance_tree(new_node);
			return (iterator(new_node));
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			for (InputIterator p = first; p != last; ++p) {
				insert(*p);
			}
		}



	};
}
#endif
