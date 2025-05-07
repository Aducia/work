#include <iostream>

int main(){

	int a,b,c,ploscha,obyem;
	std::cin >> a >> b >> c;
	ploscha = 2*(a*b+a*c+b*c);
	obyem = a*b*c;
	std::cout << "obyem parapipeda: " << obyem << ", ploscha parapipeda: " << ploscha;


}
