#include <iostream>

using namespace std;

unsigned long long results[100000];

// 반복문(for) 사용
unsigned long long Fibonacci1(int n) {
	long long now = 1, before = 1, temp;

	for (int i = 0; i < n; i++) {
		if (i < 2) { cout << now << " "; continue; }

		temp = now;
		now = now + before;
		before = temp;

		cout << now << " ";
	}
	cout << endl;

	return now;
}

// 재귀함수 사용
unsigned long long Fibonacci2(int n) {
	if (results[n - 1] != 0) return results[n - 1];
	else if (n <= 0) return 0;
	else if (n <= 2) { Fibonacci2(n - 1); results[n - 1] = 1; }
	else { Fibonacci2(n - 1); results[n - 1] = results[n - 2] + results[n - 3]; }

	return results[n - 1];
}

int main() {

#pragma region 동적 계획법
	// 특정 범위까지의 값을 구하기 위해 그것과 다른 범위까지의
	// 값을 이용해서 효율적으로 값을 구하는 알고리즘

	// (Overlapping Subproblems) 겹치는 부분 문제
	// 동일한 작은 문제들이 반복하여 나타나는 경우를 의미

	// (Optimal Substructure) 최적 부분 구조
	// 부분 문제의 최적 결과 값을 사용하여 전체 문제의 최적 결과를 낼 수 있는 경우를 의미


	// 메모이제이션
	// 프로그램이 동일한 계산을 반복해야 할 때, 이전에 계산한 값을
	// 메모리에 저장함으로써 동일한 계산을 반복 수행하는 작업을
	// 제거하여 프로그램의 실행 속도를 향상시키는 방법

	for (int i = 0; i < 100000; i++) { results[i] = 0; }

	int n;
	cin >> n;

	cout << "결과(반복문)  : " << Fibonacci1(n) << endl;
	cout << "결과(재귀함수): " << Fibonacci2(n) << endl;

#pragma endregion

	return 0;
}