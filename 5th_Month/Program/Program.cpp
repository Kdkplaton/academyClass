#include <iostream>
#include <vector>

using namespace std;

#define SIZE 8

template <typename T>
struct Graph {
private:
	bool visited[SIZE];
	vector<T> nearNodes[SIZE];
	int stack[SIZE];
	int stack_count;
	vector<int> visit_list;
public:
	Graph() {
		for (int i = 0; i < SIZE; i++) {
			this->visited[i] = false;
			this->stack[i] = NULL;
		}
		// this->visit_list = NULL;
		this->stack_count = 0;
	}
	~Graph() {
		cout << "Delete Graph!" << endl;
	}

	void Link(int t1, int t2) {
		for (int i = 0; i < this->nearNodes[t1].size(); i++) {
			if (this->nearNodes[t1][i] == t2) { cout << "Already Linked!" << endl; return; }
		}
		this->nearNodes[t1].push_back(t2);
		this->nearNodes[t2].push_back(t1);
		cout << t1 << " & " << t2 << " Linked!" << endl;
	}

	void Search(int start) {
		if (this->visited[start] == false) {
			this->visited[start] = true;
			this->visit_list.push_back(start);
		}
		
		int last;
		for (int i = 0; i < this->nearNodes[start].size(); i++) {
			if (this->visited[this->nearNodes[start][i]] == false) {
				this->visited[this->nearNodes[start][i]] = true;
				stack[stack_count++] = this->nearNodes[start][i];
				this->visit_list.push_back(this->nearNodes[start][i]);
			}
			else { continue; }
		}

		cout << "stack: ";
		if (this->stack_count == 0) { cout << "N/A"; }
		else {
			for (int i = 0; i < this->stack_count; i++) { cout << this->stack[i] << " "; }
		}
		cout << endl;

		if (stack_count == 0) {
			cout << "Search End!" << endl;

			cout << "Visited: ";
			for (int i = 0; i < this->visit_list.size(); i++) {
				cout << this->visit_list[i] << " ";
			}
			cout << endl;

			return;
		}
		else {
			last = this->stack[--stack_count];
			cout << "poped: " << last << endl;
			this->stack[stack_count] = NULL;
			Search(last);
		}
		
	}

	void showLinks() {
		cout << "----- 그래프의 연결관계 -----" << endl;
		for (int i = 1; i < SIZE; i++) {
			cout << i << "번 노드의 Links: ";

			if (this->nearNodes[i].size() == 0) { cout << "N/A" << endl; continue; }
			
			for (int j = 0; j < this->nearNodes[i].size(); j++) {
				cout << this->nearNodes[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	
};

int main() {
#pragma region 깊이 우선 탐색 (Depth First Search)
	// root 노드에서 부터 다음 분기로 넘어가기
	// 전에 해당 분기를 완벽하게 탐색하는 방법

	// 깊이 우선 탐색은 자료구조 [ Stack ] 활용

	// 1. 시작 노드를 스택에 넣고 방문 처리
	// 2. 스택 최상단 노드에 방문하지 않은 인접노드 존재시 그 노드를 스택에 넣고 방문 처리
	// 3. 방문하지 않은 인접 노드가 없으면 스택에서 최상단에 있는 노드 추출
	// 4. 더이상 2번의 과정을 수행할 수 없을 때까지 반복

	Graph<int> g1;

	g1.Link(1, 2);
	g1.Link(1, 3);

	g1.Link(2, 3);
	g1.Link(2, 4);
	g1.Link(2, 5);

	g1.Link(3, 6);
	g1.Link(3, 7);

	g1.Link(4, 5);
	g1.Link(6, 7);

	cout << endl;

	g1.showLinks();

	cout << endl;

	g1.Search(1);

#pragma endregion

	return 0;
}