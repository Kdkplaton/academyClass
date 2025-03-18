#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main() {
#pragma region 최대공약수 구하기
	srand(time(0));			// 실행시 마다 다른 난수값을 뽑기 위한 설정

	int a, b, res, num;

	cout << "최대 공약수 구하기 (100 이하의 수 2개 입력) 10번 시행" << endl;

	for (int i = 0; i < 10; i++) {
		a = (rand() % 80) + 20;
		b = (rand() % 80) + 20;
		cout << "A: " << a << "   ";
		cout << "B: " << b << "   ";
		res = 1;

		while (a > 2 || b > 2) {
			num = 2;
			while (num <= 100) {
				if (a % num == 0 && b % num == 0)
				{
					a /= num; b /= num;
					res = res * num; break;
				}
				else { num++; }
			}
			if (num > a || num > b) { break; }
		}

		cout << "res: " << res << endl;
	}

#pragma endregion

	return 0;
}