#include <iostream>
#include <stack>

using namespace std;

int main() {
#pragma region Stack
	stack<int> stk1;

	cout << "stack.push 실행" << endl;
	for (int i = 1; i <= 5; i++) { stk1.push(10 * i); }

	cout << "stack.size(): " << stk1.size() << endl;
	cout << endl;

	cout << "stack.pop 실행" << endl;
	while(stk1.empty() == false) { 
		cout << "stk1.top(): " << stk1.top() << endl;
		stk1.pop();
	}

	cout << "stack.size(): " << stk1.size() << endl;

#pragma endregion

#pragma region Queue?


#pragma endregion



	return 0;
}
