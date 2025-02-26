#include <iostream>
using namespace std;

template <typename T>
struct Vector {
private:
	T* datas;
	int capacity;
	int size;
public:
	Vector() {
		this->capacity = 0;
		this->datas = nullptr;
		this->size = 0;
	}
	~Vector() {
		delete datas;
	}

	void resize() {
		// 제시된 방법
		// 1. capacity에 새로운 size값 저장
		// 2. 새로운 포인터 변수를 생성하여 새로 만들어진 메모리 공간 지정
		// 3. 새로운 메모리 공간의 값 초기화
		// 4. 기존 배열에 있는 값을 복사하여 새로운 배열에 저장
		// 5. 기존 배열의 메모리를 해제
		// 6. 기존 배열을 가리키던 포인터 변수의 값을 새로운 배열의 시작 주소로 변경

		// 해결한 방법
		// 1. capacity에 새로운 size값 저장
		// 2. 새로운 포인터 변수를 생성하여 기존 메모리 공간 지정
		// 3. 새로운 메모리 공간 생성하여 기존 배열을 가리키던 포인터 변수로 지정
		// 4. (새로 생성한 포인터 변수가 가리키는) 기존 메모리 공간의 값을 새 메모리 공간에 복사, 나머지 빈 공간 초기화
		// 5. 기존 메모리 공간 해제

		if (this->capacity == 0) { this->capacity = 2; }
		else { this->capacity = this->size *2; }

		T* temp = this->datas;
		int resized = this->capacity;
		this->datas = new T[resized];

		for (int i = 0; i < this->capacity; i++) {
			if (i < this->size) { this->datas[i] = temp[i]; }
			else { this->datas[i] = NULL; }
		}
		delete temp;

		cout << "capacity is resized to: " << this->capacity << endl;
	}

	void push_back(T data) {
		if (this->size == this->capacity) { this->resize(); }

		this->datas[this->size++] = data;
		cout << "벡터에 push 됨!" << endl;
	}
	void pop_back() {
		if (this->size == 0) { cout << "Pop 실패 : 벡터가 비어있음!" << endl; }
		else {
			this->datas[--size] = NULL;
			cout << "벡터에서 pop 됨!" << endl;
		}
	}

	T Front() { return this->datas[0]; }
	T Back() { return this->datas[this->size -1]; }
	T* Begin() { return &(this->datas[0]); }
	T* End() { return &(this->datas[this->size]); }		// !! end는 마지막 데이터 주소의 다음을 말함 !!

	const int Capacity() { return this->capacity; }
	const int Size() { return this->size; }

	void printAll() {
		for (int i = 0; i < this->size; i++) {
			if (this->datas[i] == NULL) { cout << "!! 비어있는 공간 !!" << endl; }
			else { cout << i + 1 << "번째 데이터: " << this->datas[i] << endl; }
		}
		cout << endl;
	}

};

int main() {
#pragma region 벡터
	cout << "벡터 시작!" << endl;
	Vector<int> v1;
	cout << "벡터의 capacity: " << v1.Capacity() << endl;
	cout << "벡터의 size: " << v1.Size() << endl;
	v1.pop_back();

	v1.push_back(10);
	cout << "벡터의 capacity: " << v1.Capacity() << endl;
	cout << "벡터의 size: " << v1.Size() << endl;
	v1.printAll();

	v1.push_back(20);
	v1.push_back(30);
	v1.pop_back();
	cout << "벡터의 capacity: " << v1.Capacity() << endl;
	cout << "벡터의 size: " << v1.Size() << endl;
	v1.printAll();

	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.pop_back();
	v1.push_back(70);
	v1.push_back(80);
	v1.pop_back();
	cout << "벡터의 capacity: " << v1.Capacity() << endl;
	cout << "벡터의 size: " << v1.Size() << endl;
	cout << "벡터의 front(첫번째 값): " << v1.Front() << endl;
	cout << "벡터의 back(마지막 값): " << v1.Back() << endl;
	cout << "벡터의 begin(첫번째 주소): " << v1.Begin() << endl;
	cout << "벡터의 end(마지막 주소): " << v1.End() << endl;
	v1.printAll();

	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	cout << "벡터의 capacity: " << v1.Capacity() << endl;
	cout << "벡터의 size: " << v1.Size() << endl;
	v1.printAll();

	cout << endl;

#pragma endregion


	return 0;
}
