#include <iostream>

int main() {
	int arr[999];
	int size = 999;
	for (int i = 0; i < size; i++) {
		arr[i] = i+2;
	}
	for (int i = 0; i < size; i++) {
		if (arr[i] != 0) {
			for (int j = (arr[i]*2)-2; j < size; j += arr[i]) {
				arr[j] = 0;
			}
		}
	}
	for (int i = 0; i < 999; i++) {
		if (arr[i] != 0) {
			std::cout << arr[i] << " ";
		}
	}
	std::cout << '\n';
	return 0;
}
