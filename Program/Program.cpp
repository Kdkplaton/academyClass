#include <iostream>
#include <vector>

using namespace std;

int main() {
#pragma region STL ()
	// 선형 컨테이너
	// vector, list, deque, string

	// 컨테이너 어댑터
	// stack, queue, priority_queue 

	// 연관 컨테이너
	//



#pragma endregion

#pragma region Vector Container
	vector<int> v1;
	v1.reserve(5);

	for (int i = 1; i <= 5; i++) {
		v1.push_back(10*i);
	}

	cout << "v1.size(): " << v1.size() << endl;
	cout << "v1.capacity(): " << v1.capacity() << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << "v1[" << i << "]: " << v1[i] << endl;
	}

	cout << endl;

	v1.push_back(60);
	cout << "v1.size(): " << v1.size() << endl;
	cout << "v1.capacity(): " << v1.capacity() << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << "v1[" << i << "]: " << v1[i] << endl;
	}

	cout << endl;

	// 맨 뒤의 데이터 삭제
	v1.pop_back();
	cout << "v1.size(): " << v1.size() << endl;
	cout << "v1.capacity(): " << v1.capacity() << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << "v1[" << i << "]: " << v1[i] << endl;
	}

	cout << endl;

	v1.reserve(5);
	// 첫번째 것도 삭제 가능!
	v1.erase(v1.begin());
	cout << "v1.size(): " << v1.size() << endl;
	cout << "v1.capacity(): " << v1.capacity() << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << "v1[" << i << "]: " << v1[i] << endl;
	}

	cout << endl;

	v1.push_back(70);
	v1.push_back(80);
	cout << "v1.size(): " << v1.size() << endl;
	cout << "v1.capacity(): " << v1.capacity() << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << "v1[" << i << "]: " << v1[i] << endl;
	}

	cout << endl;

	v1.front() = v1.front() + 5;
	for (int i = 0; i < v1.size(); i++) {
		cout << "v1[" << i << "]: " << v1[i] << endl;
	}

#pragma endregion


	


	return 0;
}