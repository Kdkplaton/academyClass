#include <iostream>
#include <vector>
#include <list>
#include <deque>

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
	//vector<int> v1;
	//v1.reserve(5);		// 할당크기 사전설정

	//for (int i = 1; i <= 5; i++) {
	//	v1.push_back(10*i);
	//}

	//cout << "v1.size(): " << v1.size() << endl;
	//cout << "v1.capacity(): " << v1.capacity() << endl;
	//for (int i = 0; i < v1.size(); i++) {
	//	cout << "v1[" << i << "]: " << v1[i] << endl;
	//}

	//cout << endl;

	//v1.push_back(60);
	//cout << "v1.size(): " << v1.size() << endl;
	//cout << "v1.capacity(): " << v1.capacity() << endl;
	//for (int i = 0; i < v1.size(); i++) {
	//	cout << "v1[" << i << "]: " << v1[i] << endl;
	//}

	//cout << endl;

	//// 맨 뒤의 데이터 삭제
	//v1.pop_back();
	//cout << "v1.size(): " << v1.size() << endl;
	//cout << "v1.capacity(): " << v1.capacity() << endl;
	//for (int i = 0; i < v1.size(); i++) {
	//	cout << "v1[" << i << "]: " << v1[i] << endl;
	//}

	//cout << endl;

	//v1.reserve(5);
	//// 첫번째 것도 삭제 가능!
	//v1.erase(v1.begin());
	//cout << "v1.size(): " << v1.size() << endl;
	//cout << "v1.capacity(): " << v1.capacity() << endl;
	//for (int i = 0; i < v1.size(); i++) {
	//	cout << "v1[" << i << "]: " << v1[i] << endl;
	//}

	//cout << endl;

	//v1.push_back(70);
	//v1.push_back(80);
	//cout << "v1.size(): " << v1.size() << endl;
	//cout << "v1.capacity(): " << v1.capacity() << endl;
	//for (int i = 0; i < v1.size(); i++) {
	//	cout << "v1[" << i << "]: " << v1[i] << endl;
	//}

	//cout << endl;

	//// vector의 front는 값을 직접(레퍼런스?) 참조 하는 것 같음
	//v1.front() = v1.front() + 5;
	//for (int i = 0; i < v1.size(); i++) {
	//	cout << "v1[" << i << "]: " << v1[i] << endl;
	//}

#pragma endregion

#pragma region List Container
	//list<int> list1;

	//list1.push_back(20);	// 20
	//list1.push_back(30);	// 20,30
	//cout << "list1.size(): " << list1.size() << endl;

	//list1.push_back(10);	// 10,20,30
	//cout << "list1.size(): " << list1.size() << endl;

	//list1.pop_back();	// 10,20
	//cout << "list1.size(): " << list1.size() << endl;


	//list1.assign(3, 5);	// 5,5,5
	//cout << "list1.size(): " << list1.size() << endl;

#pragma endregion

#pragma region Deque Container
	/*deque<int> deque1;

	deque1.push_back(10);
	deque1.push_back(15);

	deque1.push_front(20);
	deque1.push_front(25);
	deque1.push_front(5);

	for (int i = 0; i < deque1.size(); i++) {
		cout << "deque1[" << i << "]: " << deque1[i] << endl;
	}

	cout << endl;

	deque1.erase(deque1.begin()+2);
	for (int i = 0; i < deque1.size(); i++) {
		cout << "deque1[" << i << "]: " << deque1[i] << endl;
	}

	cout << endl;

	deque1.insert(deque1.end()-1, 30);
	for (int i = 0; i < deque1.size(); i++) {
		cout << "deque1[" << i << "]: " << deque1[i] << endl;
	}*/


#pragma endregion

	return 0;
}
