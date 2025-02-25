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
		T* temp = datas;
		if (this->size == 0) { this->capacity = 2; }
		else { this->capacity = this->size *2; }

		int resized = this->capacity;
		datas = new T[resized];

		if (temp == nullptr) {}
		else { 
			for (int i = 0; i < size; i++) { datas[i] = temp[i]; }
			delete temp;
		}

		cout << "capacity is resized to: " << this->capacity << endl;
	}

	void push_back(T data) {
		if (this->size == this->capacity) { this->resize(); }

		this->datas[this->size++] = data;

		cout << "벡터에 push 됨!" << endl;
	}
	void pop_back() {
		if (this->size == 0) { cout << "Pop 실패 : 벡터가 비어있음!" << endl; }
		else { this->datas[size--] = NULL; }

		cout << "벡터에서 pop 됨!" << endl;
	}

	void Capacity() {
		cout << "벡터의 capacity: " << this->capacity << endl;
	}
	void Size() {
		cout << "벡터의 size: " << this->size << endl;
	}

	void printAll() {
		for (int i = 0; i < size; i++) {
			cout << i + 1 << "번째 데이터: " << this->datas[i] << endl;
		}
		cout << endl;
	}


};

int main() {
#pragma region 벡터
	cout << "벡터 시작!" << endl;
	Vector<int> v1;
	v1.Capacity();
	v1.Size();
	// v1.pop_back();       // empty 상태에서 pop을 실행해서 에러 발생

	v1.push_back(10);
	v1.Capacity();
	v1.Size();
	v1.printAll();

	v1.push_back(20);
	v1.push_back(30);
	v1.pop_back();
	v1.Capacity();
	v1.Size();
	v1.printAll();

	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.pop_back();
	v1.push_back(70);
	v1.Capacity();
	v1.Size();
	v1.printAll();

	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.Capacity();
	v1.Size();
	v1.printAll();

	cout << endl;

#pragma endregion


	return 0;
}
