#include <string>
#include <vector>
#include <queue>

/*
의문
	vector queue는 각각 어떤 상황일때 더 유리할까?


*/


using namespace std;

std::queue<char> q;

bool	balanced_str(string p)
{
	int l=0;
	int r=0;

	if (p == "")
		return (false);
	for (int i=0; p.size(); i++)
	{
		if (p[i] == '(')
			l++;
		if (p[i] == ')')
			r++;
	}
	if (l == r)
		return (true);
	else
		return (false);
}


bool	correct_str(string p)
{
	//좌측 괄호 갯수보다 우측괄호 객수가 많아지는 순간이 오면 짝 안맞는거임
	int	cnt = 0;

	for (int i=0; i<p.size(); i++)
	{
		if (p[i] == '(')
			cnt++;
		else
		{
			cnt--;
			if (cnt < 0)
				return (false);
		}
	}
	return (true);
}

string solution(string p) {
	string answer;
	string	u;
	string	v;

	if (p == "")
		return ("");
	for (int i=0; i<p.size(); i++)
	{
		u = p.substr(0, i);
		if (balanced_str(u) == true)
		{
			if (i == p.size() - 1)
				v = "";
			else
				v = p.substr(i+1, p.size() - 1);
			break ;
		}
	}
	if (correct_str(u) == true)
		solution(v);
	else
		


}