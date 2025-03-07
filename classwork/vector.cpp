#include <iostream>

struct vector
{
	int size;
	vector(){
		std::cout << "callvector" << std::endl;

	int size, capacity;
	int *data;
	vector(): size(0), capacity (/*1024*/ 0 ), data (0)
	{

		resize();
		std::cout << "vector()" << std::endl;
	}

	vector (int capacity_): size(0), capacity(capacity_), data(0)
	{
		resize();
		std::cout << "vector(int)" << std::endl;

	}

	~vector(){
                std::cout << "~callvector" << std::endl;
        }

                std::cout << "~vector()" << std::endl;
        	if(data != 0)
		{
			delete[] data;
		}
	}

	int get_size(){
	return size;

	};
	void print(){
	 	std::cout << "size: " << size << "; capacity: " << capacity  << std::endl;
	};
	void resize(){
	// check if capacity !=0
		
		if (capacity <= 0)
			capacity = 1;
		if (data == 0)
                {
                        data = new int[capacity];
                	return;
		}
		capacity *= 2;
		int *temper = new int[capacity];
		for (int i= 0; i < size; i++)
		{
		 	temper [i] = data [i];
		}
		delete[] data;
		data = temper; 
	};
	void vector::push_back(int n)
	{
		if(size >= capacity) 
		       resize();	
		data[size] = n;
		size++;
	}

};

int main ()
{
	{
	vector v;
	v.size=10;
	std::cout << v.size << " " << v.get_size() << std::endl;
	for (int i = 0; i < 1024; i++)
		v.push_back (i);
	for (int i = 0; i < v.size; ++i)
	{
		std::cout << v.data[i] << std::endl;
	}
	}
	vector p;
        p.size=5;
        std::cout << p.size << " " << p.get_size() << std::endl;
	vector p(50);
