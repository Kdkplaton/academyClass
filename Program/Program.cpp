#include <iostream>

using namespace std;

template <typename T>
class List {
private:
	int size;
	int index;

	T* datas;

public:
	List() {
		this->size = 0;
		this->index = 0;
		this->datas = nullptr;
	}
	~List() {
		if (this->datas == nullptr) { cout << "!! 해제할 대상이 없음 !!" << endl; }
		else {
			delete [] datas;
			cout << "포인터 해제됨!" << endl;
		}
		
	}
	void Resize(int size) {
		this->size = size;
		this->datas = new T[size];
		
		for (int i = 0; i < size; i++) { datas[i] = 0; }
	}
	void AddData(T data) {
		if (this->index == this->size) { cout << "!! 리스트 최대치 도달 !!" << endl << endl; }
		else { this->datas[(this->index)++] = data; }
		
	}
	int getSize() {
		return this->size;
	}

	void Print() {
		if (this->index == 0) { cout << "!! 리스트가 비어있음 !!" << endl; }
		else {
			cout << "클래스 내에서 출력 / List 크기: " << this->size << endl;
			for (int i = 0; i < this->size; i++) { cout << "list[" << i << "]: " << datas[i] << endl; }
			cout << "포인터의 크기: " << sizeof(datas) << endl << endl;
		}
	}
	T operator [] (int idx) {
		// 배열 접근시 역순으로 출력되도록 설정
		return datas[(this->size -1) -idx];
	}


};

template <typename T>
bool Same(T val1, T val2) {
	return (val1 == val2);
}

template<>
bool Same(char* str1, char* str2) {
	int idx = 0;
	while (str1[idx]==EOF && str2[idx] == EOF) {
		if (str1[idx] == EOF) {

			break;
		}
		else if (str2[idx] == EOF) {

			break;
		}
		idx++;
	}
	return true;
}

int main() {

#pragma region 템플릿
	// 데이터 형식에 의존하지 않고, 하나의 값이 여러 다른 데이터 형식을 가질 수 있는 기술에 중점을 두어 재사용성을 높일 수 있는 기능

	/*List<int> list1;
	List<bool> list2;

	list1.Resize(5);
	list1.AddData(4);
	list1.AddData(3);
	list1.AddData(2);
	list1.AddData(1);
	list1.AddData(0);
	list1.AddData(-1);
	list1.Print();

	cout << "클래스 밖에서 접근하여 출력" << endl;
	for (int i = 0; i < list1.getSize(); i++) { cout << "list[" << i << "]: " << list1[i] << endl; }
	cout << "list1의 크기: " << sizeof(list1) << endl;

	cout << endl;
	list2.Print();*/

#pragma endregion

#pragma region 템플릿 특수화
	// 특정 자료형에 대해 다르게 처리하고 싶을 경우 특정한 자료형만 다른 형식으로 동작시키는 탬플릿 기능

	// 

	cout << "True = 1 / False = 0" << endl;
	cout << "res1: " << Same(2, 2) << "    res2: " << Same(4, 7) << endl;
	cout << "res3: " << Same(2.0f, 2.0f) << "    res4: " << Same(2.3f, 2.7f) << endl;
	cout << "res5: " << Same('X', 'X') << "    res6: " << Same('Y', 'Z') << endl;

	cout << "res7: " << Same("Hello", "World") << "    res8: " << Same("Nice", "Job") << endl;

#pragma endregion



	return 0;
}