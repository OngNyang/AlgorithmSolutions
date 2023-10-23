/**
1. 문제 유형
	스택
2. 알고리즘
	스택
3. 자료구조
	스택
4. 전략
임시 벡터에 채워 넣고 짝 들어오면 없애는 식
스택 vs 큐	
	큐가 맞는것 같음. 들어오고 나가고가 한쪽에서만 이뤄지면 안됨
	아니다 스택이 맞음 리포임

	일단 하나 임시스택으로 보내고 스택의 말단2개 검사해서 짝 맞으면 pop


*/


	#include<string>
	#include <iostream>
	#include <vector>

	using namespace std;

	bool	check_vec(vector<char> &vt)
	{
		int	len = vt.size();

		if (vt[len-1] == ')' && vt[len-2] == '(')
			return (true);
		return (false);
	}

	bool solution(string s)
	{
		bool		answer = true;
		vector<char>	vt;

		vt.push_back(s[0]);
		for (int i=1; i<s.size(); i++)
		{
			//보내고
			vt.push_back(s[i]);
			//벡터 말단 2개 검사
			if (check_vec(vt) == true)
			{
				//팝백
				vt.pop_back();
				vt.pop_back();
			}
		}
		if (!vt.empty())
			answer = false;
		return answer;
	}

int	main(void) 
{
	std::cout << solution("()()") << std::endl;
	std::cout << solution("(())()") << std::endl;
	std::cout << solution(")()()") << std::endl;
	std::cout << solution("(()(") << std::endl;

	std::cout << solution("((((()))))") << std::endl;

	


}