/*
계수 정렬(count sort)
	: 별도의 리스트를 선언하고, 그 안에 정렬에 대한 정보를 담는다.
	- 시간 복잡도
		최적의 경우 O(N + K)
	- 사용성
		조건부 사용 가능하지만, 매우 빠름
			- 필수 조건
				정수
				데이터의 크기 범위가 제한적 (최대 최솟값의 차가 백만 이하)
			- 추천 조건
				중복된 값이 여러개 나올때
				값들이 촘촘할때
*/

#include <iostream>

void	count_sort(int *arr,int max, int arr_size)
{
	int	list[max+1];
	for (int i=0; i<max+1; i++)
		list[i] = 0;

	for (int i=0; i<arr_size; i++)
		list[arr[i]]++;
	
	for (int i=0; i<max+1; i++)
		for (int j=0; j<list[i]; j++)
			std::cout << i << " ";
}

int	main(void)
{
	int	arr[15] = {7,5,9,0,3,1,6,2,9,1,4,8,0,5,2};

	count_sort(arr, 9, 15);
}