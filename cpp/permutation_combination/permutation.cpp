/*
순열 (permutation)
	: 주어진 집합에서 원소들을 모든 가능한 순서로 배열하는 방법의 수를 의미
		- 순서가 중요할 경우 사용
	- nPr
	- n개의 원소중 r개를 선택
		n! / (n-r)!

준비물
	수열 벡터, 임시팔레트(벡터), 방문여부 벡터

재귀함수
	탈출 조건
		수열의 갯수를 다 채운다면 탈출
	그 외에

어려운점
	1234까진 이해하는데, 1243이 어떻게 나오는지 이해하는게 어려웠다.

*/


#include <iostream>
#include <vector>

void	print_vect(std::vector<bool>& used, std::vector<int>& current)
{
	for (int i=0; i<used.size(); i++)
	{
		std::cout << used[i] ;
	}
	std::cout << "||" << " ";
	for (int i=0; i<current.size(); i++)
	{
		std::cout << current[i] << " ";
	}
	std::cout << std::endl;
}

void	generate_permutations(std::vector<int>& nums, std::vector<int>& current, std::vector<bool>& used)
{
	if (current.size() == nums.size())
	{
		for (int num : current)
		{
			std::cout << num << "";
		}
		std::cout << std::endl;
		return ;
	}
	else
	{
		for (int i=0; i<nums.size(); i++)
		{
			std::cout << "idx : " << i << std::endl;
			if (used[i] == false)
			{
				used[i] = true;
				current.push_back(nums[i]);

				print_vect(used, current);

				generate_permutations(nums, current, used);
				current.pop_back();
				used[i] = false;

				print_vect(used, current);

			}
		}
	}

}

int	main(void)
{
	std::vector<int>	nums = {1,2,3,4};
	std::vector<int>	current;
	std::vector<bool>	used(nums.size(), false);
	generate_permutations(nums, current, used);
}
