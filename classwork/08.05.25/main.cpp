/* 
 *
 *               50
 *             /   \
 *            20   71
 *          /  \    \
 *          15  26  72
 *              /\
  *            25 30
 *
 * */
#include <iostream>
#include <stack>
#include <queue>
struct tree_node 
{
       	int value;
	tree_node() {
		right = left = 0;
	}	
	//int x(int a){ 
		//left++;
	//return 0;	
//	}
	tree_node* left;
	tree_node* right;
};
	void take_left(tree_node* start ){
		tree_node* current_element = start;
		while ( current_element != 0 ){
			std::cout << current_element->value << std::endl;
			current_element = current_element->left;
		}
	}

	void take_right(tree_node* start){
		tree_node* current_element = start;
		while ( current_element != 0 ){
			std::cout << current_element->value << std::endl;
			current_element = current_element->right;
		}
	}
	void DFS (tree_node* start){
		tree_node* current_element = start;	
		if( 0 == current_element )
			return ;
		std::cout << current_element->value << std::endl;
		DFS ( current_element->left );
		DFS ( current_element->right );
		}
	void BFS (tree_node* start){
		tree_node* current_element = start;
		if ( 0 == current_element )
			return ;
		std::queue < tree_node*> queue;
		queue.push( current_element );
	while( 0 == queue.empty()) {
		tree_node* current_element = queue.front();
		queue.pop();
		std::cout << current_element->value << std::endl;
		if ( current_element->left !=0  ){
			queue.push( current_element->left );}
		if ( current_element->right !=0  ){
			 queue.push( current_element->right );}
	}}


// int tree_node__x(tree_node* this,int a){
// 	this->left++;
// 	return 0;
// }


int main(){

	tree_node root;
	// tree_node__x(&root, 4);
	//root.x(4);
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
	take_left( &root );
	std::cout << "********"<< std::endl;
	take_right( &l1_1 );
	std::cout << "********"<< std::endl;
	DFS( &root );
	std::cout << "********"<< std::endl;
        BFS( &root );

	return 0;
}
