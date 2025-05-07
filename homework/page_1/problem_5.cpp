#include <iostream>

int main(){
	
	float p = 3.14;
	float radius;
	std::cout << "enter radius: ";
	std::cin >> radius;
	float pl = 2*p*radius*radius;
	float d = p*radius*radius;
	int n = pl;
	int a = d;
	std::cout << "ploshca kola: "<< n << "." << int(pl* 100) % (n*10) << '\n';
	std::cout << "dovzina kola: "<< a << "." << int(d*100) % (a*10) <<'\n';

}
