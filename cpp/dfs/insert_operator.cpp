/*
수열	N개
연산자	N-1개	+ - * /

수와 수 사이에 연산자를 하나 넣어서 수식을 만듦
	수의 순서를 바꿀수 없음

1 2 3 4 5 6
+ + - * /
5! / 2 == 60

*/

/*
ideas

일단 (N-1)! 의 경우가 있다고 생각하고 계산을 하면 될듯?
q에 넣어야 하나?



*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>	vect_result;
int	*arr_num;
int	N;

int	operation(int n1, int n2, char op)
{
	int	result = 0;

	if (op == '+')
		result = n1 + n2;
	if (op == '-')
		result = n1 - n2;
	if (op == '*')
		result = n1 * n2;
	if (op == '/')
		result = n1 / n2;
	return (result);
}

void	generate_permutations(std::vector<char>& nums, std::vector<int>& permutation, std::vector<bool>& used)
{
	if (permutation.size() == nums.size())
	{
		// for (int i=0; i<permutation.size(); i++)
		// 	std::cout << permutation[i] << " ";
		// std::cout << std::endl;
		
		int temp = arr_num[0];
		for (int i=0; i<N-1; i++)
		{
			temp = operation(temp, arr_num[i+1], permutation[i]);
		}
		vect_result.push_back(temp);
		return ;
	}
	for (int i=0; i<nums.size(); i++)
	{
		if (used[i] == false)
		{
			used[i] = true;
			permutation.push_back(nums[i]);
			generate_permutations(nums, permutation, used);
			permutation.pop_back();
			used[i] = false;
		}
	}
}

int	main(void)
{
	std::cin >> N;
	// int	arr_num[N];
	int	arr_op[4];
	std::vector<char>	nums;
	std::vector<int>	permutation;

	arr_num = new int[N];

	std::cin.ignore();
	for (int i=0; i<N; i++)
		std::cin >> arr_num[i];
	std::cin.ignore();
	for (int i=0; i<4; i++)
		std::cin >> arr_op[i];
	std::cin.ignore();

	for (int j=0; j<arr_op[0]; j++)
		nums.push_back('+');
	for (int j=0; j<arr_op[1]; j++)
		nums.push_back('-');
	for (int j=0; j<arr_op[2]; j++)
		nums.push_back('*');
	for (int j=0; j<arr_op[3]; j++)
		nums.push_back('/');

	std::vector<bool>	used(nums.size(), false);


	generate_permutations(nums, permutation, used);
	sort(vect_result.begin(), vect_result.end());
	std::cout << vect_result[vect_result.size()-1] << std::endl;
	std::cout << vect_result[0] << std::endl;

}