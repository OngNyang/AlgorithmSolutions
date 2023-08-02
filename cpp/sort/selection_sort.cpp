/*
선택 정렬(selection sort)
	: 가장 작은 데이터를 선택해 (정렬안된)가장 앞의 데이터와 교체하는 과정을 반복
	- 시간 복잡도
		O(N^2)
		매우 느림.
	- 사용성
		느리지만, 리스트에서 최솟값을 찾을때 알고리즘의 코드를 응용할수 있다.
*/


#include <iostream>

void	selection_sort(int	arr[], int arr_size)
{
	int	idx_min = 0;

	for (int i=0; i<arr_size; i++)
	{
		idx_min = i;
		for (int j=i+1; j<arr_size; j++)
			if (arr[j] < arr[idx_min])
				idx_min = j;
		if (i != idx_min)
		{
			int	temp = arr[i];
			arr[i] = arr[idx_min];
			arr[idx_min] = temp;
		}
	}
}

int	main(void)
{
	int	arr[10] = {7,5,9,0,3,1,6,2,4,8};
	int	arr_size = 10;
	
	selection_sort(arr, 10);
	for (int i=0; i<arr_size; i++)
		std::cout << arr[i] << " " << std::endl;
}