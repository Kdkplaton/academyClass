#include <iostream>
#include <time.h>
#include <random>
#include <cmath>
using namespace std;

bool isPrime(int target) {

	if (target < 2) { return false; }

	for (int i = 2; i < target; i++) {
		if (target % i == 0) { return false; }
	}

	return true;
}

void sieve(int num) {
	int* prime = new int[num];
	for (int i = 1; i < num; i++) { prime[i] = i + 1; }
	prime[0] = -1;

	// sqrt(n) : n의 제곱근을 구하는 함수 - cpp기준 <cmath> 참조
	for (int i = 2; i < sqrt(num); i++) {
		for (int j = 2; j < num; j++) {
			if (prime[j] == i) { continue; }
			else if (j % i == 0) { prime[j] = -1; }
		}
	}

	cout << num << " 이전까지의 소수: ";
	for (int i = 1; i < num; i++) {
		\
			if (prime[i] == -1) { continue; }
			else { cout << prime[i] << " "; }
	}
	cout << endl;

	delete[] prime;
}

int main() {
#pragma region 에라테네토스의 체
	srand(time(0));

	cout << "에라테네토스의 체 10회 시행" << endl;

	// cout << "---- isPrime() 함수 사용! ----" << endl;
	cout << "---- isPrime() 함수 미사용! ----" << endl;

	for (int k = 0; k < 10; k++) {
		int num = rand() % 90 + 10;

		/*
		cout << num << "까지의 소수: ";
		for(int i=2; i<num; i++) {
			if(isPrime(i) == false) { continue; }
			else { cout << i << " "; }
		}
		cout << endl;
		*/

		sieve(num);

	}

#pragma endregion

	return 0;
}