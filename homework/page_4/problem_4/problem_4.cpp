#include <iostream>
int main() {
	int size;
	std::cin >> size;
        int* arr = new int[size-1];
        
	for (int i = 0; i < size-1; i++) 
	{
                arr[i] = i+2;
        }

        for (int i = 0; i < size-1; i++) 
	{
                if (arr[i] != 0) 
		{
                        for (int j = (arr[i]*2)-2; j < size-1; j += arr[i]) 
			{
                                arr[j] = 0;
                        }
                }
	}
	
	int a = 0, j = 0;
	
	for (int i = 0; i < size-1; i ++)
	{ 	
		if (arr[i] != 0) 
		{
			a++;
		}
	}
		    	
	int* arr2 = new int [a];

	for ( int i = 0; i < size-1 ; i ++)
	{
		if (arr[i]!=0)
		{ 
			arr2[j++] = arr[i];
		}
	}

	delete[] arr;

	for ( int i = 0; i < j; i ++)
	{
		while (size % arr2[i] == 0)
		{	
			size = size/arr2[i]; 
		       	std::cout << arr2[i] << ", "; 
		}
		if (size == arr2[i]) {
			std::cout << arr2[i];
			break;
		}
	}
	std::cout << '\n';
	delete[] arr2;
	return 0;
}

