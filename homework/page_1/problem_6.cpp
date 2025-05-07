# include <iostream>

int main(){
	float P,R,I;
	int T;
	std::cout << "input your suffen: "<< '\n';
	std::cin >> P;
	std::cout << "input your interest rates: "<< '\n';
	std::cin >> R;
	std::cout << "input your loan period: "<< '\n';
       	std::cin >> T;
	I = (P*T*R)/100;
	int a = I;
	std::cout <<"result': "<<  a << '\n';
	std::cout << "result: " << I << '\n';
}
