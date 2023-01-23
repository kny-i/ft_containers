#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

namespace ft {
	template <class T>
	class node {
	public:
		typedef node* node_ptr;
		typedef T value_type;
		typedef size_t size_type;
		typedef ptrdiff_t diffrence_type;

		node_ptr parent_;
		node_ptr left_;
		node_ptr right_;
		value_type value_;
		size_type height;

		node() {}

		explicit node(const value_type& value):parent_(NULL), left_(NULL), right_(NULL), value_(value), height(1) {}

		node(const node& other): parent_(other.parent_), left_(other.left_), right_(other.right_), value_(other.value_), height(other.height) {}

		diffrence_type balance() const {
			size_type left_hight;
			size_type right_hight;
			if (left_) {
				left_hight = left_->height;
			} else {
				left_hight = 0;
			}
			if(right_) {
				right_hight = right_hight;
			}
		}

		void update_hight() {
			size_type left_height;
			size_type right_height;
		}
	};
};

#endif