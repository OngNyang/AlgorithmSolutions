#include <iostream>
#include <algorithm>

class	Student
{
	public:
			std::string	name;
			int			score;
			Student(void)
			{
				this->name = "unknown";
				this->score = -42;
			}
			Student(std::string name, int score)
			{
				this->name = name;
				this->score = score;
			}
			bool	operator<(const Student &other) const
			{
				return (this->score < other.score);
			}
			bool	operator>(const Student &other) const
			{
				return (this->score > other.score);
			}
};

int		N;
Student	*arr;
// std::string	*arr_name;
// int			*arr_score;


int	main(void)
{
	std::cin >> N;
	std::cin.ignore();
	arr = new Student[N];
	// arr_name = new std::string[N];
	// arr_score = new int[N];

	for (int i=0; i<N; i++)
	{
		// std::cin >> arr_name[i] >> arr_score[i];
		std::cin >> arr[i].name >> arr[i].score;
	}
	std::sort(arr, arr + N);

	//pair를 사용해야 하나? 그러면 sort 하기 어렵자너

	for (int i=0; i<N; i++)
	{
		// std::cout << arr_name[i] << " " << arr_score[i] << std::endl;
		std::cout << arr[i].name << " ";
	}
}