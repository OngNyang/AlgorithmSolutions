/*
삽입 정렬(insertion sort)
	: 정렬된 부분과 안된 부분으로 나누어 정렬 안된 부분의 가장 앞의 값을 정렬된 부분에 삽입
	- 시간 복잡도
		O(N^2) ~ O(N)
	- 사용성
		데이터가 거의 정렬되어 있을때 매우 효율적.

*/

#include <iostream>

int	arr_size = 10;

void	insertion_sort(int *arr)
{
	int	temp;

	for (int i=1; i<arr_size; i++)	//정렬됐는지 인덱스
	{
		for (int j=i; j != 0; j--)
		{
			if (arr[j] < arr[j-1])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
			else
				break ;
		}
	}
}

int	main(void)
{
	int	arr[] = {7,5,9,0,3,1,6,2,4,8};
	insertion_sort(arr);

	for (int i=0 ;i<10; i++)
	{
		std::cout << arr[i] << " ";
	}
}