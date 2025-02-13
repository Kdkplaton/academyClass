#include <iostream>
#include "../Program/Vector2.h"

using namespace std;

Vector2 operator+ (int val1, Vector2& val2) {
	
	return val1 + val2;
}

int main() {

#pragma region 연산자 오버로딩
	Vector2* direction1 = new Vector2(8, 8);
	Vector2* direction2 = new Vector2(2, 2);

	cout << "direction1.x: " << direction1->getX() << " direction1.y: " << direction1->getY() << endl;
	cout << "direction2.x: " << direction2->getX() << " direction2.y: " << direction2->getY() << endl;

	/*Vector2 res1 = (*direction1) + (*direction2);
	cout << "res1.x: " << res1.getX() << " res1.y: " << res1.getY() << endl;
	Vector2 res2 = (*direction1) - (*direction2);
	cout << "res2.x: " << res2.getX() << " res2.y: " << res2.getY() << endl;
	Vector2 res3 = (*direction1) * (*direction2);
	cout << "res3.x: " << res3.getX() << " res3.y: " << res3.getY() << endl;
	Vector2 res4 = (*direction1) / (*direction2);
	cout << "res4.x: " << res4.getX() << " res4.y: " << res4.getY() << endl;*/

	++(*direction1);
	cout << "direction1.x: " << direction1->getX() << " direction1.y: " << direction1->getY() << endl;
	(*direction1)++;
	cout << "direction1.x: " << direction1->getX() << " direction1.y: " << direction1->getY() << endl;
	(*direction2)--;
	cout << "direction2.x: " << direction2->getX() << " direction2.y: " << direction2->getY() << endl;
	cout << "direction2.x: " << direction2->getX() << " direction2.y: " << direction2->getY() << endl;

	
	// delete res1, res2, res3, res4;
	
#pragma endregion

#pragma region 교환 법칙
	// 교환법칙 - 주말에 복습하기!
	// A + B = B + A

	// 

	int val = 3;
	Vector2 res5 = val + (*direction1);
	cout << "res5.x: " << res5.getX() << " res5.y: " << res5.getY() << endl;

#pragma endregion

	delete direction1, direction2;

	return 0;
}