#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define INFINITY 10000000

class Dijkstra {
private:
	int SIZE;
	int** weights;
	bool* visited;
	int* distance;

public:
	Dijkstra(int size = 7) {
		this->SIZE = size;
		this->weights = new int* [size];
		for (int i = 0; i < size; i++) {
			this->weights[i] = new int[size];
			for (int j = 0; j < size; j++) {
				if (i == j) { this->weights[i][j] = 0; }
				else { this->weights[i][j] = INFINITY; }
			}
		}
		this->visited = new bool[size];
		this->distance = new int[size];
		for (int i = 0; i < size; i++) {
			this->visited[i] = false;
			this->distance[i] = 0;
		}

	}
	~Dijkstra() {
		for (int i = 0; i < this->SIZE; i++) { delete[] this->weights[i]; }
		delete[] this->weights;
		delete[] visited;
	}

	void calculate(int start) {
		bool check = false;
		for (int i = 0; i < this->SIZE; i++) {
			if (this->visited[i] == false) { check == true; break; }
		}
		if (check == false) {
			cout << "Calculate End!" << endl;
			
			cout << "Distance: ";
			for (int i = 0; i < this->SIZE; i++) { cout << this->distance[i] << ""; }
			cout << endl;
		}

		int target = start - 1;
		this->visited[target] = true;
		for (int i = 0; i < this->SIZE; i++) {
			if (this->visited[i] == true) { continue; }
			else { this->distance[i] = this->weights[target][i]; }
		}

		int min = INFINITY;
		for (int i = 0; i < this->SIZE; i++) {
			if (this->visited[i] == true) { continue; }
			else {
				if (this->distance[min] > this->distance[i]) { min = i; }
			}
		}

		calculate(min);
	}

	void set_weight(int x, int y, int val) {
		if (this->weights[x - 1][y - 1] != INFINITY) { cout << "Already Exsist!!" << endl; }
		else {
			this->weights[x - 1][y - 1] = val; this->weights[y - 1][x - 1] = val;
			cout << x << "↔" << y << " Set!" << endl;
		}
	}
	void show_weights() {
		for (int i = 0; i < this->SIZE; i++) {
			for (int j = 0; j < this->SIZE; j++) {
				cout << setw(8) << this->weights[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main() {
#pragma region ???
	// 시작점으로부터 모든 노드까지의 최소 거리를 구해주는 알고리즘

	// 1. 거리 배열에 weight[시작 노드]의 값들로 초기화
	// 2. 시작점을 방문 처리
	// 3. 거리 배열에서 최소비용 노드를 찾고 방문 처리
	//    단, 이미 방문한 노드는 제외
	// 4. 최소비용 노드를 거쳐갈 지 고민하여 거리 배열을 갱신
	//    단, 이미 방문한 노드는 제외
	// 5. 모든 노드를 방문할 때까지 3~4번 반복
	
	// 방문하지 않은 노드 중에서 가장 작은 거리를 가진 노드를
	// 방문하고, 그 노드와 연결된 다른 노드까지의 거리를 계산함

	Dijkstra dijkstra1;

	dijkstra1.set_weight(1, 2, 2);
	dijkstra1.set_weight(1, 3, 5);
	dijkstra1.set_weight(1, 4, 1);
	dijkstra1.set_weight(2, 1, 2);
	dijkstra1.set_weight(2, 3, 3);
	dijkstra1.set_weight(2, 4, 2);
	dijkstra1.set_weight(3, 4, 3);
	dijkstra1.set_weight(3, 5, 1);
	dijkstra1.set_weight(3, 6, 5);
	dijkstra1.set_weight(4, 2, 2);
	dijkstra1.set_weight(4, 5, 1);
	dijkstra1.set_weight(5, 6, 2);

	dijkstra1.show_weights();
	// INFINITY가 출력할때 너무 길어서 -1로 임시 대체함

#pragma endregion


	return 0;
}