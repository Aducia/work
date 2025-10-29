#include<iostream>

bool is_palindrome(int i) {
	int rever = 0, orig = i;
	while (i > 0) {
		rever = rever*10+i%10;
		i /= 10;
	}
	return orig == rever;
}

int main() {
	for (int i = 1; i < 100; i++) {
		if (is_palindrome(i)) {
			int sq = i*i;
			if (is_palindrome(sq)) {
				std::cout << i << " ";
			}
		}
	}
	return 0;
}


