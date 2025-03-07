#include  <iostream>
#include "vector.h"


int main ()
{
        vector v;
        for (int i = 0; i < 128; i++)
                v.push_back (i);
        for (int i = 0; i < v.size; ++i)
                std::cout << v.data[i] << " ";
        std::cout << '\n';
}
