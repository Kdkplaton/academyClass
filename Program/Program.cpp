#include <iostream>
#include "Vector2.h"

using namespace std;

int main() {

#pragma region xxx


	Vector2* direction1 = new Vector2(5, 5);
	Vector2* direction2 = new Vector2(1, 1);

	direction1->coutX();
	direction1->coutY();
	direction2->coutX();
	direction2->coutY();

	Vector2 direction = (*direction1) + (*direction2);
	direction.coutX();
	direction.coutY();

	delete direction1, direction2;

#pragma endregion

#pragma region yyy

#pragma endregion


	int n;
	bool checker[42] = { false, };
	int counter = 0;

	for (int i = 0; i < 10; i++) {
		cin >> n;
		checker[n % 42] = true;
	}

	for (int j = 0; j < 42; j++) {
		if (checker[j] == true) { counter++; }
		else { continue; }
	}
	cout << counter << endl;


	return 0;
}