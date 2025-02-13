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
	void setDef(int Def) {
		this->defense = Def;
	}

};

class Marine : public Unit {
private:
	int attack;
	short atkType;

public:
	Marine(int atk = 6) {
		this->setHP(40);
		this->attack = atk;
		this->atkType = 0;
	}

	int getAtk() {
		return this->attack;
	}
	void Stats() {
		cout << "마린의 체력/공격력/방어력: " << this->getHP() << " / " << this->getAtk() << " / " << this->getDef() << endl;
	}
};
class Firebat : public Unit {
private:
	int attack;
	short atkType;

public:
	Firebat(int atk = 8 * 2) {
		this->setHP(50);
		this->setDef(1);
		this->attack = atk;
		this->atkType = 0;
	}

	int getAtk() {
		return this->attack;
	}
	void Stats() {
		cout << "파이어뱃의 체력/공격력/방어력: " << this->getHP() << " / " << this->getAtk() << " / " << this->getDef() << endl;
	}
};
class Ghost : public Unit {
private:
	int attack;
	short atkType;

public:
	Ghost(int atk = 10) {
		this->setHP(45);
		this->attack = atk;
		this->atkType = 0;
	}

	int getAtk() {
		return this->attack;
	}
	void Stats() {
		cout << "고스트의 체력/공격력/방어력: " << this->getHP() << " / " << this->getAtk() << " / " << this->getDef() << endl;
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
	Firebat f1;
	Ghost g1;

	cout << "Terran의 메모리 크기: " << sizeof(u1) << endl;
	cout << "Marine의 메모리 크기: " << sizeof(m1) << endl;
	cout << "Firebat의 메모리 크기: " << sizeof(f1) << endl;
	cout << "Ghost의 메모리 크기: " << sizeof(g1) << endl << endl;

	m1.Stats();
	f1.Stats();
	g1.Stats();

#pragma endregion


	return 0;
}