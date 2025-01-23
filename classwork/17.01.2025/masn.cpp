#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	int len;
	std::cin >> len;
	int* a = new int [len];
	srand(std::time(0));
	std::cout << RAND_MAX << '\n' << '\n'
	for (int i = 0; i < len; i++) {
		a[i] = (rand()%101)-50;
	}
	
	for (int i = 0; i < len; i++) {
		std::cout << a[i] << '\t';
	}

	std::cout << '\n' << '\n';
	
	for (int j = len-1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (a[i] > a[i+1]) {
				int b;
				b = a[i+1];
				a[i+1] = a[i];
				a[i] = b;
			}
		}
	}

	for (int i = 0; i < len; i++) {
                std::cout << a[i] << '\t';
        }

	int fnum;
	std::cin >> fnum;

	for (int i = 0; i < len; i++) {
		if (a[i] == fnum) {
			std::cout << "found on position: " << i;
			break;
		}
	}
	std::cout << '\n' << "binary" << '\n';
	//****************
	int left = 0, right = len-1;
	while (left < right) {
		int middle = (left+right)/2;
		
		if (fnum < a[middle]) {
			right = middle;
		}
		else {
			left = middle;
		}
	}
	if (a[left] == fnum) {
		std::cout << "found on position: " << left;
	}
	else {
		std::cout << "number not found";
	}


	delete[] a;
	return 0;
}
