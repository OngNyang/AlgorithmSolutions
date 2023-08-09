#include <iostream>
#include <algorithm>

int	main(void)
{
	int	size = 10;
	int	arr[10] = {7,5,9,0,3,1,6,2,4,8};

	std::sort(arr, arr+10);
	for (int i=0; i<size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::sort(arr, arr+size, std::greater<int>());
	for (int i=0; i<size; i++)
	{
		std::cout << arr[i] << " ";
	}
}