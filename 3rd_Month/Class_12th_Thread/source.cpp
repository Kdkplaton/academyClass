#include <iostream>
#include <thread>

using namespace std;

void Input() {
	for (int i = 0; i < 10; i++) {
		cout << "Input..." << endl;
	}
}
void Renderer() {
	for (int i = 0; i < 10; i++) {
		cout << "Renderer..." << endl;
	}
}

int main() {
#pragma region 스레드
	// 프로세스 내에서 실행되는 하나의 작업 단위

	/*thread t1(Input);
	thread t2(Renderer);

	t1.join();
	t2.join();*/

#pragma endregion


	return 0;
}