// Program.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
using namespace std;

class Unit {
private:
	int health;
	
	int* kill;

public:
	Unit(int health=0, int atk=6, int def=0) {
#pragma region this 포인터
		// 자기 자신(클래스, 오브젝트 등...)을 가리키는 포인터

#pragma endregion
		this->health = health;
		
		kill = new int;
		*kill = 0;
	}
	
	Unit(const Unit& clone) {
		health = clone.health;
		kill = clone.kill;
	}
	~Unit() {
		delete kill;
	}

	const int& Health() {
		return health;
	}
	const int& Kill() {
		return *kill;
	}
	void setHealth(int val) {
		this->health = val;
	}

};

int main()
{
#pragma region 복사 생성자
	// 같은 객체를 복사하여 생성기킬 때 호출되는 생성자

	// 복사 생성자를 정의하지 않고 객체를 복사하게 되면, 기본 복사생성자가 호출되기 때문에 얕은 복사로 객체가 복사됨

	//Unit marine(40);
	//Unit marine1(marine);			// 깊은 복사 (값만 복사)
	//Unit& marine2(marine);		// 얕은 복사 (주소 복사)
	//
	//// 복사 차이 확인용 값 변경
	//marine.setHealth(60);
	//marine.setAtk(7);
	//marine.setDef(1);
	//
	//cout << "marine의  health/atk/def 값: " << marine.Health() << "/" << marine.Atk() << "/" << marine.Def() << endl;
	//cout << "marine1의 health/atk/def 값: " << marine1.Health() << "/" << marine1.Atk() << "/" << marine1.Def() << endl;
	//cout << "marine2의 health/atk/def 값: " << marine2.Health() << "/" << marine2.Atk() << "/" << marine2.Def() << endl;

#pragma endregion

#pragma region 얕은 복사
	// 객체를 복사할 때 주소 값을 복사하여 샅은 메모리 공간을 가리키게 하는 것

	// 얕은 복사의 경우 같은 객체가 서로 같은 메모리 공간을 참조하고 있기 때문에
	// 하나의 객체로 값을 변경하게 되면 서로 참조된 객체도 함께 영향을 받음

	//int* ptr1 = new int;
	//int* ptr2 = ptr1;
	//int& ref1 = *ptr1;
	//int& ref2 = ref1;
	//*ptr1 = 10;
	//
	//cout << "ptr1의 주소/값: " << ptr1 << "/" << *ptr1 << endl;
	//cout << "ptr2의 주소/값: " << ptr2 << "/" << *ptr2 << endl;
	//cout << "ref1: " << ref1 << " | ref2: " << ref2 << endl << endl;
	//
	//delete(ptr1);
	//cout << "ptr2의 주소/값: " << ptr2 << "/" << *ptr2 << endl;
	//cout << "ref1: " << ref1 << " | ref2: " << ref2 << endl;
	//// 주소는 남는다...?

	Unit unit1(50);
	Unit unit2(unit1);		// 얕은 복사

	cout << "unit1의 health/kill: " << unit1.Health() << "/" << unit1.Kill() << endl;
	cout << "unit2의 health/kill: " << unit2.Health() << "/" << unit2.Kill() << endl;

	// unit1에서 delete kill; 실행시 unit2의 kill도 delete 되는 것이므로, 이후 unit2가 delete 시도시 에러가 발생한다. (이미 delete 되었으므로)

#pragma endregion


	return 0;
}

// 레퍼런스(&)와 포인터(*)의 차이 (조사하기!)
// 레퍼런스는 변수(값)의 주소를 가지지 않지만, 포인터는 주소를 가진다.


// Unity 프리펩? 기능
// 
