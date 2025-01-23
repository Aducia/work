#include <iostream>

int pow (int a) {
	a = a*a;
	return a;
}

//void pow (int* a) {
//	a = a*a;
//}

int main () {
	long long int a, b, c = 1, n;
	std::cout << "Enter n:" << '\n';
	std::cin >> n;
	a = c;
	b = c;
	while (c < n) {
		for (a = 1; a <= c; a++) {
			for (b = 1; b <= a; b++) {
				if (pow(a) + pow(b) == pow(c)) {
					std::cout << "a:" << a << " b:" << b << " c:" << c << '\n';
				}
			}
		}
	c++;
	}
}
