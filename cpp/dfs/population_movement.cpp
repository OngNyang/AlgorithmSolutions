/*
이게 왜 dfs..

인접 행렬을 만드는건가?
	N*N개이다. N*N개 만큼의 도시가 있는것이고 그에 맞춰 각각 4개의 인접행렬이 있을수 있다.

각 위치마다 인접 리스트 만들기
인접 리스트로 bfs 이용해서 각 위치마다 연합 리스트 만들기

2차원 배열을 전부 순회하며, 평균값 연산 할곳은 해주고, 넘어갈곳은 넘어가 주기


*/



/*
알고리즘 테스트를 진행할때, 일괄적으로 적용시킬 폼이 있음 좋겠다. 예를 들면

자료구조는 무엇을 선택할것인가.
알고리즘은 무엇을 선택할것인가
시간 복잡도 계산
메모리 계산

*/


// #include <iostream>
// #include <vector>
// #include <queue>

// int	N,L,R;
// int	**map;



// void	bfs(bool *visited, std::vector<std::vector<std::pair<int, int> > >& adj_list)
// {
// 	std::queue<std::pair<int, int> >	q;
// 	std::pair<int, int> >				node;

// 	q.push(make_pair(0, 0));
// 	while (!q.empty())
// 	{
// 		node = q.front();
// 		q.pop();
// 		visited[(node.first * N) + node.second] = true;
// 		for (int i=0; i<)
// 	}
// }

// void	check_LR(int i, int j, int ni, int nj, std::vector<std::vector<std::pair<int, int> > >& adj_list)
// {
// 	int	diff = 0;

// 	if (!(0 <= ni && ni < N && 0<= nj && nj < N))
// 		return ;
// 	diff = abs(map[i][j] - map[ni][nj]);
// 	if (L <= diff && diff <= R)
// 		adj_list[(i*N)+j].push_back(std::make_pair(ni, nj));
// }

// int	main(void)
// {
// //입력받기
// 	std::cin >> N >> L >> R;
// 	std::cin.ignore();
// 	map = new int*[N];
// 	for (int i=0; i<N; i++)
// 		map[i] = new int[N];
// 	for (int i=0; i<N; i++)
// 		for (int j=0; j<N; j++)
// 			std::cin >> map[i][j];
// //인접 리스트 생성
// 	std::vector<std::vector<std::pair<int, int> > > adj_list(N*N);
// //상하좌우 탐색
// 	for (int i=0; i<N; i++)
// 	{
// 		for (int j=0; j<N; j++)
// 		{
// 			check_LR(i, j, i-1, j, adj_list);
// 			check_LR(i, j, i+1, j, adj_list);
// 			check_LR(i, j, i, j-1, adj_list);
// 			check_LR(i, j, i, j+1, adj_list);
// 		}
// 	}
// //bfs와 인접리스트를 이용해서 연합 구해내기.
// 	std::vector<std::queue<std::pair<int, int> > >	aliance;
// 	bool	*visited = new bool[N*N];
// 	bfs(visited, adj_list);



// //인접 리스트 출력 체크
// 	// for (int i=0; i<(N*N); i++)
// 	// {
// 	// 	std::cout << "idx : " << (i/N) << " " << (i%N) << std::endl;
// 	// 	for (int j=0; j<adj_list[i].size(); j++)
// 	// 	{
// 	// 		std::cout << adj_list[i][j].first << "," << adj_list[i][j].second << " ";
// 	// 	}
// 	// 	std::cout << std::endl;
// 	// }
// //map 입력 출력 체크
// 	// for (int i=0; i<N; i++)
// 	// {
// 	// 	for (int j=0; j<N; j++)
// 	// 	{
// 	// 		std::cout << map[i][j] << " ";
// 	// 	}
// 	// 	std::cout << std::endl;
// 	// }

// }


#include <bits/stdc++.h>

using namespace std;

// 땅의 크기(N), L, R 값을 입력받기
int n, l, r;

