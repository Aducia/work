#include <iostream>
#include <cstring>

int main () {
	char a[255];
	int num[255];
	char operands[255];
	std::cin >> a;
	int length = strlen(a);
	for (int i = 0; i < length; i++) {
		if (a[i] == '(' || a[i] == ')') {
		}
		else if (a[i] >= '0' && a[i] <= '9') {

		}
		else if (a[i] == '+' || a[i] == '-'|| a[i] == '*'|| a[i] == '/') {
		}
		else {
			std::cout << "Incorrect input " << a[i];
			break;
		}
	}		
	std::cout << length << std::endl;
}
