#include <iostream>
#include <vector>
#include <queue>

std::vector<int> graph[9];
bool	visited[9];

void bfs(int start)
{
	std::queue<int> q;
	int	node;

	q.push(start);
	while(!q.empty())
	{
		node = q.front();
		q.pop();
		visited[node] = true;
		std::cout << node << " ";
		for (int i=0; i<graph[node].size(); i++)
		{
			if (visited[graph[node][i]] == false)
				q.push(graph[node][i]);
				visited[graph[node][i]] = true;
		}
	}
}

int	main(void)
{
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	graph[2].push_back(1);
	graph[2].push_back(7);
		
	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);
		
	graph[4].push_back(3);
	graph[4].push_back(5);
		
	graph[5].push_back(3);
	graph[5].push_back(4);
		
	graph[6].push_back(7);
		
	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);
		
	graph[8].push_back(1);
	graph[8].push_back(7);

	bfs(1);
}