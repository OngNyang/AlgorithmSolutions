/*
	최소 연산 -> 5,3으로 나누어 떨어지게 만드는게 좋을지도
	1부터 해당 숫자까지 최소 연산 횟수를 리스트에 저장.

1 : 1
2 : 2/2 = 1
3 : 3/3 = 1
4 : 4/2=2, 2/2=1
  : 4-1=3, 3/3=1
5 : 5/5=1
6 : 6-1=5, 5/5=1
  : 6/3=2, 2/2=1
7 : 7-1=6,
...
16 : 16/2=8, 8/2=4, 4/2=2, 2/2=1
	 16-1=15,15/5=3, 3/3=1
17 : 17-1=16, 16/2=8, 8/2=4, 4/2=2, 2/2=1
	 17-1=16, 16-1=15,15/5=3, 3/3=1
18 : 18/3=6, 6/3=2, 2/1=1

결국 관건은 나누기보다 1을 빼주는게 이득인 상황이 있다는것.

일단 어떤걸로도 나누어 떨어지지 않으면 -1
나누어 떨어진다면 나누는게 나을지 -1을 하는게 나을지 비교

아니다, 1빼기, 5로 나누기, 3으로 나누기, 2로 나누기 다 시도해서 비교해야

*/

#include <iostream>
#include <algorithm>

int	X;
int	*arr;
int	*cnt;
//	-1 /5 /3 /2


int	main(void)
{
	int	n;

	std::cin >> X;
	arr = new int[X+1];
	cnt = new int[4];
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 1;
	for (int i=6; i<X+1; i++)
	{
		int	result;
		n = i;
		for (int j=0; j<4; j++)
			cnt[j] = -42;
		cnt [0] = arr[n-1] + 1;
		if (n%5 == 0)
			cnt[1] = arr[n/5] + 1;
		if (n%3 == 0)
			cnt[2] = arr[n/3] + 1;
		if (n%2 == 0)
			cnt[3] = arr[n/2] + 1;
		std::sort(cnt, cnt+4);
		for (int j=0; j<4; j++)
		{
			if (cnt[j] < 0)
				continue ;
			else
			{
				result = cnt[j];
				break ;
			}
		}
		arr[i] = result;
	}
	std::cout << arr[X] << std::endl;
}