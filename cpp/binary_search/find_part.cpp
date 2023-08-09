#include <algorithm>
#include <iostream>

int	N;
int	M;
int	*arr_shop;
int	*arr_cust;

int	binary_search(int start, int end, int target)
{
	int	mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr_shop[mid] == target)
			return (mid);
		else if (arr_shop[mid] > target)
			end = mid -1;
		else
			start = mid + 1;
	}
	return (-1);
}

int	main(void)
{
	std::cin >> N;
	arr_shop = new int[N];
	for (int i=0; i<N; i++)
		std::cin >> arr_shop[i];
	std::cin >> M;
	arr_cust = new int[M];
	for (int i=0;i<M; i++)
		std::cin >> arr_cust[i];
	std::sort(arr_shop, arr_shop + N);
	for (int i=0; i<M;i++)
	{
		if (binary_search(0, N-1, arr_cust[i]) != -1)
			std::cout << "yes" << " ";
		else
			std::cout << "no" << " ";
	}
}