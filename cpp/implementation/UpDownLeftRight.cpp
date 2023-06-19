/*
설명
	여행가 A는 N X N 크기의 정사각형 공간 위에 서 있다.
	이 공간은 1 x 1 크기의 정사각형으로 나 누어져 있다. 
	가장 왼쪽 위 좌표는 (1, 1)이며, 가장 오른쪽 아래 좌표는 (N, N)에 해당한다. 
	여행 가 는 상, 하, 좌, 우 방향으로 이동할 수 있으며, 시작 좌표는 항상 (1,1)이다. 
	우리 앞에는 여행 카 A가 이동할 계획이 적힌 계획서가 놓여 있다
	계획서에는 하나의 줄에 띄어쓰기를 기준으로 하여 L. R, U, D 중 하나의 문자가 반복적으로 적혀 있다. 각 문자의 의미는 다음과 같다.
	• L: 왼쪽으로 한 칸 이동
	• R: 오른쪽으로 한 칸 이동
	• U: 위로 한 칸 이동
	• D: 아래로 한 칸 이동
	이때 여행가 A가 N X N 크기의 정사각형 공간을 벗어나는 움직임은 무시된다. 예를 들어 (1, 1)
	의 위치에서 L 혹은 U를 만나면 무시된다.
	계획서가 주어졌을때, 여행가 A가 최종적으로 도착할 지점의 좌표를 출려하는 프로그램을 작성하시오.

입력 조건
	• 첫째 줄에 공간의 크기를 나타내는 N이 주어진다. (1 ≤ N ≤ 100)
	• 둘째 줄에 여행가 A가 이동할 계획서 내용이 주어진다. (1 ≤ 이동 횟수 ≤ 100)
출력 조건 
	• 첫째 줄에 여행가 A가 최종적으로 도착할 지점의 좌표 (X, Y)를 공백으로 구분하여 출력한다.
*/

/*
IDEA
	(0,0)에서 시작하는게 기본이지만, 문제에선 (1,1)에서 시작하니 최종적으로 좌표값에 1씩 더해서 출력해야함.


*/

/*
배운점
	제한이 따로 없고, 개행문자 올때까지 입력을 받는 경우
느낀점
	저자 처럼 
	int dx[4] = {0, 0, -1, 1};
	int	dy[4] = {-1, 1, 0, 0};
	char moveTypes[4] = {'L', 'R', 'U', 'D'};
	이렇게 하는게 깔끔하긴 하다.
	하지만, 나는 42서울에서 c로 개발하던 스타일대로 만들어 봤다. 가독성은 더 좋은것 같은데, 좀 더 어려운 과제를 만나면 힘들지도 모르겠다.
*/

#include <iostream>
#include <string>

typedef struct s_pos
{
	int x;
	int y;
	int N;
}				t_pos;

void	move_u(t_pos *pos)
{
	if (pos->x > 1)
		pos->x -= 1;
}
void	move_d(t_pos *pos)
{
	if (pos->x < pos->N)
		pos->x += 1;
}
void	move_l(t_pos *pos)
{
	if (pos->y > 1)
		pos->y -= 1;
}
void	move_r(t_pos *pos)
{
	if (pos->y < pos->N)
		pos->y += 1;
}


int	main(void)
{

	int	N;
	std::cin >> N;
	std::cin.ignore();

	t_pos	pos;
	pos.x = 1;
	pos.y = 1;
	pos.N = N;

	std::string	orderList;
	getline(std::cin, orderList);

	for (int i=0; i<orderList.size(); i++)
	{
		if (orderList[i] == 'U')
			move_u(&pos);
		else if (orderList[i] == 'D')
			move_d(&pos);
		else if (orderList[i] == 'L')
			move_l(&pos);
		else if (orderList[i] == 'R')
			move_r(&pos);
	}

	std::cout << pos.x << " " << pos.y << std::endl;
}