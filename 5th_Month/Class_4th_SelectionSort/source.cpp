#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main() {
#pragma region 선택 정렬
	// 주어진 리스트 중에 최소값을 찾은 다음 특정한 위치에서 결과를 교체하는 방식으로 정렬하는 알고리즘

	const int size = 10;
	int datas[size], target;

	srand(time(0));			// 매번 다른 난수를 얻기 위한 함수 (time.h 참조)

	cout << "정렬 전: ";
	for (int i = 0; i < size; i++) {
		datas[i] = rand() % 100;
		cout << datas[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size; i++) {
		target = i;
		for (int j = i; j < size; j++) { if (datas[target] > datas[j]) { target = j; } }
		swap(datas[i], datas[target]);

		cout << "정렬 " << i + 1 << " : ";
		for (int k = 0; k < size; k++) { cout << datas[k] << " "; }
		cout << endl;
	}

	cout << "정렬 후: ";
	for (int i = 0; i < size; i++) { cout << datas[i] << " "; }
	cout << endl;

#pragma endregion

	return 0;
}