#include <iostream>
#include "Terran.h"
#include "Vulture.h"
#include "SiegeTank.h"
#include "Goliath.h"

using namespace std;

int main() {

#pragma region 가상 함수
	// 상속하는 클래스 내에서 같은 형태의 함수로 재정의될 수 있는 함수

	// 가상 함수는 실행 시간에 상위 클래스에 대한 참조로 하위 클래스에 재정의된 함수를 호출할 수 있음

	Terran* t1 = new Vulture();
	Terran* t2 = new SiegeTank();
	Terran* t3 = new Goliath();

	t1->Stats();
	t2->Stats();
	t3->Stats();

	delete t1, t2, t3;


#pragma endregion


	


	return 0;
}