// 전체 나라의 정보(N x N)를 입력받기
int graph[50][50];
int unions[50][50];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

// 특정 위치에서 출발하여 모든 연합을 체크한 뒤에 데이터 갱신
void process(int x, int y, int index) {
    // (x, y)의 위치와 연결된 나라(연합) 정보를 담는 리스트
    vector<pair<int, int> > united;
    united.push_back({x, y});
    // 너비 우선 탐색 (BFS)을 위한 큐 라이브러리 사용
    queue<pair<int, int> > q;
    q.push({x, y});
    unions[x][y] = index; // 현재 연합의 번호 할당
    int summary = graph[x][y]; // 현재 연합의 전체 인구 수
    int count = 1; // 현재 연합의 국가 수
    // 큐가 빌 때까지 반복(BFS)
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 현재 위치에서 4가지 방향을 확인하며
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 바로 옆에 있는 나라를 확인하여
            if (0 <= nx && nx < n && 0 <= ny && ny < n && unions[nx][ny] == -1) {
                // 옆에 있는 나라와 인구 차이가 L명 이상, R명 이하라면
                int gap = abs(graph[nx][ny] - graph[x][y]);
                if (l <= gap && gap <= r) {
                    q.push({nx, ny});
                    // 연합에 추가하기
                    unions[nx][ny] = index;
                    summary += graph[nx][ny];
                    count += 1;
                    united.push_back({nx, ny});
                }
            }
        }
    }
    // 연합 국가끼리 인구를 분배
    for (int i = 0; i < united.size(); i++) {
        int x = united[i].first;
        int y = united[i].second;
        graph[x][y] = summary / count;
    }
}

int totalCount = 0;

int main(void) {
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // 더 이상 인구 이동을 할 수 없을 때까지 반복
    while (true) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                unions[i][j] = -1;
            }
        }
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (unions[i][j] == -1) { // 해당 나라가 아직 처리되지 않았다면
                    process(i, j, index);
                    index += 1;
                }
            }
        }
        // 모든 인구 이동이 끝난 경우
        if (index == n * n) break;
        totalCount += 1;
    }

    // 인구 이동 횟수 출력
    cout << totalCount << '\n';
}


#include <iostream>

int	n, l, r;
int	totalCount = 0;
int	graph[50][50];
int	unions[50][50];
int	dx[] = {-1, 0, 1, 0};
ind	dy[] = {0, -1, 0, 1};

void	process(int x, int y, int idx)
{
	std::vector<std::pair<int, int> >	united;
	std::queue<pair<int, int> >			q;
	int									summary = graph[x][y];
	int									count = 1;
	int									x, y;
	int									nx, ny;
	int									gap;

	united.push_back({x, y});
	q.push({x, y});
	unions[x][y] = index;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i= 0; i<4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && unions[nx][ny] == -1)
			{
				gap = abs(graph[nx][ny] - graph[x][y]);
				if (l <= gap && gap <= r)
				{
					q.push({nx, ny});
					unions[nx][ny] = index;
					summary += graph[nx][ny];
					count += 1;
					united.push_back({nx, ny});
				}
			}
		}
	}
	for (int i=0; i<united.size(); i++)
	{
		x = united[i].first;
		y = united[i].second;
		graph[x][y] = summary/count;
	}
}

int	main(void)
{
//입력 받기
	std::cin >> n >> l >> r;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			std::cin >> graph[i][j];

	while (1)
	{
	//unions 초기화
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				unions[i][j] = -1;
	//process 적용
		int	idx = 0;
		for (int i=0; i<n; i++)
		{
			for (int j=0; j <n; j++)
			{
				if (unions[i][j] == -1)
				{
					process(i, j, idx);
					idx++;
				}
			}
		}
	//while문 탈출 조건
		if (idx == n*n)
			break ;
		totalCount++;
	}
	std::cout << totalCount << std::endl;
}