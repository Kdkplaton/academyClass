#include <iostream>
#include <time.h>
#include <random>
#include <cmath>
using namespace std;

int main() {
#pragma region 계수 정렬
	// 데이터의 값을 비교하지 않고 각 원소에 데이터가 
	// 몇개 있는지 개수를 세어 사용한 다음 정렬하는 알고리즘

	srand(time(0));

	cout << "계수정렬 5회 실행" << endl;
	for (int j = 0; j < 5; j++) {
		int size = 10;
		int* numbers = new int[size];
		int counter[5] = { 0, };

		cout << "숫자 목록: ";
		for (int i = 0; i < 10; i++) {
			numbers[i] = rand() % 5 + 1;		// 1~5 사이의 수
			cout << numbers[i] << " ";
		}
		cout << endl;

		for (int i = 0; i < size; i++) { counter[numbers[i] -1]++; }

		cout << "계수정렬 결과: ";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < counter[i]; j++) {
				cout << i+1 << " ";
			}
		}
		cout << endl;

		delete[] numbers;
		cout << endl;
	}

#pragma endregion


	return 0;
}