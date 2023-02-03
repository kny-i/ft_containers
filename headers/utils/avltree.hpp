#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "pair.hpp"
#include <memory>
#include "node.hpp"
#include "tree_iterator.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include <utility>

#include "pair.hpp"
#include <utility>

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> > >
	class AVLTree {
	public:
		typedef Key key_type;
		typedef T value_type;
		typedef Compare value_compare;
		typedef Allocator allocator_type;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		typedef Node<T> node_type;
	public:
		typedef node_type* node_pointer;
		/*
		 * rebindを使う目的としては、ユーザーからは定義しきれない
		 * std::allocator<>の<>部分を再定義し直すため ← map class側から指定することはできない
		 * (前提: map class(AVLTree class)においてallocator用いて確保したい型はnode_typeであるが、
		 * node_typeはprivateなmemberなので、rebind()を用いて再定義し直す必要がある)
		 * ↑本当に厳密な話としてはpublicでも一度インスタンス化する必要があるためほぼ不可能？
		 */
		typedef typename Allocator::template rebind<node_type>::other node_allocator_type;

		typedef tree_iterator<value_type, node_type> iterator;
		typedef tree_iterator<value_type, node_type> const_iterator;

	private:
		value_compare comp_;
		node_allocator_type node_alloc_;
		size_type size_;
		node_pointer begin_;
		node_pointer end_;

	public:
		AVLTree(): comp_(Compare()), node_alloc_(Allocator()), size_(0), begin_(), end_(create_node()) {
			end_->left_ = NULL;
			begin_ = end_;
		}
		AVLTree(value_compare comp, allocator_type alloc)
				: comp_(comp), node_alloc_(alloc), size_(0) {
			end_ = create_node();
			end_->left_ = NULL;
			begin_ = end_;
		}

		AVLTree(const AVLTree& other)
				: comp_(other.comp_), node_alloc_(other.node_alloc_), size_(0) {
			end_ = create_node();
			end_->left_ = NULL;
			begin_ = end_;
			insert(other.begin(), other.end());
		}
		~AVLTree() {
			delete_tree();
			delete_node(end_);
		}
		AVLTree& operator=(const AVLTree& other) {
			if (this != &other) {
				clear();
				comp_ = other.comp_;
				node_alloc_ = other.node_alloc_;
				insert(other.begin(), other.end());
			}
			return *this;
		}
		iterator begin() {
			return iterator(begin_);
		}
		const_iterator begin() const {
			return const_iterator(begin_);
		}
		iterator end() {
			return iterator(end_);
		}
		const_iterator end() const {
			return const_iterator(end_);
		}

		size_type size() const {
			return size_;
		}

		size_type max_size() const {
			return node_alloc_.max_size();
		}


		ft::pair<iterator, bool> insert(const value_type& val) {
			node_pointer parent_node = end_;
			node_pointer node = get_root();

			while (node) {
				parent_node = node;
				if (comp_(val, parent_node->value_)) {
					node = parent_node->left_;
				} else if (comp_(parent_node->value_, val)) {
					node = parent_node->right_;
				} else {
					return ft::make_pair(iterator(parent_node), false);
				}
			}
			node_pointer new_node = create_node_at(val, parent_node);
			make_balanced(new_node);
			return ft::make_pair(iterator(new_node), true);
		}
		iterator insert(iterator position, const value_type& val) {
			(void)position;
			ft::pair<iterator, bool> ret = insert(val);
			return ret.first;
		}
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			for (InputIterator p = first; p != last; ++p) {
				insert(*p);
			}
		}
		void erase(iterator position) {
			node_pointer erase_node = position.base();
			if (erase_node == begin_) {
				begin_ = erase_node->get_next_node();
			}
			node_pointer alternate;
			if (!erase_node->left_ && !erase_node->right_) {
				alternate = NULL;
			} else if (erase_node->get_scale() <= 0) {
				//　　　[weight on left]
				// 下の逆パターン
				alternate = erase_node->left_->get_max_node();
			} else {
				alternate = erase_node->right_->get_min_node();
				//　　　[weight on right]
				//          ( 9 )
				//         /    \
                //      ( 5 ) ( 11 )
				//              /  \
                //           ( 10 )( 12 )
			}

			node_pointer bottom_node;
			if (alternate == NULL) {
				bottom_node = erase_node->parent_;
			} else if (alternate->parent_ == erase_node) {
				//          ( 9 )                     (11)
				//          /   \                    /    \
                //      ( 5 ) ( 11 )      ->     (5)       (12)
				//                \
                //               ( 12 )
				bottom_node = alternate;
			} else {
				bottom_node = alternate->parent_;
				//          ( 10 )
				//         /    \
                //      ( 5 ) ( 11 )
				//                \
                //               ( 12 )
			}
			replace_node(erase_node, alternate);
			delete_node(erase_node);
			size_--;
			make_balanced(bottom_node);
		}

		size_type erase(const key_type& content) {
			iterator position = find(content);
			if (position == end()) {
				return 0;
			}
			erase(position);
			return 1;
		}

		void erase(iterator first, iterator last) {
			while (first != last) {
				erase(first++);
			}
		}

		void swap(AVLTree& other) {
			std::swap(node_alloc_, other.node_alloc_);
			std::swap(comp_, other.comp_);
			std::swap(size_, other.size_);
			std::swap(begin_, other.begin_);
			std::swap(end_, other.end_);
		}

		iterator find(const key_type& content) {
			node_pointer node = find_node(content);
			return iterator(node);
		}

		const_iterator find(const key_type& content) const {
			node_pointer node = find_node(content);
			return const_iterator(node);
		}

		// 重複は許されないので0か1のみ返す
		size_type count(const key_type& content) const {
			return find_node(content) != end_;
		}

		iterator lower_bound(const key_type& content) {
			node_pointer node = lower_bound_node(content);
			return iterator(node);
		}

		const_iterator lower_bound(const key_type& content) const {
			node_pointer node = lower_bound_node(content);
			return const_iterator(node);
		}

		iterator upper_bound(const key_type& content) {
			node_pointer node = upper_bound_node(content);
			return iterator(node);
		}

		const_iterator upper_bound(const key_type& content) const {
			node_pointer node = upper_bound_node(content);
			return const_iterator(node);
		}

		pair<const_iterator, const_iterator> equal_range(const key_type& content) const {
			pair<node_pointer, node_pointer> pair = equal_range_node(content);
			return ft::make_pair(const_iterator(pair.first),
								 const_iterator(pair.second));
		}

		pair<iterator, iterator> equal_range(const key_type& content) {
			pair<node_pointer, node_pointer> pair = equal_range_node(content);
			return ft::make_pair(iterator(pair.first), iterator(pair.second));
		}

		void clear() {
			delete_tree();
			size_ = 0;
			end_->left_ = NULL;
			begin_ = end_;
		}

	private:
		node_pointer create_node() {
			node_pointer new_node = node_alloc_.allocate(1);
			node_alloc_.construct(new_node);
			return new_node;
		}

		node_pointer create_node(const value_type& val) {
			node_pointer new_node = node_alloc_.allocate(1);
			node_alloc_.construct(new_node, node_type(val));
			return new_node;
		}

		node_pointer create_node_at(const value_type& val, node_pointer parent_node) {
			node_pointer new_node = create_node(val);


			bool is_left_child = (parent_node == end_ || comp_(val, parent_node->value_));
			new_node->connect_parent(parent_node, is_left_child);

			if (is_left_child && parent_node == begin_) {
				begin_ = new_node;
			}
			size_++;
			return new_node;
		}

		node_pointer get_root() const {
			return end_->left_;
		}

		void delete_node(node_pointer node) {
			node_alloc_.destroy(node);
			node_alloc_.deallocate(node, 1);
		}

		void delete_tree() {
			node_pointer node = get_root();
			if (node == NULL) {
				return;
			}
			while (node != end_) {
				if (node->left_) {
					node = node->left_;
				} else if (node->right_) {
					node = node->right_;
				} else {
					node_pointer parent_node = node->parent_;
					node->disconnect_parent();
					delete_node(node);
					node = parent_node;
				}
			}
		}

		void replace_node(node_pointer erase_node, node_pointer alternate) {
			if (alternate == NULL) {
				erase_node->disconnect_parent();
			} else {
				if (alternate->left_ == NULL && alternate->right_ == NULL) {
					alternate->disconnect_parent();
				} else if (alternate->left_) {
					alternate->left_->connect_parent(alternate->parent_, alternate->is_left_child());
				} else {
					alternate->right_->connect_parent(alternate->parent_,
													 alternate->is_left_child());
				}
				alternate->connect_parent(erase_node->parent_, erase_node->is_left_child());
				alternate->connect_left_child(erase_node->left_);
				alternate->connect_right_child(erase_node->right_);
			}
		}

		node_pointer find_node(const key_type& content) const {
			node_pointer node = get_root();
			while (node) {
				if (comp_(content, node->value_)) {
					node = node->left_;
				} else if (comp_(node->value_, content)) {
					node = node->right_;
				} else {
					return node;
				}
			}
			return end_;
		}
		/*
		 * 全探索をして、(最も近い)かつ(自分よりも大きい)nodeを見つける
		 */
		node_pointer lower_bound_node(const key_type& content) const {
			node_pointer node = get_root();
			node_pointer result = end_;
			while (node) {
				if (comp_(node->value_, content)) {
					node = node->right_;
				} else {
					result = node;
					node = node->left_;
				}
			}
			return result;
		}
		/*
		 * 全探索をして、(最も近い)かつ(自分よりも小さい)nodeを見つける
		 */
		node_pointer upper_bound_node(const key_type& content) const {
			node_pointer node = get_root();
			node_pointer result = end_;
			while (node) {
				if (comp_(content, node->value_)) {
					result = node;
					node = node->left_;
				} else {
					node = node->right_;
				}
			}
			return result;
		}
		ft::pair<node_pointer, node_pointer> equal_range_node(const key_type& content) const {
			return ft::make_pair(lower_bound_node(content), upper_bound_node(content));
		}

		void rotate_left(node_pointer node) {
			node_pointer right_node = node->right_;

			right_node->connect_parent(node->parent_, node->is_left_child());
			node->connect_right_child(right_node->left_);
			right_node->connect_left_child(node);

			node->update_height();
			right_node->update_height();
		}

		void rotate_right(node_pointer node) {
			node_pointer left_node = node->left_;

			left_node->connect_parent(node->parent_, node->is_left_child());
			node->connect_left_child(left_node->right_);
			left_node->connect_right_child(node);

			node->update_height();
			left_node->update_height();
		}

		//追加または削除した部分のbottom_node
		void make_balanced(node_pointer bottom_node) {
			node_pointer node = bottom_node;
			node_pointer parent_node;

			while (node != end_) {
				parent_node = node->parent_;
				difference_type scale = node->get_scale();
				if (scale == -2) {
					if (node->left_->get_scale() == 1) {
						rotate_left(node->left_);
					}
					rotate_right(node);
				} else if (scale == 2) {
					if (node->right_->get_scale() == -1) {
						rotate_right(node->right_);
					}
					rotate_left(node);
				} else {
					node->update_height();
				}
				node = parent_node;
			}
		}

	public:
		bool verify_avl() {
			bool is_ok = true;
			node_pointer node = begin_;
			while (node != end_) {
				difference_type scale = node->get_scale();
				if (abs(scale) > 1) {
					is_ok = false;
					std::cerr << "OH MY GOSH!" << std::endl;
				}
				node = node->get_next_node();
			}
			return is_ok;
		}
	};

}  // namespace ft

#endif
