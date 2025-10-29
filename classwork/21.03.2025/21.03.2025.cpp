#include <iostream>
template <typename T> 
T sum ( T a, T b)
{
       	
	return a+b; 
}
float sum2 (float a, float b)
{ 
	return a+b;
}
int main()
{
	int  a = 0, b = 1, c;
	c = sum (a,b);
	std::cout << c << std::endl;
	std::cout<< sum (4.3, 5.7) << std::endl;
	return 0;

}
