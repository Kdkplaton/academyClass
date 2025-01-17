#include <iostream>

using namespace std;

class Unit {
protected:
	int health;
	int defense;

public:
	Unit(int hp = 10, int def = 0) {
		this->health = hp;
		this->defense = def;

	}

	int getHP() {
		return this->health;
	}
	int getDef() {
		return this->defense;
	}

	void setHP(int HP) {
		this->health = HP;
	}

};

class Marine : public Unit {
private:
	int damage;

public:
	Marine(int atk = 6) {
		this->setHP(40);
		this->damage = atk;
	}

	int getAtk() {
		return this->damage;
	}
};

int main() {
#pragma region 캡슐화
	// 클래스 안에 서로 연관되어 있는 속성과 기능들을 하나의 캡슐로 만들어 데이터를 외부로부터 보호하며,
	// 사용자에게 인터페이스를 제공하여 클래스의 기능을 사용하게 하는 것
#pragma endregion

#pragma region 상속
	// 상위 클래스의 속성을 하위 클래스가 사용할 수 있도록 설정해주는 기능

	// 클래스의 상속 관계에서 상위 클래스는 하위 클래스의 속성을 사용할 수 없으며,
	// 하위 클래스는 상위 클래스의 메모리가 포함된 상태로 메모리의 크기가 결정됨
	
	Unit u1;
	Marine m1;

	cout << "Unit의 크기: " << sizeof(u1) << '\t';
	cout << "Marine의 크기: " << sizeof(m1) << endl;

	cout << "마린1의 체력/공격력/방어력: " << m1.getHP() << '/' << m1.getAtk() << '/' << m1.getDef() << endl;

#pragma endregion


	return 0;
}