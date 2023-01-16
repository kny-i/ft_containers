#ifndef AVL_TREE
#define AVL_TREE

#include <libc.h>


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
node_t *leftRotate(node_t *root, node_t *node, node_t *parent, int direction)
{
	node_t *pivot;
	node_t *new_root;

	printf("left_rotate[%d]\n", node->num);

	//     (parent)
	//			\
	//			(node)
	//			/    \	
	//		(    )	(pivot)
	//					\
	//  				(     )
	
	pivot = node->right;
	if (pivot != NULL) {
		node->right = pivot->left;
		pivot->left = node;
	}
	if (pivot == NULL) {
		new_root = pivot;
		return new_root;
	}
	
}
#endif
