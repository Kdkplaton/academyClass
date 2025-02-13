// Program.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
using namespace std;

namespace Austraila
{
	int area = 75357;

	void Size() { cout << "Austraila Area: " << area << endl; }
}
namespace China
{
	int area = 6543456;

	void Size() { cout << "China Area: " << area << endl; }
}

class Object {
private:
	int n;
	static int count;

public:
	Object(int x) {
		this->n = x;
		count = 0;
		cout << "클래스 'Object' 생성됨" << endl;
	}
	~Object() {
		count++;
		cout << "(static) count 값: " << count << endl;

		cout << "클래스 'Object' 제거됨" << endl;
	}

	int getN() {
		return this->n;
	}
};

int Object::count = 0;

int main()
{
#pragma region 이름공간(NameSpace)
	// 속성을 구분할 수 있도록 유효 범위를 설정하는 영역

	/*Austraila::Size();
	China::Size();*/

#pragma endregion

#pragma region 생성자
	// 클래스의 인스턴스가 생성되는 시점에서 자동으로 호출되는 특수한 멤버 함수

	// 생성자의 경우 객체가 생성될 때 단 한번만 호출되며,
	// 생성자는 반환형이 존재하지 않기 때문에 생성자가 호출되기전에는 객체에 대한 메모리가 할당되지 않음

	// 생성자에는 매개변수를 사용할 수 있음

	// Object OBJ;
	// cout << "OBJ's n: " << OBJ.getN() << endl;

#pragma endregion

#pragma region 소멸자
	// 객체가 소멸될 때 자동으로 실행되는 클래스의 멤버 함수

	// 소멸자는 객체가 메모리에서 해제될 때 단 한 번만 호출되며,
	// 소멸자에는 매개 변수를 생성하여 사용할 수 없음

	/*Object OBJ(7);
	cout << "OBJ의 n: " << OBJ.getN() << endl;*/

	/*Object* obj1 = new Object(3);
	Object* obj2 = new Object(6);
	Object* obj3 = new Object(9);

	cout << "obj1's n: " << obj1->getN() << endl;
	cout << "obj2's n: " << obj2->getN() << endl;
	cout << "obj3's n: " << obj3->getN() << endl;

	delete obj1;
	delete obj2;
	delete obj3;*/

#pragma endregion

	return 0;
}
