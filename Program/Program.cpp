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

	const int & ErrorCode() {
		return errorCode;
	}
};

class Resource {
	int data;
public:
	Resource() {
		this->data = 0;
		cout << "Packet Created" << endl;
	}
	~Resource() {
		cout << "Packet Released" << endl;
	}

	void setData(int n) {
		this->data = n;
	}
	int getData() {
		return this->data;
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

	shared_ptr<Resource> s_ptr1 = make_shared<Resource>();
	cout << "sp1 reference count: " << s_ptr1.use_count() << endl;

	shared_ptr<Resource> s_ptr2 = s_ptr1;
	cout << "sp1 reference count: " << s_ptr1.use_count() << endl;
	cout << "sp2 reference count: " << s_ptr2.use_count() << endl;

	s_ptr1->setData(5);
	cout << "sp1 data: " << s_ptr1->getData() << endl;
	cout << "sp2 data: " << s_ptr2->getData() << endl;
	// sq1의 data를 변경했음에도 불구하고 sp2의 data도 변경된 것을 볼 수 있음 
	// 정말로 둘이 같은 객체를 참조하고 있는 모양이다.

	s_ptr2->setData(3);
	cout << "sp1 data: " << s_ptr1->getData() << endl;
	cout << "sp2 data: " << s_ptr1->getData() << endl;

	// 숙제 - EBCO 개념 찾아보기!!
#pragma endregion

#pragma region weak pointer
	// 

#pragma endregion


	return 0;
}