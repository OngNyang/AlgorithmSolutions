/*
IDEAS
	최소칸의 갯수라..
	bfs로 하는게 경로의 횟수를 조건으로 할때는 유리할듯
	큐에 집어넣기. 
	한단계 올라갈때마다 경로 횟수 1씩 증가.
	종착지 도착하면 종료하고, 경로 횟수 말하기

	0이면 못가는거, 맵에서 벗어나도 못가는거. 그렇지 않을경우 갈수 있는거. 그 좌표가 N,M이면 끝나는거
	

*/


// #include <iostream>
// #include <queue>
// #include <type_traits>

// typedef struct	s_pos
// {
// 	int	x;
// 	int	y;
// }				pos;

// bool	check(int **map, int x, int y, int N, int M)
// {
// 	if (map[x][y] == 0)
// 		return (false);
// 	if (!(0<= x && x <= N-1))
// 		return (false);
// 	if (!(0<= y && y <= M-1))
// 		return (false);
// 	return (true);
// }


// int	main(void)
// {
// 	int			**map;
// 	std::string	temp;
// 	int			N,M;
// 	int			cnt = 0;

// //making map
// 	std::cin >> N >> M;
// 	std::cin.ignore();
// 	map = new int*[N];
// 	for (int i=0; i<N; i++)
// 		map[i] = new int[M];
// 	for (int i=0; i<N; i++)
// 	{
// 		getline(std::cin, temp);
// 		for (int j=0; j<temp.size(); j++)
// 			map[i][j] = temp[j] - '0';
// 	}

// //----
// 	std::queue<pos> q;
// 	pos	now;
// 	now.x = 0;
// 	now.y = 0;
// 	q.push(now);

// 	pos	node;
// 	// while(!q.empty())
// 	while (1)
// 	{
// 		node = q.front();
// 		if (node.x == N-1 && node.y == M-1)
// 			break;
// 		q.pop();
// 		cnt++;
// 		if (check(map, node.x+1, node.y, N,M) == true)
// 		{
// 			pos	temp = node;
// 			temp.x++;
// 			q.push(temp);
// 		}
// 		if (check(map, node.x-1, node.y, N,M) == true)
// 		{
// 			pos	temp = node;
// 			temp.x--;
// 			q.push(temp);
// 		}
// 		if (check(map, node.x, node.y+1, N,M) == true)
// 		{
// 			pos	temp = node;
// 			temp.y++;
// 			q.push(temp);
// 		}
// 		if (check(map, node.x+1, node.y-1, N,M) == true)
// 		{
// 			pos	temp = node;
// 			temp.y--;
// 			q.push(temp);
// 		}
// 	}
// 	std::cout << cnt << std::endl;
// }


#include <iostream>
#include <queue>

typedef struct	s_pos
{
	int	x;
	int	y;
}				pos;

int	main(void)
{
	int			dx[4] = {-1,1,0,0};
	int			dy[4] = {0,0,-1,1};
	std::string	temp;
	int			**map;
	int			N,M;

	std::cin >> N >> M;
	std::cin.ignore();
	map = new int*[N];
	for (int i=0; i<N; i++)
		map[i] = new int[M];
	for (int i=0; i<N; i++)
	{
		getline(std::cin, temp);
		for (int j=0; j<temp.size(); j++)
			map[i][j] = temp[j] - '0';
	}

	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++)
		{
			std::cout << map[i][j] << " " ;
		}
		std::cout << std::endl;
	}

	std::queue<pos> q;
	pos	departure;
	departure.x = 0;
	departure.y = 0;
	q.push(departure);
	while (!q.empty())
	{
		pos	now = q.front();
		q.pop();
		for (int i=0; i<4; i++)
		{
			pos	next;
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			if (!(0 <= next.x && next.x <= N-1 && 0 <= next.y && next.y <= M-1))
				continue ;
			if (map[next.x][next.y] == 1)
			{
				map[next.x][next.y] = map[now.x][now.y] + 1;
				q.push(next);
			}
		}
	}
	std::cout << map[N-1][M-1] << std::endl;

	// std::queue<pos> q;
	// pos	now;
	// now.x = 0;
	// now.y = 0;
	// q.push(now);

	// while (!q.empty())
	// {
	// 	pos	now = q.front();
	// 	q.pop();
	// 	for (int i=0; i<4; i++)
	// 	{
	// 		pos	next;
	// 		next.x = now.x + dx[i];
	// 		next.y = now.y + dy[i];
	// 		if(!(0 <= next.x && next.x <= N-1 && 0 <= next.y && next.y <= M-1))
	// 			continue ;
	// 		if (map[next.x][next.y] == 0)
	// 			continue ;
	// 		if (map[next.x][next.y] == 1)
	// 		{
	// 			map[next.x][next.y] = map[now.x][now.y] + 1;
	// 			q.push(next);
	// 		}
	// 	}
	// }
	// std::cout << map[N-1][M-1] << std::endl;
}