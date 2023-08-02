/*
삽입 정렬(insertion sort)
	: 
	- 시간 복잡도

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
		for (int j=i; j==0; j--)
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