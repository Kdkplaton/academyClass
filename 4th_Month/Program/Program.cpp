#include <iostream>
using namespace std;

template <typename T>
struct hashTable {
private:
	char** key;
	T* data;
	int size;

public:
	hashTable(int max = 5) {
		this->size = 0;
		this->key = new char* [max];
		this->data = new T[max];
	}
	~hashTable() {
		delete key;
		delete data;
	}

	void Add(char* key, T* data) {
		for (int i = 0; i < size; i++) {
			if (this->key[i] = key) {}
			else {}
		}


	}

};

struct String {
private:
	char* string;
	int size;
public:
	String(char* input = nullptr) {
		this->string = input;
		this->size = 0;
	}
	~String() {
		delete this->string;
	}

	int getLen(const char* target) {
		int count = 0;
		while (target[count] != '\0') { count++; }

		return count;
	}

	void operator = (const char* input) {
		// 1. 복사할 문자열 크기 구하기 & 메모리 생성
		int length = getLen(input);		// 문자열 길이 구하기
		this->size = length +1;					// 문자열 크기 설정
		char* temp = new char[this->size];		// 설정된 크기로 메모리 생성

		// 2. 생성된 메모리에 문자열 복사
		int idx = 0;
		while (input[idx] != '\0') {
			temp[idx] = input[idx++];
		}
		temp[idx] = '\0';		// 문자열에 '\0'는 복사되지 않았으므로 '\0'도 복사

		// 3. 기존 메모리 해제 및 포인터 지정
		delete[] this->string;	// 기존 메모리 할당 해제
		this->string = temp;	// 복사된 메모리 지정

		temp = nullptr;			// 복사에 사용한 포인터가 지정하는 메모리 변경
		delete temp;			// 복사에 사용한 포인터 해제 (안해도 됨?)
	}
	void operator + (const char* target) {
		int addLength = getLen(target);
		char* temp = new char[this->size + addLength];

		// 기존 문자열
		int idx = 0;
		while (this->string[idx] != '\0') {
			temp[idx] = this->string[idx++];
		}
		int endPoint = idx;

		// 추가할 문자열
		idx = 0;
		while (target[idx] != '\0') {
			temp[endPoint + idx] = target[idx++];
		}
		temp[endPoint + idx] = '\0';

		// 크기 변경
		int totalLength = getLen(temp);
		this->size = totalLength + 1;

		delete[] this->string;
		this->string = temp;

		temp = nullptr;
		delete temp;

	}

	const char* getStr() { return this->string; }
	void printStr() { cout << this->string << endl; }
	int Size() { return this->size; }
	
};

int main() {
#pragma region 문자열(String)
	String str1;
	str1 = "Hello World!";
	
	str1.printStr();
	cout << "문자열 크기: " << str1.Size() << endl;
	cout << "문자열 길이: " << str1.getLen(str1.getStr()) << endl;
	
	cout << endl;

	str1 = "Hello";
	str1 + "World!";
	str1.printStr();
	cout << "문자열 크기: " << str1.Size() << endl;
	cout << "문자열 길이: " << str1.getLen(str1.getStr()) << endl;

	cout << endl;

#pragma endregion


	return 0;
}
