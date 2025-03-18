#include <iostream>
#include <random>
#include <time.h>

using namespace std;

void euclid(int x, int y) {
	// 1. 두 개의 자연수 x, y가 있음
	//    그리고 x와 y를 나눈 나머지를 R이라고 함

	// 2. R이 0이라면, x와 y의 최대공약수는 둘중 하나

	// 3. R이 0이라면, x와 y의 최대 공약수는 y와 R의 최대 공약수와 같기 때문에
	//    x에는 y 그리고 y에는 R을 대입한 후 1번으로 돌아감

	int r, num;

	cout << "A: " << x << "   ";
	cout << "B: " << y << "   ";

	r = -1, num = 2;
	while (r != 0) {
		r = x % y;
		if (r == 0) { break; }

		x = y;
		y = r;
	}
	cout << "res: " << y << endl;

}

int main() {
#pragma region  유클리드 호제법
	// 2개의 자엲수 또는 정식의 최대 공약수를 구하는 방식
	// 두 수가 서로 상대발 수를 나누어서 원하는 수를 얻어내는 알고리즘

	srand(time(0));

	int a, b;

	cout << "유클리드 호제법 10회 실행" << endl;
	for (int i = 0; i < 10; i++) {
		a = rand() % 90 + 10;
		b = rand() % 90 + 10;
		if (a < b) { swap(a, b); }

		euclid(a, b);
	}

#pragma endregion

	return 0;
}