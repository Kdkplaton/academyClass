#include <iostream>
#include <vector>

using namespace std;

class Edge {
private:
	int start;
	int end;
	int dist;
public:
	Edge(int node1 = NULL, int node2 = NULL, int val = NULL) {
		this->start = node1;
		this->end = node2;
		this->dist = val;
	}
	~Edge() {

	}

	void update_dist(int val) { this->dist = val; }
	int get_start() { return this->start; }
	int get_end() { return this->end; }
	int get_dist() { return this->dist; }
};

class Kruskal {
private:
	int SIZE;
	vector<Edge> edges;
	int* parents;
	int cost;
public:
	Kruskal(int size = 8) {
		this->SIZE = size;
		this->parents = new int[size];
		for (int i = 0; i < size; i++) { this->parents[i] = i; cout << parents[i] << endl; }
		this->cost = 0;

		cout << "Kruskal Start!\n" << endl;
	}
	~Kruskal() {
		delete[] parents;
		cout << "\nKruskal End!" << endl;
	}

	void set_edge(int node1, int node2, int val) {
		for (int i = 0; i < this->edges.size(); i++) {
			if (this->edges[i].get_start() == node1 && this->edges[i].get_end() == node2) {
				// edges[i].update_dist(val);
				cout << "Edge " << node1 << "↔" << node2 << " Already Exsists!" << endl; return;
			}
			else if (this->edges[i].get_start() == node2 && this->edges[i].get_end() == node1) {
				// edges[i].update_dist(val);
				cout << "Edge " << node1 << "↔" << node2 << " Already Exsists!" << endl; return;
			}
		}
		this->edges.push_back(Edge(node1, node2, val));
		if (node1 > node2) { this->parents[node1] = node2; }
		else { this->parents[node1] = node2; }
		cout << "Edge " << node1 << "↔" << node2 << " added!" << endl;
	}
	void sort_edges() {
		for (int i = 0; i < this->edges.size() - 1; i++) {
			int min = i;
			for (int j = i + 1; j < this->edges.size(); j++) {
				int dist1 = this->edges[min].get_dist();
				int dist2 = this->edges[j].get_dist();
				if (dist1 > dist2) { min = j; }
			}
			swap(this->edges[i], this->edges[min]);
		}

		cout << "Edges sorted!" << endl;
		this->show_edges();
	}
	
	void find_lowestDistTree() {
		this->sort_edges();
		
		for (int i = 0; i < this->edges.size(); i++) {
			int n1 = this->edges[i].get_start();
			int n2 = this->edges[i].get_end();
			if (n1 > n2) {
				if () {}
			}
			else {

			}

		}

	}

	void show_edges() {
		cout << "-- Show Edge List --" << endl;
		for (int i = 0; i < this->edges.size(); i++) {
			cout << "간선[" << this->edges[i].get_start() << "↔" << this->edges[i].get_end() << "] " << this->edges[i].get_dist() << endl;
		}
	}
	void show_parents() {
		cout << "-- Show Parents List --" << endl;
		for (int i = 1; i < this->SIZE; i++) {
			cout << i << "의 부모: " << this->parents[i] << endl;
		}
	}
};

int main() {
#pragma region 최소 신장 트리
	// 그래프의 모든 정점을 포함하면서 사이클이 존재하지 않는 부분 그래프
	// 그래프의 모든 정점을 최소비용으로 연결하는 트리

	// 그래프의 정점의 수가 n개일 때, 간선의 수는 n-1개 (결과)

	Kruskal krsk1;

	// 존재하는 모든 간선 관계를 각 노드의 관점에서 전부 설정
	// ※ 이미 등록된 관계는 설정(추가)되지 않음 ※
	cout << "---- Initialize Nodes ----" << endl;
	
	krsk1.set_edge(1, 2, 64);
	krsk1.set_edge(1, 4, 30);
	krsk1.set_edge(1, 5, 19);
	krsk1.set_edge(1, 7, 10);

	krsk1.set_edge(2, 1, 64);	// 추가되지 않음
	krsk1.set_edge(2, 4, 25);
	krsk1.set_edge(2, 5, 61);

	krsk1.set_edge(4, 1, 30);	// 추가되지 않음
	krsk1.set_edge(4, 2, 25);	// 추가되지 않음
	krsk1.set_edge(4, 7, 14);

	krsk1.set_edge(7, 1, 10);	// 추가되지 않음
	krsk1.set_edge(7, 4, 14);	// 추가되지 않음
	krsk1.set_edge(7, 5, 73);

	krsk1.set_edge(5, 1, 19);	// 추가되지 않음
	krsk1.set_edge(5, 2, 61);	// 추가되지 않음
	krsk1.set_edge(5, 3, 22);
	krsk1.set_edge(5, 6, 48);
	krsk1.set_edge(5, 7, 73);	// 추가되지 않음

	krsk1.set_edge(3, 5, 22);	// 추가되지 않음
	krsk1.set_edge(3, 6, 36);
	
	krsk1.set_edge(6, 3, 36);	// 추가되지 않음
	krsk1.set_edge(6, 5, 48);	// 추가되지 않음

	cout << "---- Initialize Ended ----" << endl;
	
	cout << endl;
	
	krsk1.show_edges();

	cout << endl;

	krsk1.show_parents();

	cout << endl;

	krsk1.find_lowestDistTree();



#pragma endregion

	return 0;
}