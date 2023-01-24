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


	};
}
#endif
