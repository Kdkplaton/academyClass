#include <iostream>

using namespace std;

template <typename T>
struct priorityQueue {
private:
	T* datas;
	int count;
public:
	priorityQueue() {
		this->datas = new T[5];
		this->count = 0;
	}
	~priorityQueue() {
		delete[] datas;
	}

	void push(T data) {
		for (int i = 0; i < 5; i++) {
			if (this->datas[i] < data) {
				for (int j = this->count - 1; j > i; j--) {

				}
			}
			else {

			}
		}

		this->datas[] = data;

	}



};

int main() {
#pragma region 우선순위 큐
	priorityQueue<int> p_Queue;
	p_Queue.push(10);



#pragma endregion


	return 0;
}