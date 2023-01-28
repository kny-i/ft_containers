#ifndef AVL_TREE
#define AVL_TREE

#include <memory>
#include "node.hpp"
#include "tree_iterator.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include <utility>
/* in std::less, we use map_value_compare */

namespace ft {

	template <class Key, class T, class Compare = std::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> > >
	class avl_tree {
	public:
		typedef Key key_type;
		typedef T value_type;
		typedef Compare map_value_compare;
		typedef Allocator allocator_type;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		typedef node<T> node_type;

	public:
		typedef node_type* node_pointer;

		// わかりやすいサイト(https://in-neuro.hatenablog.com/entry/2018/08/01/114441)
		typedef
		typename Allocator::template rebind<node_type>::other node_allocator_type;

		typedef tree_iterator<value_type, node_type> iterator;
		typedef tree_iterator<const value_type, const node_type> const_iterator;

	private:
		map_value_compare comp_;
		node_allocator_type node_alloc_;
		size_type size_;
		node_pointer begin_;
		node_pointer end_;

	public:
		avl_tree(): comp_(Compare()), node_alloc_(Allocator()), size_(0), begin_(), end_(create_node()) {
			end_->left_ = NULL;
			begin_ = end_;

		}
		avl_tree(map_value_compare comp, allocator_type alloc)
				: comp_(comp), node_alloc_(alloc), size_(0) {
			end_ = create_node();
			end_->left_ = NULL;
			begin_ = end_;
		}

		avl_tree(const avl_tree& other)
				: comp_(other.comp_), node_alloc_(other.node_alloc_), size_(0) {
			end_ = create_node();
			end_->left_ = NULL;
			begin_ = end_;
			insert(other.begin(), other.end());
		}

		~avl_tree() {
			delete_tree();
			delete_node(end_);
		}

		avl_tree& operator=(const avl_tree& other) {
			if (this != &other) {
				clear();
				comp_ = other.comp_;
				node_alloc_ = other.node_alloc_;
				insert(other.begin(), other.end());
			}
			return (*this);
		}

		iterator begin() { return (iterator(begin_)); }
		const_iterator begin() const { return (const_iterator(begin_)); }
		iterator end() { return (iterator(end_)); }
		const_iterator end() const { return (const_iterator(end_)); }

		size_type size() const { return size_; }

		size_type max_size() const {
			return (node_alloc_.max_size());
		}

		ft::pair<iterator, bool> insert(const value_type& val) {
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
					return (ft::make_pair(iterator(parent_node), false));
				}
			}

			node_pointer new_node = create_node_at(val, parent_node);

			rebalance_tree(new_node);

