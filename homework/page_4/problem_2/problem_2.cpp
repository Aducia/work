#include <iostream>

int main() {
	int n;
	std::cout << "Enter n:" << '\n';
	std::cin >> n;
	std::cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			std::cout << "1";
		}
		std::cout << '\n';
	}

}
