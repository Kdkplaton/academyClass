#include <iostream>
using namespace std;

class Unit {
private:
	int health;

	int* kill;

public:
	Unit(int health = 0, int atk = 6, int def = 0) {
#pragma region this 포인터
		// 자기 자신(클래스, 오브젝트 등...)을 가리키는 포인터

#pragma endregion
		this->health = health;

		kill = new int;
		*kill = 0;
	}

	Unit(const Unit& clone) {
		// 얕은 복사는 객체가 메모리에서 해제될 때 생성자의 실행순서와 반대로 소멸자가 실행되기 때문에,
		// 복사한 객체가 먼저 해제되므로 원래 있던 객체가 해제될 때는 이미 해제된 메모리에 접근하게 됨

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

class Item {
private:
	int* price;
	char grade;

public:
	Item(char grade = 'D') {
		this->grade = grade;
		this->price = new int;
	}
	Item(const Item& clone) {
		grade = clone.grade;
		price = new int;
	}
	~Item() {
		this->price = NULL;
	}

	char getGrade() {
		return this->grade;
	}
	int* getPrice() {
		return this->price;
	}

	void setPrice(int* price) {
		this->price = price;
	}
};

int main()
{
#pragma region 복사 생성자
	// 같은 객체를 복사하여 생성기킬 때 호출되는 생성자

	// 복사 생성자를 정의하지 않고 객체를 복사하게 되면, 기본 복사생성자가 호출되기 때문에 얕은 복사로 객체가 복사됨

	//Unit marine(40);
	//Unit marine1(marine);			// 깊은 복사 (값만 복사)
	//Unit& marine2(marine);		// 레퍼런스 대상 적용
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

	//Unit firebat1(50);
	//Unit firebat2(firebat1);		// 얕은 복사
	//
	//cout << "firebat1의 health/kill: " << firebat1.Health() << "/" << firebat1.Kill() << endl;
	//cout << "firebat2의 health/kill: " << firebat2.Health() << "/" << firebat2.Kill() << endl;

	// unit1에서 delete kill; 실행시 unit2의 kill 대상도(같으므로) delete 되는 것이므로, 이후 unit2가 delete 시도시 에러가 발생한다.

#pragma endregion

#pragma region 깊은 복사
	// 객체를 복사할 때, 참조 값이 아닌 객체 자체를 새로 복사하여 서로 다른 메모리를 생성하는 복사
	Item potion1('B');
	Item* potion2 = new Item();

	cout << "potion1의 등급: " << potion1.getGrade() << endl;
	cout << "potion2의 등급: " << potion2->getGrade() << endl;

	cout << "potion1의 가치주소: " << potion1.getPrice() << endl;
	cout << "potion2의 가치주소: " << potion2->getPrice() << endl;

	int newPrice = 20;
	potion1.setPrice(&newPrice);
	cout << "potion1의 가치: " << *(potion1.getPrice()) << endl;
	cout << "potion2의 가치: " << *(potion2->getPrice()) << endl;

#pragma endregion


	return 0;
}

// 레퍼런스(&)와 포인터(*)의 차이 (조사하기!)
// 포인터는 주소를 저장하는 변수 / 레퍼런스는 직접 변수를 참조 (주소가 아님)
// 포인터는 주소를 가지고, 레퍼런스는 변수(값)의 주소를 가지지 않음
// 포인터는 NULL을 허용하지만, 레퍼런스는 NULL을 허용하지 않음 (선언과 동시에 대상지정 해야함)

// Unity 프리펩? 기능
// 
