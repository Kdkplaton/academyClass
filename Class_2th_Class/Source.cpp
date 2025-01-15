// Program.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class GameObject {
#pragma region 접근 지정자
	// 클래스 내부에 포함되어 있는 속성에 접근 범위를 제한하는 지정자

	// public : 클래스 내부와 자기가 상속하고 있는 클래스 그리고 클래스 외부에서도 접근을 허용하는 지정자
	// protected : 클래스 내부와 자기가 상속하고 있는 클래스까지만 접근을 허용하는 지정자
	// private : 클래스 내부만 접근을 허용하는 지정자



#pragma endregion

private:
	int x;
protected:
	int y;
public:
	int z;

	int Z() {
		return z;
	}

	// 생성자와 소멸자 정의
	GameObject() {
		x = 0;
		y = 1;
		z = 2;
	}
	~GameObject() {

	}

	// 반환자 및 지정자 (get & set) 정의
	int getX() {
		return this->x;
	}
	void setZ(int value) {
		this->z = value;
	}


};

void Swap1(int x, int y) {
	int n = x;
	x = y;
	y = n;
}
void Swap2(int& x, int& y) {
	int n = x;
	x = y;
	y = n;
}

int main()
{
#pragma region 클래스
	// 사용자 정의 데이터 유형으로 속성과 함수가 포함되어있으며,
	// 클래스를 통해 객체를 생성하여 접근하고 사용하는 집합체

	// 클래스의 경우 클래스 내부에 있는 변수는 클래스의 메모리 영역에 포함되지만,
	// 정적 변수와 함수의 메모리는 클래스 영역에 포함되지 않음

	// !! 클래스 내의 변수는 기본적으로 (접근지정자 미지정시) private 속성 !!

	/*GameObject gameObject1, gameObject2, gameObject3;

	gameObject1.setZ(5);
	gameObject2.setZ(10);
	gameObject3.setZ(20);

	cout << "gameObject1의 z값: " << gameObject1.Z() << endl;
	cout << "gameObject2의 z값: " << gameObject2.Z() << endl;
	cout << "gameObject3의 z값: " << gameObject3.Z() << endl;*/

#pragma endregion

#pragma region 참조자
	// 어떤 변수의 메모리 공간에 다른 이름을 지정하는 지정자

	/*int data = 10;
	int& reference = data;

	cout << "data의 값: " << data << endl;
	cout << "reference의 값: " << reference << endl;

	reference = 20;
	cout << "data의 값: " << data << endl;
	cout << "reference의 값: " << reference << endl;*/

	/*int a = 111;
	int b = 222;

	Swap1(a, b);
	cout << "Swap1 (Call by Value)" << endl;
	cout << "a의 값: " << a << endl;
	cout << "b의 값: " << b << endl;

	Swap2(a, b);
	cout << "Swap2 (Call by Reference)" << endl;
	cout << "a의 값: " << a << endl;
	cout << "b의 값: " << b << endl;*/

#pragma endregion


}

// C언어 -> 구조체 (값타입?)
// C++ -> 클래스 (참조타입) 멀티-패러다임 언어
