/*
행복왕국의 왕실정원은 체스판과 같은 8 * 8좌표 평면이다. 
왕실 정원의 특저안 한 칸에 나이트가 서있다. 나이트는 매우 충성스러운 신하로서 매일	
무술을 연마한다. 나이트는 말을 타고 있기 때문에 이동을 할때는 L자 형태로만 
이동할 수 있으며 정원 밖으로는 나갈 수 없다. 나이트는 특정한 위취에서 다음과 같은 2가지 
경우로 이동할 수 있다.	
1. 수평으로 두 칸 이동한 뒤에 수직으로 한 칸 이동하기 
2. 수직으로 두칸 이동한 뒤에 수평으로 한 칸 이동하기 

이처럼 8 * 8 좌표 평면상에서 나이트의 위치가 주어졌을 때	
나이트가 이동할 수 있는 경우의 수를 출력하는 프로그램을 작성하시오. 
이떄 왕실의 정원에서 행 위치를 표현할 떄는 1부터 8로 표현하며, 열 위치를 표현 
할 때는 a부터 h까지 로 표현한다. 

예를 들어 만약 나이트가 a1에 있을 때 이동할 수 있는 경우의 수는 다음 2가지이다. 
a1의 위치는 좌표 평면에서 구석의 위치에 해당하며 나이트는 정원의 밖으로는 나갈 수 없기 
때문이다. 

1. 오른쪽 두 칸 이동 후 아래로 한 칸 이동하기(c2) 
2. 아래로 두 칸 이동 후 오른쪽으로 한 칸 이동하기(b3) 

또 다른 예로 나이트가 c2에 위치해 있다면 나이트가 이동할 수 있는 경우의 수는 6가지이다. 

입력조건 
- 첫째 줄에 8 * 8 좌표 평면상에서 현재 나이트가 위치한 곳의 좌표를 나타내는 두 문자로 
구성된 문자 열이 입력된다. 입력문자는 a1처럼 열과 행으로 이뤄진다. 

- 첫째 줄에 나이트가 이동할 수 있는 경우의 수를 출력하시오. 
*/

/*
idea
이동가능 경로 기본 8개
없는길로는 못감 그만큼 경우의 수에서 차감

인자를 0,0으로 치환
*/




#include <iostream>

bool check(int x, int y)
{
	if (x < 0 || x >7)
		return (false);
	if (y < 0 || y >7)
		return (false);
	return(true);
}

int main() {
	std::string input;
	std::getline(std::cin, input);
	int cnt = 0;
	int x = input[0] - 'a';
	int y = input[1] - '1';

	if(check(x +2, y+1) == true)
		cnt++;
	if(check(x +2, y-1) == true)
		cnt++;
	if(check(x -2, y+1) == true)
		cnt++;
	if(check(x -2, y-1) == true)
		cnt++;
	if(check(x +1, y+2) == true)
		cnt++;
	if(check(x +1, y-2) == true)
		cnt++;
	if(check(x -1, y+2) == true)
		cnt++;
	if(check(x -1, y-2) == true)
		cnt++;
	std::cout << cnt;
}