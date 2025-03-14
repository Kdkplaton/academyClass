#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main() {
#pragma region 거품 정렬 (Bubble Sort)
	// 

	const int size = 20;
	int datas[size];

	srand(time(0));			// 매번 다른 난수를 얻기 위한 함수 (time.h 참조)

	cout << "정렬 전: ";
	for (int i = 0; i < size; i++) {
		datas[i] = rand() % 100;
		cout << datas[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (datas[j] > datas[j + 1]) { swap(datas[j], datas[j + 1]); }
		}
	}

	cout << "정렬 후: ";
	for (int i = 0; i < size; i++) { cout << datas[i] << " "; }
	cout << endl;

#pragma endregion

	return 0;
}