			return ft::make_pair(iterator(new_node), true);
		}

		iterator insert(iterator position, const value_type& val) {
			return insert(val);
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

			// eraseするnodeと入れ替えるnodeをセット
			node_pointer alt_node;
			if (erase_node->left_ == NULL && erase_node->right_ == NULL) {
				alt_node = NULL;
			} else if (erase_node->get_scales() >= 0){
				//weigh on right
				alt_node = erase_node->left_->get_max_node();
			} else {
				alt_node = erase_node->right_->get_min_node();
			}

			node_pointer bottom_node;
			if (alt_node == NULL) {
				bottom_node = erase_node->parent_;
			} else if (alt_node->parent_ == erase_node) {
				bottom_node = alt_node;
			} else {
				bottom_node = alt_node->parent_;
			}

			replace_node(erase_node, alt_node);
			delete_node(erase_node);
			--size_;
			rebalance_tree(bottom_node);
		}

		size_type erase(const key_type& k) {
			iterator position = find(k);
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

		void swap(avl_tree& other) {
			std::swap(node_alloc_, other.node_alloc_);
			std::swap(comp_, other.comp_);
			std::swap(size_, other.size_);
			std::swap(begin_, other.begin_);
			std::swap(end_, other.end_);
		}

		iterator find(const key_type& k) {
			node_pointer node = find_node(k);
			return iterator(node);
		}

		const_iterator find(const key_type& k) const {
			node_pointer node = find_node(k);
			return const_iterator(node);
		}

		// 重複は許されないので0か1のみ返す
		size_type count(const key_type& k) const { return (find_node(k) != end_); }

		iterator lower_bound(const key_type& k) {
			node_pointer node = lower_bound_node(k);
			return iterator(node);
		}

		const_iterator lower_bound(const key_type& k) const {
			node_pointer node = lower_bound_node(k);
			return const_iterator(node);
		}

		iterator upper_bound(const key_type& k) {
			node_pointer node = upper_bound_node(k);
			return iterator(node);
		}

		const_iterator upper_bound(const key_type& k) const {
			node_pointer node = upper_bound_node(k);
			return const_iterator(node);
		}

		pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
			pair<node_pointer, node_pointer> pair = equal_range_node(k);
			return ft::make_pair(const_iterator(pair.first),
								 const_iterator(pair.second));
		}

		pair<iterator, iterator> equal_range(const key_type& k) {
			pair<node_pointer, node_pointer> pair = equal_range_node(k);
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

			bool is_left = (parent_node == end_ || comp_(val, parent_node->value_));
			new_node->connect_parent(parent_node, is_left);

			if (is_left && parent_node == begin_) {
				begin_ = new_node;
			}

			++size_;

			return new_node;
		}

		node_pointer root() const { return end_->left_; }

		void delete_node(node_pointer node) {
			node_alloc_.destroy(node);
			node_alloc_.deallocate(node, 1);
		}

		void delete_tree() {
			node_pointer node = root();
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

		void replace_node(node_pointer erase_node, node_pointer alt_node) {
			if (alt_node == NULL) {
				erase_node->disconnect_parent();
			} else {
				if (alt_node->left_ == NULL && alt_node->right_ == NULL) {
					alt_node->disconnect_parent();
				} else if (alt_node->left_) {
					alt_node->left_->connect_parent(alt_node->parent_, alt_node->is_left());
				} else {
					alt_node->right_->connect_parent(alt_node->parent_,
													 alt_node->is_left());
				}
				alt_node->connect_parent(erase_node->parent_, erase_node->is_left());
				alt_node->connect_left(erase_node->left_);
				alt_node->connect_right(erase_node->right_);
			}
		}

		node_pointer find_node(const key_type& k) const {
			node_pointer node = root();
			while (node) {
				if (comp_(k, node->value_)) {
					node = node->left_;
				} else if (comp_(node->value_, k)) {
					node = node->right_;
				} else {
					return node;
				}
			}
			return end_;
		}

		node_pointer lower_bound_node(const key_type& k) const {
			node_pointer node = root();
			node_pointer result = end_;
			while (node) {
				if (!comp_(node->value_, k)) {
					result = node;
					node = node->left_;
				} else {
					node = node->right_;
				}
			}
			return result;
		}

		node_pointer upper_bound_node(const key_type& k) const {
			node_pointer node = root();
			node_pointer result = end_;
			while (node) {
				if (comp_(k, node->value_)) {
					result = node;
					node = node->left_;
				} else {
					node = node->right_;
				}
			}
			return result;
		}
		pair<node_pointer, node_pointer> equal_range_node(const key_type& k) const {
			node_pointer upper = end_;
			node_pointer lower = root();
			while (lower) {
				if (comp_(k, lower->value_)) {
					upper = lower;
					lower = lower->left_;
				} else if (comp_(lower->value_, k)) {
					lower = lower->right_;
				} else {
					return ft::make_pair(lower,
										 lower->right_ ? lower->right_->get_min_node() : upper);
				}
			}
			return ft::make_pair(upper, upper);
		}

		void rotate_left(node_pointer node) {
			node_pointer right_node = node->right_;

			right_node->connect_parent(node->parent_, node->is_left());
			node->connect_right(right_node->left_);
			right_node->connect_left(node);

			node->update_height();
			right_node->update_height();
		}

		void rotate_right(node_pointer node) {
			node_pointer left_node = node->left_;

			left_node->connect_parent(node->parent_, node->is_left());
			node->connect_left(left_node->right_);
			left_node->connect_right(node);

			node->update_height();
			left_node->update_height();
		}

		//追加または削除した部分のbottom_node
		void rebalance_tree(node_pointer bottom_node) {
			node_pointer node = bottom_node;
			node_pointer parent_node;

			while (node != end_) {
				parent_node = node->parent_;
				difference_type balance = node->get_scales();
				if (balance == 2) {
					if (node->left_->get_scales() == -1) {
						rotate_left(node->left_);
					}
					rotate_right(node);
				} else if (balance == -2) {
					if (node->right_->get_scales() == 1) {
						rotate_right(node->right_);
					}
					rotate_left(node);
				} else {
					node->update_height();
				}
				node = parent_node;
			}
			// verify_avl();
		}

	public:
		// verify関数を入れる
		void verify_avl() {
			node_pointer node = begin_;
			while (node != end_) {
				difference_type bal = node->get_scales();
				if (bal > 1 || bal < -1) {
					std::cerr << "avl is not verified" << std::endl;
					throw "wrong tree!!!";
				}
				node = node->get_next_node();
			}
		}
	};

}  // namespace ft

#endif
