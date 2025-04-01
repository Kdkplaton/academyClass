#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
struct Graph {
private:
	int SIZE;
	vector<int>* nodes;
	int* degrees;
	queue<int> que1;
	int* pushed;
	int* sorted;
	int count;
	int count2;
public:
	Graph(int SIZE = 8) {
		this->SIZE = SIZE;
		this->nodes = new vector<int>[SIZE];
		this->degrees = new int[SIZE];
		for (int i = 0; i < SIZE; i++) { this->degrees[i] = NULL; }
		this->pushed = new int[SIZE];
		for (int i = 0; i < SIZE; i++) { this->pushed[i] = NULL; }
		this->sorted = new int[SIZE];
		for (int i = 0; i < SIZE; i++) { this->sorted[i] = NULL; }
		this->count = 0;
		this->count2 = 0;
	}
	~Graph() {
		delete[] nodes;
		delete[] degrees;
		cout << "Graph End!" << endl;
	}

	void topological_sort() {
		for (int i = 1; i < this->SIZE; i++) {
			if (this->degrees[i] == 0) {
				bool check = false;
				for (int j = 0; j < this->count; j++) {
					if (this->pushed[j] == i) { check = true; break; }
				}

				if (check == true) { continue; }
				else {
					this->que1.push(i);
					this->pushed[this->count++] = i;
				}
			}
		}

		if (this->que1.size() == 0) {
			cout << "Topological Sort End!" << endl;

			cout << "sorted: ";
			for (int i = 0; i < this->count2; i++) { cout << this->sorted[i] << " "; }
			cout << endl;

			return;
		}

		int poped = this->que1.front();

		this->sorted[this->count2++] = poped;
		this->que1.pop();
		for (int i = 0; i < this->nodes[poped].size(); i++) {
			this->degrees[this->nodes[poped][i]]--;
		}

		topological_sort();
	}

	void Link(int a, int b) {
		for (int i = 0; i < this->nodes[a].size(); i++) {
			if (this->nodes[a][i] == b) { cout << a << "->" << b << " Already Exists!!" << endl; return; }
		}
		for (int i = 0; i < this->nodes[b].size(); i++) {
			if (this->nodes[b][i] == a) { cout << b << "->" << a << " Already Exists!!" << endl; return; }
		}

		this->nodes[a].push_back(b);
		this->degrees[b]++;
		cout << "Link " << a << " to " << b << endl;
	}
	void showLinks() {
		cout << "----- Graph Links -----" << endl;
		for (int i = 1; i < this->SIZE; i++) {
			cout << i << " -> [ ";
			if (this->nodes[i].size() == 0) { cout << "N/A "; }
			else {
				for (int j = 0; j < this->nodes[i].size(); j++) { cout << this->nodes[i][j] << " "; }
			}
			cout << "]" << endl;
		}
	}
	void showDegrees() {
		cout << "----- Graph Degrees -----" << endl;
		cout << "degrees (from 1): ";
		for (int i = 1; i < this->SIZE; i++) {
			cout << this->degrees[i] << " ";
		}
		cout << endl;
	}
};

int main() {
#pragma region 위상 정렬 (Topological Sort)
	// 병합 그래프에 존재하는 각 정점들의 선행 순서를 지키며, 모든 정점을 차례대로 진행하는 알고리즘

	// 사이클이 발생하는 경우 위상 정렬을 수행할 수 없음

	// DAG(Directed Acyclic Graph) : 사이클이 존재하지 않는 그래프

	// 시간 복잡도 : O(V + E)

	// 위상 정렬 방법
	// 1. 진입 차수가 0인 정점을 큐(Queue)에 삽입
	// 2. 큐에서 원소를 꺼내 연결된 모든 간선 제거
	// 3. 간선 제거 이후에 진입 차수가 0이 된 정점을 큐에 삽입
	// 4. 큐가 비어있을때 까지 2-3번 작업을 반복

	Graph<int> g1;

	g1.Link(1, 2);
	g1.Link(1, 5);
	g1.Link(2, 3);
	g1.Link(3, 4);
	g1.Link(4, 6);
	g1.Link(5, 6);
	g1.Link(6, 7);

	cout << endl;

	g1.showLinks();

	cout << endl;

	g1.showDegrees();

	cout << endl;

	g1.topological_sort();


#pragma endregion

	return 0;
}