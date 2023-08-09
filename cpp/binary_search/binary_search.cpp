#include <iostream>

int	binary_search(std::string *arr, std::string target, int start, int end)
{
	int	mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (-1);
}

int	main(void)
{
	int	n = 10;
	std::string	target = "다";
	std::string	arr[10] = {"가", "나", "다", "라", "마","바", "사", "아", "자", "차"};

	int	result = binary_search(arr, target, 0, n-1);
	if (result < 0)
		std::cout << "there is no target you want.";
	else
		std::cout << result + 1;
}