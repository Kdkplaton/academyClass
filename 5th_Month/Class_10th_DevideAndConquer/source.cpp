#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int Find(int list[], int left, int right) {
	int a, b;
	if (left == right) {
		return list[left];
		cout << "End Point Reached!" << endl;
	}
	else {
		a = Find(list, left, (left + right) / 2);
		b = Find(list, (left + right) / 2 + 1, right);

		if (a > b) { return a; }
		else { return b; }
	}
}

int main() {
#pragma region 분할 정복
	// 주어진 2개 이상의 부분으로 문제를 나눈 뒤
	// 각 부분 문제에 대한 답을 재귀 호출을 이용하여 계산한 다음,
	// 그 답으로부터 전체 문제의 답을 계산해내는 알고리즘

	// 분할(Devide): 주어진 문제를 2개 혹은 그 이상의 형식으로 나눔

	// 정복 (Conqeuer): 나누어진 문제를 재귀적으로 해결해서
	// 나누어진 문제를 더 이상 나누어서 문제가 필요없을 때 까지 계속 분할]

	// 통합 (Combine): 나누어서 해결한 문제들을 통합해서 원래 문제의 해답을 생성

	srand(time(0));

	int datas[10];

	for (int j = 0; j < 5; j++) {
		cout << "datas: ";
		for (int i = 0; i < 10; i++) {
			datas[i] = rand() % 100 + 1;
			cout << datas[i] << " ";
		}
		cout << endl;

		cout << "최대값: " << Find(datas, 0, 9) << endl;
	}

#pragma endregion

	return 0;
}