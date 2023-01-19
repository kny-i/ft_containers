#ifndef AVL_TREE
#define AVL_TREE

#include <memory>

namespace ft {
	template <typename first_type, typename second_type>
	class node{
	public:
		node(first_type first, second_type second) {

		}

	private:
		first_type first;
		second_type second;
		node *left;
		node *right;
	};

	template <typename first_type, typename second_type, typename Compare = std::less<first_type>
	class avltree {

	};
}
#endif
