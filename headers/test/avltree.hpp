#ifndef AVL_TREE
#define AVL_TREE

#define Left 1
#define Right 2

#include <libc.h>
#include <iostream>


struct node_t {
	int num;
	char name[1000];
	struct node_t *left;
	struct node_t *right;
}		node_s;


int getHight(node_t *node)
{
	int left_hight;
	int right_hight;
	int tree_hight;

	if (node == NULL){
		return 0;
	}

	left_hight = getHight(node->left);
	right_hight = getHight(node->right);


	if (left_hight > right_hight) {
		tree_hight = left_hight;
	} else {
		tree_hight = right_hight;
	}
	return tree_hight + 1;
}

/* erturn used root or created root */
/* direction is the direction from parent to node */
node_t *leftRotate(node_t *root, node_t *node, node_t *parent, int direction)
{
	node_t *pivot;
	node_t *new_root;

	printf("left_rotate[%d]\n", node->num);

	//     (parent)
	//			\
	//			(node)
	//			/    \	
	//		(  1  )	(pivot)
	//				/		\
	//  		(  2  )		(  3  )
	//							
	//     (parent)
	//			\
	//			(pivot)
	//			/      \	
	//		( node )    (  3  )
	//		/	  \		
	//  (  1  )   (  2  )


	pivot = node->right;
	if (pivot != NULL) {
		node->right = pivot->left;
		pivot->left = node;
	}
	if (pivot == NULL) {
		new_root = pivot;
		return new_root;
	}
	if (direction == Left)
	{
		parent->left = pivot;
	} else {
		parent->right = pivot;
	}
	return root;
}
node_t *rightRotate(node_t *root, node_t *node, node_t *parent, int direction)
{
	node_t *pivot;
	node_t *new_root;
	printf("right_rotate[%d]\n", node->num);

	pivot = node->left;
	if (pivot != NULL) {
		node->right = pivot->right;
		pivot->left = node;
	}
	if (pivot == NULL) {
		new_root = pivot;
		return new_root;
	}
	if (direction == Left) {
		parent->left = pivot;
	} else {
		parent->right = pivot;
	}
	return root;
}


node_t *rightleftRotate(node_t *root, node_t *node, node_t *parent, int direction) {
	node_t *new_root;

	std::cout << "--right left rotate--" << node->num << std::endl;

	new_root = rightRotate(root, node, parent, direction);

	return leftRotate(new_root, node, parent, direction);
}


node_t *leftrightRotate(node_t *root, node_t *node, node_t *parent, int direction) {
	node_t *new_root;

	std::cout << "--left right rotate--" << node->num << std::endl;

	new_root = leftRotate(root, node, parent, direction);

	return rightRotate(new_root, node, parent, direction);
}

node_t *balancing(node_t *root, node_t *node, node_t *parent, int direction, int *branch, int num_branch) {
	node_t *next;
	node_t *new_root;

	int left_hight, right_hight;
	int balnce;

	if (node == NULL || root == NULL) {
		return root;
	}
	if (num_branch > 0) {
		
	}
}
#endif
