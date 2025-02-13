#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
#pragma region Stack
	/*stack<int> stk1;

	cout << "stack.push 실행" << endl;
	for (int i = 1; i <= 5; i++) { stk1.push(10 * i); }

	cout << "stack.size(): " << stk1.size() << endl;
	cout << endl;

	cout << "stack.pop 실행" << endl;
	while(stk1.empty() == false) {
		cout << "stk1.top(): " << stk1.top() << endl;
		stk1.pop();
	}

	cout << "stack.size(): " << stk1.size() << endl;*/

#pragma endregion

#pragma region Queue
	queue<int> q1;

	for (int i = 1; i <= 5; i++) {
		q1.push(10 * i);
	}

	while (q1.empty() == false) {
		cout << q1.front() << endl;
		q1.pop();
	}



#pragma endregion


	// string class
	// 문자열을 다루는 클래스
	// 문자열을 하나의 변수 type처럼 사용하며, 문자열을 훨씬 다양하고 쉽게 다룰 수 있게 해줌
	// 문자열의 끝에 '\0' 문자가 들어가지 않으며, 문자열의 길이를 동적으로 변경 가능
	// scanf와 printf에서 사용 불가능
	// 


	return 0;
}