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

struct tree 
{
       	int x;
       	int y;
	tree* left;
};

int main(){
	tree x;
	tree z;
	x.x = 10;
	x.y = 50;
	z.x = 20;
	z.y = 60;
	x.left = &z;
	z.left = &x;

	std::cout << x.x << x.x + x.y << x.left << std::endl;
	std::cout << (*x.left).x << (*x.left).x + (*x.left).y << (* (*x.left).left).left << std::endl;
	tree* p = x.left;
	std::cout << p->left->left->left->left << std::endl;
       /* p = &z; p-> left = &x =  x.left = (* (*x.left).left).left  */	
 	return 0;

}
