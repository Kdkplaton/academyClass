#include <iostream>

using namespace std;

class Weapon {
	int attack;
	int intersection;
public:
	Weapon(int atk = 1, int range = 1) {
		this->attack = atk;
		this->intersection = range;
	}

	void setAtk(int attack = 1) {
		this->attack = attack;
	}

	int getAtk() {
		return this->attack;
	}
	int getRange() {
		return this->intersection;
	}

#pragma region 오버라이드
	// 상위 클래스에 있는 함수를 하위 클래스에서 재정의하여 사용하는 기능

	virtual void Attack() {
		cout << "공격! " << this->getAtk() << " 데미지!" << endl;
	}

	// 오버라이든느 상속 관계에서만 이루어지며, 하위 클래스의 함수를 재정의할 때 상위 클래스의 함수 형태와 일치해야 함

#pragma endregion




};
class Knife : public Weapon {


public:
	Knife(int attack) {
		this->setAtk(attack);
	}

	void Attack() {
		cout << "나이프 공격! " << this->getAtk() << " 데미지!" << endl;
	}
};
class Knuckles : public Weapon {


public:
	Knuckles(int attack) {
		this->setAtk(attack);
	}

	void Attack() {
		cout << "쌍너클 공격! " << this->getAtk() << " 데미지!" << endl;
	}
};

void Coordinate(int x, int y) {
	cout << "x: " << x << " y: " << y << endl;
}
void Coordinate(int x, int y, int z) {
	cout << "x: " << x << " y: " << y << " z: " << z << endl;
}
void Coordinate(float x, float y) {
	cout << "x: " << x << " y: " << y << endl;
}
void Coordinate(float x, float y, float z) {
	cout << "x: " << x << " y: " << y << " z: " << z << endl;
}

int main() {

#pragma region 다형성
	// 여러개의 서로 다른 개체가 동일한 기능을 서로 다른 방법으로 처리할 수 있는 작업

	// 다형성은 컴파일 시점에 함수와 속성이 결정되는 정적 바인딩을 하지 않고, 실행 시간에 함수와 속성이 결정될 수 있는 동적 바인딩을 가능하게 함

	/*Weapon w1;
	Knife* knife1 = new Knife(5);
	Knuckles* knuckles1 = new Knuckles(3);

	w1.Attack();
	knife1->Attack();
	knuckles1->Attack();*/

#pragma endregion

#pragma region 함수 오버로딩
	// 같은 이름의 함수를 매개 변수의 자료형과 매개변수의 수로 구분하여 여러 개를 선언할 수 있는 기능

	// 함수의 오버로딩의 경우 함수의 매개 변수에 전달하는 인수의 형태를 보고 호출하므로, 반환형으로 함수의 오버로딩을 생성할 수 없음

	Coordinate(1, 2);
	Coordinate(3, 4, 5);
	Coordinate(6.7f, 8.9f);
	Coordinate(1.2f, 3.4f, 5.6);

#pragma endregion


	return 0;
}