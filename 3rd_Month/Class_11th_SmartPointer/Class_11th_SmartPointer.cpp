#include <iostream>

using namespace std;

void setPointer(int& p2) {
	int* pointer3 = new int(200);
	p2 = *pointer3;
}

class Packet {
private:
	int errorCode = -9999;
public:
	Packet() {
		cout << "Packet Created" << endl;
	}
	~Packet() {
		cout << "Packet Released" << endl;
	}

	const int& ErrorCode() {
		return errorCode;
	}
};

class Resource {
	int data;
	shared_ptr<Resource> link;
public:
	Resource() {
		this->data = 0;
		cout << "Packet Created" << endl;
	}
	~Resource() {
		cout << "Packet Released" << endl;
	}

	const void share(shared_ptr<Resource>& target) {
		link = target;
	}

	void setData(int n) {
		this->data = n;
	}
	int getData() {
		return this->data;
	}
};

class Character {
	weak_ptr<Character> linker;

public:
	Character() {
		cout << "Character Created" << endl;
	}
	~Character() {
		cout << "Character Released" << endl;
	}

	void Partner(shared_ptr<Character>& target) {
		this->linker = target;
	}
};

int main() {
#pragma region 스마트 포인터
	// 포인터를 사용하는 동시에 자동으로 메모리 관리를 해주며,
	// 경계 확인과 같은 추가 기능을 제공하는 추상 데이터 포인터 형식
	// 종류 : unique pointer, shared pointer, weak pointer


	//int* pointer2 = nullptr;

	//// 중괄호( '{}' )는 함수 취급?
	//{
	//	int* pointer1 = new int(100);
	//	pointer2 = pointer1;
	//}
	//cout << "pointer2: " << *pointer2 << endl;

	//setPointer(*pointer2);
	//cout << "pointer2: " << *pointer2 << endl;


#pragma endregion

#pragma region unique pointer
	// 특정한 개체를 하나의 스마트 포인터만 가리킬 수 있도록 되어 있는 포인터

	/*unique_ptr<Packet> uniquePointer = make_unique<Packet>();
	cout << "uniquePointer ErrorCode: " << uniquePointer->ErrorCode() << endl;

	unique_ptr<Packet> uniqueReference = move(uniquePointer);
	cout << "uniquePointer ErrorCode: " << uniquePointer->ErrorCode() << endl;
	cout << "uniqueReference ErrorCode: " << uniqueReference->ErrorCode() << endl;*/


#pragma endregion

#pragma region shared pointer
	// 하나의 자원 객체를 여러 포인터 객체가 가리킬 수 있으며,
	// 모든 포인터 객체가 자원 객체를 필요 하지 않을 때 자원 객체를 해제하도록 설계되어있는 포인터

	//shared_ptr<Resource> s_ptr1 = make_shared<Resource>();
	//cout << "sp1 reference count: " << s_ptr1.use_count() << endl;

	//shared_ptr<Resource> s_ptr2 = s_ptr1;
	//cout << "sp1 reference count: " << s_ptr1.use_count() << endl;
	//cout << "sp2 reference count: " << s_ptr2.use_count() << endl;

	//s_ptr1->setData(5);
	//cout << "sp1 data: " << s_ptr1->getData() << endl;
	//cout << "sp2 data: " << s_ptr2->getData() << endl;
	//// sq1의 data를 변경했음에도 불구하고 sp2의 data도 변경된 것을 볼 수 있음 
	//// 정말로 둘이 같은 객체를 참조하고 있는 모양이다.

	//s_ptr2->setData(3);
	//cout << "sp1 data: " << s_ptr1->getData() << endl;
	//cout << "sp2 data: " << s_ptr1->getData() << endl;


	/*shared_ptr<Resource> oil = make_shared<Resource>();
	shared_ptr<Resource> mineral = make_shared<Resource>();

	oil->share(mineral);
	mineral->share(oil);

	cout << "oil.use_count(): " << oil.use_count() << endl;
	cout << "mineral.use_count(): " << mineral.use_count() << endl;*/



#pragma endregion

	// 숙제 - EBCO 개념 찾아보기!!
	// EBCO : Empty Base Class Optimization (빈 기본 클래스 최적화)
	//
	// 크기가 0인 빈 클래스를 상속받는 경우 베이스 클래스(부모 클래스)의 크기를 0으로 최적화 하는 것
	// empty class가 base class로 사용되는 경우에는 같은 타입의 다른 객체나 하위 객체와 동일한 주소에 할당되지 않는 한 empty class에 공간을 할당할 필요가 없음
	//
	// 빈 클래스 조건 : 비-static 변수가 없을 것, 가상(virtual) 함수가 없을 것
	// 빈 클래스의 크기는 1 (주소를 나타내는 바이트) (환경에 따라 다를 수 있음)

#pragma region weak pointer
	// 자원 객체를 소유하지 않기 때문에 공유 포인터로 관리되는 자원 객체를 가리켜서 참조 개수에 영향을 미치지 않게 하는 포인터
	/*shared_ptr<Character> char1 = make_shared<Character>();
	shared_ptr<Character> char2 = make_shared<Character>();

	char1->Partner(char2);
	char2->Partner(char1);

	cout << "char1.use_count(): " << char1.use_count() << endl;
	cout << "char2.use_count(): " << char2.use_count() << endl;*/

#pragma endregion


	return 0;
}