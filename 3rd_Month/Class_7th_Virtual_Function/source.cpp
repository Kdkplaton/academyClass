#include <iostream>
#include "../Class_7th_Virtual_Function/Terran.h"
#include "../Class_7th_Virtual_Function/Vulture.h"
#include "../Class_7th_Virtual_Function/SiegeTank.h"
#include "../Class_7th_Virtual_Function/Goliath.h"

#include <iomanip>

using namespace std;

int main() {

#pragma region 가상 함수
	// 상속하는 클래스 내에서 같은 형태의 함수로 재정의될 수 있는 함수

	// 가상 함수는 실행 시간에 상위 클래스에 대한 참조로 하위 클래스에 재정의된 함수를 호출할 수 있음

	/*Terran* t1 = new Vulture();
	Terran* t2 = new SiegeTank();
	Terran* t3 = new Goliath();

	cout << "Terran의 크기: " << sizeof(Terran) << endl;

	cout << "t1의 크기: " << sizeof(t1) << endl;
	cout << "t1의 주소: " << &(t1) << endl;
	cout << "t2의 크기: " << sizeof(t2) << endl;
	cout << "t2의 주소: " << &(t2) << endl;

	delete t1, t2, t3;*/


#pragma endregion

#pragma region 가상 함수 포인터
	// 가상 함수는 한 개 이상의 가상 함수를 포함하는 클래스가 있을 때 객체 주소에 가상 함수 테이블을 추가
	int sel;
	Terran* list[5];

	cout << "팩토리의 유닛을 5개 생산하시오. (1:벌처 2:시즈탱크 3:골리앗)\n" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번째 유닛: ";
		cin >> sel;

		if (sel == 1) {
			list[i] = new Vulture();
			list[i]->Stats();
			cout << "벌처 생산됨" << endl;
		}
		else if (sel == 2) {
			list[i] = new SiegeTank();
			list[i]->Stats();
			cout << "시즈탱크 생산됨" << endl;
		}
		else if (sel == 3) {
			list[i] = new Goliath();
			list[i]->Stats();
			cout << "골리앗 생산됨" << endl;
		}
		else {
			cout << "잘못된 선택. 다시 선택하시오" << endl;
			i--;
		}
		cout << endl;
	}
	cout << "5기 생산종료." << endl;

	// Unity 에서는 오브젝트 제거시 가비지컬렉터가 자동으로 제거해 주므로 필요 없음
	// 물론 Visual Studio는 그런거 없으니 내 컴퓨터 메모리 환경이 깨끗하게 정리해주자!
	for (int j = 0; j < 5; j++) {
		delete list[j];
	}

#pragma endregion


	return 0;
}