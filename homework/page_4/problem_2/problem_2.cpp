#include <iostream>

int main() {
	int n;
	std::cout << "Enter n:" << '\n';
	std::cin >> n;
	std::cout << '\n';
	int triangle[n][n];
	triangle[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				triangle[i][j] = 1;
			}
			else if (j == i) {
				triangle[i][j] = 1;
			}
			else {
				triangle[i][j] = triangle[i-1][j-1]+triangle[i-1][j];
			}	
			std::cout << triangle[i][j] << " ";
		}
		std::cout << '\n';
	}

}
