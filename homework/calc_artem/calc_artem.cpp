#include <iostream>
using namespace std;

int stringToInt(const char* str) {
  int num = 0;
  for (int i = 0; str[i] != '\0'; i++) {
	  cout << " " << num;
    num = num * 10 + (str[i] - '0');
    cout << " " << num;
  }
  cout << endl;
  return num;
}

int calculate(int a, int b, char op) {
  if (op == '+') return a + b;
  if (op == '-') return a - b;
  if (op == '*') return a * b;
  if (op == '/') return a / b;
  return 0;
}

int main() {
  char input[100];
  while (true) {
    cin >> input;

    int result = 0;
    char currentOp = '+';
    char currentNumber[10];
    int numIndex = 0;
	int bigin = 0;
    for (int i = 0; input[i] != '\0'; i++) {
      char ch = input[i];
//100+20-30 
      if (ch >= '0' && ch <= '9') {
        currentNumber[numIndex++] = ch;
	if (numIndex > bigin) {
		bigin = numIndex;
	}
	for(int j = 0; j < numIndex; j++) {
//			cout << currentNumber[j] << " ";
	}
      }
      else {
	 if (numIndex > 0) {
//		 cout << "   ";
//		 for (int j = 0; j < bigin; j++) {
//			 cout << currentNumber[j] << " ";
//		 }
//		 cout << "   ";
         	 currentNumber[numIndex] = '\0';
//		 for (int j = 0; j < bigin; j++) {
//                         cout << currentNumber[j] << " ";
//                 }
		 int num = stringToInt(currentNumber);
        	  result = calculate(result, num, currentOp);
        	  numIndex = 0;
		  cout << "    " << num;
        }
	currentOp = ch;
      }
      cout << endl;
    }

    if (numIndex > 0) {
//	    cout << "   ";
//                 for (int j = 0; j < bigin; j++) {
//                         cout << currentNumber[j] << " ";
//                 }
//                 cout << "   ";
                 currentNumber[numIndex] = '\0';
//                 for (int j = 0; j < bigin; j++) {
//                         cout << currentNumber[j] << " ";
//                 }
    currentNumber[numIndex] = '\0';
    int num = stringToInt(currentNumber);
    result = calculate(result, num, currentOp);
    cout << "    " << num << endl;
  }

    cout << result << endl;
    break;
  }

  return 0;
}
