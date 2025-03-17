#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main() {
#pragma region 삽입 정렬 (Insertion Sort)
	// 데이터를 하나씩 확인하면서 이미 정렬된 부분과 비교해서 
	// 자신의 위치를 찾아 삽입하는 방식으로 정렬하는 알고리즘

	const int size = 10;
	int datas[size], target;

	srand(time(0));

	cout << "정렬 전: ";
	for (int i = 0; i < size; i++) {
		datas[i] = rand() % 100;
		cout << datas[i] << " ";
	}
	cout << endl;

	int j;
	for (int i = 1; i < size; i++) {
		int key = datas[i];
		for (j = i - 1; j >= 0; j--) {
			if (key < datas[j]) { datas[j + 1] = datas[j]; }
			else { break; }
		}
		datas[j + 1] = key;
	}

	cout << "정렬 후: ";
	for (int i = 0; i < size; i++) { cout << datas[i] << " "; }
	cout << endl;

#pragma endregion

	return 0;
}