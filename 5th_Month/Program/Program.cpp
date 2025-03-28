#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define SIZE 8

template <typename T>
struct Graph {
private:
	queue<int> que1;
	vector<int> link[SIZE];
	bool visited[SIZE];
	vector<int> visit_list;
public:
	Graph() {
		for (int i = 0; i < SIZE; i++) { this->visited[i] = false; }

	}
	~Graph() {
		cout << "Delete Graph!" << endl;
	}

	void Link(int x, int y) {
		for (int i = 0; i < this->link[x].size(); i++) {
			if (this->link[x][i] == y) { cout << "Already Linked!" << endl; return; }
		}
		this->link[x].push_back(y);
		this->link[y].push_back(x);
		cout << x << " & " << y << " Linked!" << endl;
	}

	void Search(int start) {
		if (this->visited[start] == false) {
			this->visited[start] = true;
			this->visit_list.push_back(start);
		}
		
		for (int i = 0; i < this->link[start].size(); i++) {
			if (this->visited[this->link[start][i]] == false) {
				this->visited[this->link[start][i]] = true;
				que1.push(this->link[start][i]);
				this->visit_list.push_back(this->link[start][i]);
			}
			else { continue; }
		}

		queue<int> temp = this->que1;
		cout << "queue: ";
		if (temp.size() == 0) { cout << "N/A"; }
		else {
			int n = temp.size();
			for (int i = 0; i < n; i++) {
				cout << temp.front() << " ";
				temp.pop();
			}
		}

		if (this->que1.size() == 0) {
			cout << endl << "Search End!" << endl;

			cout << "Visited: ";
			for (int i = 0; i < this->visit_list.size(); i++) {
				cout << this->visit_list[i] << " ";
			}
			cout << endl;

			return;
		}
		else {
			int poped = this->que1.front();
			this->que1.pop();
			cout << "\tpoped: " << poped << endl;
			Search(poped);
		}

	}

	void showLinks() {
		cout << "----- 그래프의 연결관계 -----" << endl;
		for (int i = 1; i < SIZE; i++) {
			cout << i << "번 노드의 Links: ";

			if (this->link[i].size() == 0) { cout << "N/A" << endl; continue; }

			for (int j = 0; j < this->link[i].size(); j++) {
				cout << this->link[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main() {
#pragma region 너비 우선 탐색 (Breadth First Search)
	// 시작 정점을 방문한 후 시작 정점에 인접한 모든 정점들을 우선 방문하는 방법
	
	// 더 이상 방문하지 않은 정점이 없을 때까지 방문하지
	// 않은 모든 정점들에 대해서도 너비 우선 탐색을 적용

	Graph<int> g1;

	g1.Link(1, 2);
	g1.Link(1, 3);

	g1.Link(2, 3);
	g1.Link(2, 4);
	g1.Link(2, 5);

	g1.Link(3, 1);
	g1.Link(3, 6);
	g1.Link(3, 7);

	g1.Link(4, 5);
	g1.Link(6, 7);

	cout << endl;

	g1.showLinks();

	cout << "Search start:1" << endl;
	g1.Search(1);

#pragma endregion

	return 0;
}