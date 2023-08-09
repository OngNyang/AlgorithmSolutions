#include <algorithm>
#include <iostream>

int	N;
int	*arr;

int	main(void)
{
	std::cin >> N;
	arr = new int[N];
	for (int i=0; i<N; i++)
		std::cin >> arr[i];
	std::sort(arr, arr+N, std::greater<int>());
	for (int i=0; i<N; i++)
	{
		std::cout << arr[i] << " ";
	}
}