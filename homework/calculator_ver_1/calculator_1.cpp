#include <iostream>
#include<stack>

using namespace std;
 struct Leksems
{
	char type;
	double value;
 };
void Maths (stak <Leksems> & ) 
int main()
 { char n;
   stack<Leksems> stack_n;
   stack<Leksems> stack_o;
   Leksems item;
while (1) {
   n = cin.peek();

    if( n >= '0' && n <= '9')//condition for numbers//
	{ cin >> value; 
		item.type = '0';
		item.value = value;
		stack_n.push (item);
		conti nue;} 
    if (n == '+' || n == '-'|| n == '*'|| n == '/')
    {
	       item.type = '0';
                item.value = value;
      stack_o.push (item);
     cin.ignore();
    continue;
    }
}




} 
