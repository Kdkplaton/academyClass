// Program.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int data = 1;

int main()
{
#pragma region 스트림
	// 시간의 흐름에 따라 연속적으로 발생하는 데이터의 흐름

	// << (삽입 연산자)
	// 자신이 참조하고 있는 값을 반환하여 출력하는 연산자

	/*
	int errorCode = -9999;
	cout << "Hello World!" << endl;
	cout << "에러코드는 " << errorCode << " 입니다.";
	*/

	// >> (추출 연산자)
	// 특정한 값을 입력받은 다음 버퍼에 저장하는 연산자

	/*
	int n = 0;
	cin >> n;
	cout << "n의 값: " << n << endl;
	*/

#pragma endregion

#pragma region 범위 지정 연산자
	// 여러 범위에서 사용되는 식별자를 구분하는데 사용하는 연산자

	// 범위 지정 연산자는 전역 변수와 같은 이름의 지역 변수가 선언되었을때,
	// 가장 가까운 범위에 선언된 변수의 이름을 사용하는 범위 규칙이 존재하기 때문에 전역 변수가 호출되지 않음

	/*
	int data = 10;
	cout << "지역변수 data의 값: " << data << endl;
	cout << "전역변수 data의 값: " << ::data << endl;
	*/

#pragma endregion

#pragma region 동적 할당
	// 프로그램을 실행 중에 필요한 만큼 메모리를 할당하는 작업

	// 64bit 운영체제에서 포인터의 크기 : 8 Byte

	int* p = new int;
	*p = 100;
	cout << "*p's Value: " << *p << endl;
	cout << "p's Address Value: " << p << endl;

	delete p;

	p = new int[3];
	for (int i = 0; i < 3; i++) {
		*(p + i) = 10 + (i * 10);
	}

	for (int i = 0; i < 3; i++) {
		cout << "p의 " << i+1 << " 번째 값: " << p[i] << endl;
	}
	cout << "p[0]의 Address Value: " << &(p[0]) << endl;
	cout << "p의 Address Value: " << p << endl;

	delete[ ] p;

#pragma endregion

}

// 스택메모리


// 힙메모리

