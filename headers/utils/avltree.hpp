#ifndef AVL_TREE
#define AVL_TREE

#include <memory>

namespace ft {
	template <typename pair_type>
	class node{
	public:
		node(typename pair_type::first_type first, typename pair_type::second_type second) {

		}
	private:
		typedef typename pair_type::first_type key_type;
		typedef typename pair_type::value_type value_type;
		key_type key_;
		value_type value_;
		node *left;
		node *right;
		node *parent;
	};

	template <typename value_type, typename Compare = std::less<typename value_type::first_type>, class Allocator = std::allocator<typename value_type::first_type> >
	class avltree {
	private:
		node<value_type> *root;


	public:

	};
}
#endif
