/*
A의 모든 원소의 합이 최대가 되게 하려면...

A정렬, B정렬.
while (K번 제한)
{
	if (B에서 제일 큰거 > A에서 제일 작은거)
	{
		교체
	}
	else
	{
		break ;
	}

}


*/


#include	<iostream>
#include	<algorithm>

int	N;
int	K;
int	*A;
int	*B;

int	main(void)
{
	int	sum = 0;

	std::cin >> N >> K;
	A = new int[N];
	B = new int[N];
	for (int i=0; i<N; i++)
	{
		std::cin >> A[i];
	}
	for (int i=0; i<N; i++)
	{
		std::cin >> B[i];
	}
	std::sort(A, A+N);
	std::sort(B, B+N, std::greater<int>());
	// for (int i=0; i<N; i++)
	// {
	// 	std::cout << A[i] << " " << B[i] << std::endl;
	// }
	int i = 0;
	while (i < K)
	{
		if (B[i] > A[i])
		{
			A[i] = B[i];
		}
		else
		{
			break ;
		}
		i++;
	}
	for (int i=0; i<N; i++)
	{
		std::cout << A[i] << std::endl;
		sum += A[i];
	}
	std::cout << sum << std::endl;

	delete [] A;
	delete [] B;

}