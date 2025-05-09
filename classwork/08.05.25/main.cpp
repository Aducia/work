/* 
 *
 *               50
 *             /   \
 *            20   71
 *          /  \    |
 *          15  26  72
 *              /\
  *            25 30
 *
 * */
#include <iostream>

struct tree_node 
{
       	int value;
	tree_node() {
		right = left = 0;
	}	
	tree_node* left;
	tree_node* right;
};


int main(){

	tree_node root;
	root.value = 50;
	tree_node l1_1;
	l1_1.value = 20;
	tree_node l1_2;
	l1_2.value = 71;
	root.left = &l1_1;
	root.right = &l1_2;
	
	tree_node l2_1, l2_2, l2_3, l3_1, l3_2;
	l2_1.value = 15;
	l2_2.value = 26;
	l2_3.value = 72;
	l3_1.value = 25;
	l3_2.value = 30;
	l1_1.left = &l2_1;
	l1_1.right = &l2_2;
	l1_2.right = &l2_3;
	l2_2.left = &l3_1;
	l2_2.right = &l3_2;
}
