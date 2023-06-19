/*
다양한 수로 이뤄진 배열이 있을 때 주어진 수들을 M번 더해 가장 큰 수를 만드는 법칙.
단, 배열의 특정한 인덱스에 해당하는 수가 K번을 초과해 더해질수 없다.

ex)	arr = {2,4,5,4,6}, M = 8, K = 3
	-> 6 + 6 + 6 + 5 + 6 + 6 + 6 + 5 = 46

입력 조건
	첫째 줄에 N(2 <= N <= 1,000), M(1 <= M <= 10,000), K(1 <= K <= 10,000)의 자연수가 주어지며,
	각 자연수는 공백으로 구분한다.
	둘째 줄에 N개의 자연수가 주어진다. 각 자연수는 공백으로 구분한다. 단 자연수는 1이상 1만 이하.
	입력으로 주어지는 K는 항상 M 이하인다.

출력 조건
	첫째 줄에 큰 수의 법칙에 따라 더해진 답을 출력
*/

/*
IDEA
	가장 큰수를 K번 더하고, 두번째로 큰수를 1번 더하고, 다시 가장 큰 수를 K번 더하고...
*/

#include <iostream>
#include <algorithm>

int main(void)
{
	int	N, M, K;
	std::cin >> N >> M >> K;

	int	arr[N];
	for (int i=0; i<N; i++)
	{
		std::cin >> arr[i];
	}
	std::sort(arr, arr + N);

	int	first = arr[N - 1];
	int	second = arr[N - 2];
	int	res = 0;

	int	i=0;
	while (1)
	{
		for (int j=0; j<K; j++)
		{
			res += first;
			i++;
			if (i == M)
				break;
		}
		if (i == M)
			break ;
		res += second;
		i++;
		if (i == M)
			break ;
	}
	std::cout << res << std::endl;
}