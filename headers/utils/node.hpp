#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include "tree_iterator.hpp"
#include "pair.hpp"
#include <iostream>

namespace ft {
	template <class T>
	class Node {
	public:
		typedef Node* node_pointer;
		typedef T value_type;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;

		node_pointer parent_;
		node_pointer left_;
		node_pointer right_;
		value_type value_;
		size_type height_;

		Node():parent_(NULL), left_(NULL), right_(NULL), value_(), height_()  {}

		explicit Node(const value_type& value)
				: parent_(NULL),
				  left_(NULL),
				  right_(NULL),
				  value_(value),
				  height_(1) {}

		Node(const Node& other)
				: parent_(other.parent_),
				  left_(other.left_),
				  right_(other.right_),
				  value_(other.value_),
				  height_(other.height_) {}

		difference_type get_scale() const {
			size_type left_height = 0;
			if (left_) {
				left_height = left_->height_;
			}
			size_type right_height = 0;
			if (right_) {
				right_height = right_->height_;
			}
			return (right_height - left_height);
		}

		void update_height() {
			size_type left_height = 0;
			if (left_) {
				left_height = left_->height_;
			}
			size_type right_height = 0;
			if (left_) {
				right_height = left_->height_;
			}
			height_ = std::max(left_height, right_height) + 1;
		}

		bool is_left_child() const {
			return this == parent_->left_;
		}
		bool is_right_child() const {
			return this == parent_->right_;
		}

		void connect_left_child(node_pointer new_left_node) {
			left_ = new_left_node;
			if (new_left_node) {
				new_left_node->parent_ = this;
			}
		}

		void connect_right_child(node_pointer new_right_node) {
			right_ = new_right_node;
			if (new_right_node) {
				new_right_node->parent_ = this;
			}
		}

		void connect_parent(node_pointer new_parent_node, bool is_left_child) {
			parent_ = new_parent_node;
			if (is_left_child) {
				new_parent_node->left_ = this;
			} else {
				new_parent_node->right_ = this;
			}
		}

		void disconnect_parent() {
			if (is_left_child()) {
				parent_->left_ = NULL;
			} else {
				parent_->right_ = NULL;
			}
			parent_ = NULL;
		}

		node_pointer get_max_node() {
			node_pointer node = this;
			while (node->right_) {
				node = node->right_;
			}
			return node;
		}

		node_pointer get_min_node() {
			node_pointer node = this;
			while (node->left_) {
				node = node->left_;
			}
			return node;
		}

		node_pointer get_next_node() {
			if (right_) {
				return right_->get_min_node();
			} else {
				node_pointer node = this;
				while (node->is_right_child()) {
					node = node->parent_;
				}
				return node->parent_;
			}
		}

		node_pointer get_next_node() const {
			if (right_)
				return (right_->get_min_node());
			else {
				const Node* node = this;
				while (node->is_right_child()) {
					node = node->parent_;
				}
				return (node->parent_);
			}
		}

		node_pointer get_prev_node() {
			if (left_) {
				return (left_->get_max_node());
			} else {
				node_pointer node = this;
				while (node->is_left_child()) {
					node = node->parent_;
				}
				return node->parent_;
			}
		}

		node_pointer get_prev_node() const {
			if (left_)
				return (left_->get_max_node());
			else {
				const Node* node = this;
				while (node->is_left_child()) {
					node = node->parent_;
				}
				return node->parent_;
			}
		}
	};

}

#endif
