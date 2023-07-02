/*
adjacency list (인접 리스트)
	: 모든 노드에 연결된 노드에 대한 정보를 차례대로 연결해 저장.
	- vector 사용.

*/

/*
배운점
	- 구조체도 생성자가 있다.
	- c++11 버전으로는 중괄호로도 구조체를 초기화할수 있다.
	- 연결리스트를 만들때도 벡터를 사용하는게 좋을수 있다.
*/


#include <iostream>
#include <vector>

struct	Edge
{
	int	dest;
	int	cost;

	Edge(int d, int c)
	{
		dest = d;
		cost = c;
	}
};

int	main(void)
{
	std::vector<std::vector<Edge> > adj_list(3);
	adj_list[0].push_back(Edge(1, 7));
	adj_list[0].push_back(Edge(2, 5));
}



// #include <iostream>
// #include <vector>

// using namespace std;

// // 간선을 나타내는 구조체
// struct Edge {
//     int destination;  // 연결된 정점의 번호
//     int cost;         // 간선의 소요 비용
// };

// int main() {
//     int numVertices = 5;  // 정점의 수

//     // 인접 리스트를 나타내는 벡터의 벡터
//     vector<vector<Edge> > adjacencyList(numVertices);

//     // 간선 추가 예시
//     adjacencyList[0].push_back({1, 10});  // 0번 정점과 1번 정점 사이의 간선 (소요 비용: 10)
//     adjacencyList[1].push_back({2, 5});   // 1번 정점과 2번 정점 사이의 간선 (소요 비용: 5)
//     adjacencyList[2].push_back({3, 7});   // 2번 정점과 3번 정점 사이의 간선 (소요 비용: 7)
//     adjacencyList[3].push_back({4, 3});   // 3번 정점과 4번 정점 사이의 간선 (소요 비용: 3)

//     // 인접 리스트 출력 예시
//     for (int i = 0; i < numVertices; i++) {
//         cout << "정점 " << i << "과 연결된 정점들:\n";
//         for (const Edge& edge : adjacencyList[i]) {
//             cout << "연결된 정점: " << edge.destination << ", 소요 비용: " << edge.cost << "\n";
//         }
//         cout << endl;
//     }

//     return 0;
// }
