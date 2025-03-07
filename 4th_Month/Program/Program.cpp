#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class AdjacencyMatrix {
private:
	T* datas;
	int** links;
	int size;
	int count;
public:
	AdjacencyMatrix(int size = 10) {
		this->datas = new T[size];
		this->size = size;
		this->count = 0;

		// links 초기화
		this->links = new int* [size];
		for (int i = 0; i < size; i++) {
			this->links[i] = new int[size];
			for (int j = 0; j < size; j++) { this->links[i][j] = -1; }
		}
	}
	~AdjacencyMatrix() {
		delete[] this->datas;

		for (int i = 0; i < this->size; i++) { delete[] this->links[i]; }
		delete[] this->links;
	}

	void addData(T data) {
		if (this->count == this->size) { cout << "!! Error : Matrix Overflow !!" << endl; }
		else {
			this->datas[this->count++] = data;
			for (int i = 0; i < this->size; i++)
			{ this->links[this->count - 1][i] = 0; }
			cout << "데이터 추가 됨!" << endl;
		}
	}
	void deleteData(int target) {
		if (this->links[target][0] == -1) { cout << "!! Error : 해당 위치에 데이터가 없음 !!" << endl; }
		else {


			this->count--;
		}
		
	}
	void edge(int target1, int target2)
	{
		if (this->links[target1][0] == -1 || this->links[target2][0] == -1) {
			cout << "!! Error : 존재하지 않는 데이터와 연결시도 !!" << endl;
		}
		else {
			this->links[target1][target2]++;
			this->links[target2][target1]++;
			cout << target1 << " <-> " << target2 << " 연결됨!" << endl;
		}
	}
	void unEdge(int target) {
		for (int i = 0; i < this->size; i++) {
			if (i == target) { continue; }
			else if (this->links[i][0] == -1) { continue; }
			else { this->links[i][target]--; }
		}



	}
	void showLinkDetail() {
		cout << "---------- [size:" << this->size << "] link 세부목록----------" << endl;
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++) {
				if (this->links[i][j] == -1) { cout << setw(2) << setfill(' ') << i + 1 << "->" << j + 1 << ":N "; }
				else { cout << setw(2) << setfill(' ') << i << "->" << j << ":" << this->links[i][j] << " "; }
			}
			cout << endl;
		}
	}
	void showLink() {
		cout << "---- link 목록 ----" << endl;
		for (int i = 0; i < this->count; i++) {
			for (int j = 0; j < this->count; j++) {
				if (this->links[i][j] == -1) { cout << "X "; }
				else { cout << this->links[i][j] << " "; }
			}
			cout << endl;
		}
	}
};

int main() {
#pragma region 그래프(Graph)
	// 그래프 용어
	// 정점 Vertex
	// 간선: Node를 연결하는 선

	// 방향 그래프
	// 진입 차수 : 들어오는 경로의 수
	// 진출 차수 : 나가는 경로의 수
	// 
	
	// 무방향 그래프
	// ??
	// ??

	//int array[4][4] = {
	//	0, 1, 0, 0,
	//	1, 0, 1, 1,
	//	0, 1, 0, 1,
	//	0, 1, 1, 0
	//};


	AdjacencyMatrix<int> AM1;
	AM1.addData(30);
	AM1.addData(50);
	AM1.edge(1, 2);
	AM1.addData(20);
	AM1.edge(1, 2);
	AM1.addData(10);
	AM1.addData(40);
	// AM1.showLinkDetail();		// 쉽게 간선관계를 이해하기 위한 함수
	AM1.showLink();

	cout << endl;

	AM1.addData(60);
	AM1.edge(4, 2);
	AM1.showLink();

#pragma endregion


	return 0;
}