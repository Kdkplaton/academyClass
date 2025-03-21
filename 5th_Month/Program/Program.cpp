#include <iostream>

using namespace std;

void binary_search(int list[], int key) {
	int left = 0, right = 9;

	cout << "탐색 대상: " << key << " - ";
	while (true) {
		if (key < list[left] || key > list[right]) { cout << "존재하지 않음!" << endl; return; }
		else {
			if (key == (list[(left + right) / 2])) { cout << ((left + right) / 2) + 1 << "번째 값" << endl; return; }
			if (key < (list[(left + right) / 2])) { right = ((left + right) / 2) - 1; }
			else if (key > (list[(left + right) / 2])) { left = ((left + right) / 2) + 1; }
		}
	}
};

int main() {
#pragma region 투 포인터 알고리즘
	// 

	int datas[10] = {11,22,33,44,55,66,77,88,99,101};

	cout << "datas: ";
	for (int i = 0; i < 10; i++) { cout << datas[i] << " "; }
	cout << endl;
	binary_search(datas, 44);
	binary_search(datas, 33);
	binary_search(datas, 7);
	binary_search(datas, 85);
	binary_search(datas, 77);
	binary_search(datas, 11);
	binary_search(datas, 100);


#pragma endregion


	return 0;
}