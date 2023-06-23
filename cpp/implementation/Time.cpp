#include <iostream>
#include <string>

/*
정수 N이 입력되면 00시 00분 00초부터 N시 59분 59초까지의 모든 시각 중에서 3이 하나라도 포함되는 모든 경우의 수를 구하는 프로그램을 작성하시오. 예를 들어 1을 입력했을 때 다음은 3이 하나라도 포함되어 있으므로 세어야 하는 시각이다.
00시 00분 03초
00시 13분 30초

반면에 다음은 3이 하나도 포함되어 있지 않으므로 세면 안 되는 시각이다.
00시 02분 55초
01시 27분 45초
[입력 조건]
첫째 줄에 정수 N이 입력된다. (0 <= N <= 23)
[출력 조건]
00시 00분 00초부터 N시 59분 59초까지의 모든 시각 중에서 3이 하나라도 포함되는 모든 경우의 수를 출력한다.

*/

/*
이렇게까지 장황하게 풀어야할 문제는 아닌것 같지만, 클래스를 만들고 논리적으로 만든것 같아 나쁜 습관은 아닌것 같다. 하지만 코딩 테스트에서도 이런 방식이 유리할지는 의문이다.
*/

class time
{
	public:
			time(void);
			std::string getter(void);
			void increase_hour(void);
			void increase_min(void);
			void increase_sec(void);
	private:
			int hour;
			int min;
			int sec;
};

time::time(void)
{
	this->hour = 0;
	this->min = 0;
	this->sec = 0;
}

std::string time::getter(void)
{
	std::string str = std::to_string(hour)+std::to_string(min) +	std::to_string(sec);
	return (str);
}

void time::increase_min(void)
{
	this->min++;
	if (this->min >= 60)
	{
		this->min = 0;
		increase_hour();
	}
}

void time::increase_hour(void)
{
	this->hour++;
}

void time::increase_sec(void)
{
	this->sec++;
	if (this->sec >= 60)
	{
		this->sec = 0;
		increase_min();
	}
}

int main() {
	int n;
	std::cout << "typing" <<std::endl;
	std::cin >> n;
	class time obj;
	int cnt =0;
	bool flag = false;

	std::string target = std::to_string(n) + "59"+"59";
	std::string now;
	while (1)
		{
			flag = false;
			now = obj.getter();
			if (now == target)
				break;
			for (int i=0;i<now.size();i++)
				{
			if (now[i] =='3')
				flag = true;
				//cnt++;
				}
			if (flag == true)
				cnt++;
			obj.increase_sec();
		}
	std::cout << cnt;
}