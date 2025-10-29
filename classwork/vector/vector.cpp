#include  <iostream>
#include "vector.h"


void vector::push_back(int n)
        {
                if(size >= capacity)
                       resize();
                data[size] = n;
                size++;
        }

vector::vector(): size(0), capacity (/*1024*/ 0 ), data (0)
	{
		resize();
	}

vector::vector (int capacity_): size(0), capacity(capacity_), data(0)
	{
		resize();
	}

vector::~vector()
	{
        if(data != 0)
		delete[] data;
	}
	int vector::get_size()
	{
	return size;
	};
	
	void vector::print()
	{
	 	std::cout << "size: " << size << "; capacity: " << capacity  << std::endl;
	};
	
	void vector::resize()
	{
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
