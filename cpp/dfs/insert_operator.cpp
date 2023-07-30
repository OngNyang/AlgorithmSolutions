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





// #include <iostream>
// #include <vector>
// using namespace std;


// void generatePermutations(vector<int>& nums, vector<int>& permutation, vector<bool>& used) {
//     // if (permutation.size() == nums.size()) { // 기저 조건: 수열의 크기와 같으면 출력
//     //     for (int num : permutation) {
//     //         cout << num << " ";
//     //     }
//     //     cout << endl;
//     //     return;
//     // }

//     // for (int i = 0; i < nums.size(); ++i) {
//     //     if (!used[i]) {
//     //         used[i] = true; // 해당 원소를 사용했다고 표시
//     //         permutation.push_back(nums[i]); // 수열에 해당 원소 추가
//     //         generatePermutations(nums, permutation, used); // 재귀 호출
//     //         permutation.pop_back(); // 마지막 원소 제거
//     //         used[i] = false; // 해당 원소를 사용하지 않았다고 표시
//     //     }
//     // }
// 	if (permutation.size() == nums.size())
// 	{
// 		for (int i=0; i<permutation.size(); i++)
// 			std::cout << permutation[i] << " ";
// 		// for (int num : permutation)
// 		// 	std::cout << num << " ";
// 		std::cout << std::endl;
// 		return ;
// 	}
// 	for (int i=0; i<nums.size(); ++i)
// 	{
// 		if (used[i] == false)
// 		{
// 			used[i] = true;
// 			permutation.push_back(nums[i]);
// 			generatePermutations(nums, permutation, used);
// 			permutation.pop_back();
// 			used[i] = false;
// 		}
// 	}

// }

// int main() {
//     vector<int> nums;
// 	nums.push_back(1);
// 	nums.push_back(2);
// 	nums.push_back(3);

//     vector<int> permutation;
//     vector<bool> used(nums.size(), false);

//     generatePermutations(nums, permutation, used);

//     return 0;
// }


#include <iostream>
#include <vector>

void	generate_permutations(std::vector<char>& nums, std::vector<int>& permutation, std::vector<bool>& used)
{
	std::cout << permutation.size();
	if (permutation.size() == nums.size())
	{
		for (int i=0; i<permutation.size(); i++)
			std::cout << permutation[i] << " ";
		// for (int num : permutation)
		// 	std::cout << num << " ";
		std::cout << std::endl;
		return ;
	}
	for (int i=0; i<nums.size(); i++)
	{
		if (used[i] == false)
		{
			std::cout << i << " ";
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
	int	N;
	std::cin >> N;
	int	arr_num[N];
	int	arr_op[4];
	std::vector<char>	nums;
	std::vector<int>	permutation;
	std::vector<bool>	used(nums.size(), false);

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

	generate_permutations(nums, permutation, used);

}