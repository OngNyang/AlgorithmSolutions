/*
조합 (combination)
	: 주어진 집합에서 원소들을 순서에 상관없이 선택하는 방법의 수를 의미합니다. 
		- 순서가 상관없을때 사용
	- nCr
	- n개의 원소중 r개를 순서 없이 선택
		n! / ((n-r)! * r!)

*/


#include <iostream>
#include <vector>


void	generate_combinations(std::vector<int>& nums, int k, int start, std::vector<int>& current)
{
	if (current.size() == k)
	{
		for (int num : current)
			std::cout << num << " ";
		std::cout << std::endl;
		return ;
	}
	else
	{
		for (int i = start; i<nums.size(); i++)
		{
			current.push_back(nums[i]);
			generate_combinations(nums, k, i+1, current);
			current.pop_back();
		}
	}
}

int	main(void)
{
	std::vector<int>	nums = {1,2,3,4};
	std::vector<int>	current;
	int k = 2;

	generate_combinations(nums, k, 0, current);
}


