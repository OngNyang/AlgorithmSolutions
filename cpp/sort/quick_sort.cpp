/*
퀵 정렬(quick_sort)
	: 기준이 될 값을 선택하고 그 기준보다 큰 수와 작은 수의 위치를 바꾼다.
	- 시간 복잡도
		O(NlogN)
	- 사용성
		가장 빠르다. 거의 다 정렬되 있는 경우 삽입 정렬을 사용하고,
		그 이외의 경우 모두 퀵 정렬을 사용해준다.


*/

#include <iostream>

void	quick_sort(int arr[], int start, int end)
{
	int	pivot = start;
	int	left = start + 1;
	int	right = end;
	int	temp;

	if (start >= end)
		return ;
	while (left <= right)
	{
		while (left <= end && arr[left] <= arr[pivot])
			left++;
		while (right > start && arr[right >= arr[pivot]])
			right--;
		if (left > right)
		{
			temp = arr[pivot];
			arr[pivot] = arr[right];
			arr[right] = temp;
		}
		else
		{
			temp = arr[right];
			arr[right] = arr[left];
			arr[left] = temp;
		}
		quick_sort(arr, start, right-1);
		quick_sort(arr, right+1, end);
	}
}

int	main(void)
{
	int	arr[] = {7,5,9,0,3,1,6,2,4,8};
	
	quick_sort(arr, 0, 10-1);
	for (int i=0; i<10; i++)
	{
		std::cout << arr[i] << " ";
	}
}