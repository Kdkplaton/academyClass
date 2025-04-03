#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
private:
	int size;
	vector<int>* united;
public:
	UnionFind(vector<int> v1, vector<int> v2) {
		int len1 = v1.size();
		int len2 = v2.size();

		this->size = len1 + len2;
		united = new vector<int>[2];

		// union 배열 초기화
		for (int i = 0; i < len1; i++) {
			this->united[0].push_back(v1[i]);
			this->united[1].push_back(v1[i]);
		}
		for (int i = 0; i < len2; i++) {
			this->united[0].push_back(v2[i]);
			this->united[1].push_back(v2[i]);
		}

		// 초기화 결과
		cout << "----- init result -----" << endl;
		for (int i = 0; i < this->size; i++) { cout << this->united[0][i] << " "; }
		cout << endl;
		for (int i = 0; i < this->size; i++) { cout << this->united[1][i] << " "; }
		cout << endl;
	}
	~UnionFind() {
		delete[] united;
		cout << "\nUnionFind 종료!" << endl;
	}

	int find(int val) {
		for (int i = 0; i < this->size; i++) {
			if (this->united[0][i] == val) { return this->united[1][i]; }
		}
	}
	void Union(int a, int b) {
		int temp1 = find(a);
		int temp2 = find(b);

		if (temp1 == a && temp2 == b) {
			if (a <= b) { this->united[1][b] = a; }
			else { { this->united[1][a] = b; } }

			cout << a << "&" << b << " 연결됨!" << endl;
		}
		else {
			cout << "이미 연결된 개체 존재!!" << endl; return;
		}
	}
	bool same(int a, int b) {
		if (this->united[1][a] == this->united[1][b]) return true;
		else return false;
	}

	void showUnionFind() {
		cout << "----- show united -----" << endl;
		for (int i = 0; i < this->size; i++) { cout << this->united[0][i] << " "; }
		cout << endl;
		for (int i = 0; i < this->size; i++) { cout << this->united[1][i] << " "; }
		cout << endl;
	}

};

int main() {
#pragma region 유니온-파인드 Union-Find
	// 여러 노드가 존재할 때 어떤 노드가 다른 노드와 연결되어 있는 지 확인하는 알고리즘

	// Union : 특정한 두 개의 노드를 같은 집합으로 합치는 연산
	// Find : 특정한 노드가 어느 집합에 있는 지 확인하는 연산

	vector<int> arr1 = { 0,1,2 };
	vector<int> arr2 = { 3,4,5 };

	UnionFind uf1(arr1, arr2);

	cout << endl;

	uf1.Union(0, 1);
	cout << "1의 부모: " << uf1.find(1) << endl;
	cout << "0의 부모: " << uf1.find(0) << endl;

	uf1.Union(3, 4);
	uf1.Union(4, 5);
	cout << "5의 부모: " << uf1.find(5) << endl;
	cout << "4의 부모: " << uf1.find(4) << endl;

	cout << endl;

	uf1.showUnionFind();

	cout << endl;

	cout << "0&1 same parent? : " << uf1.same(0, 1) << endl;
	cout << "1&4 same parent? : " << uf1.same(1, 4) << endl;


#pragma endregion

	return 0;
}