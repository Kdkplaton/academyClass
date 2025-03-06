#include <iostream>

using namespace std;

template <typename T>
struct priorityQueue {
private:
	T* datas;
	int count;
	int size;
public:
	priorityQueue(int size = 20) {
		this->size = size;
		this->datas = new T[size];
		this->count = 1;
	}
	~priorityQueue() {
		delete[] datas;
	}

	// 부모를 기준으로 했을때,
	// 왼쪽 자식	= (부모 * 2)
	// 오른쪽 자식	= (부모 * 2) + 1

	void Push(T data) {
		if (this->count == this->size) { cout << "!! Error: Priority Queue Overlaod !!" << endl; }
		else {
			this->datas[this->count] = data;

			int child = this->count;
			int parent = child / 2;

			while (child > 1) {
				if (this->datas[parent] < this->datas[child]) {
					T temp = this->datas[parent];
					this->datas[parent] = this->datas[child];
					this->datas[child] = temp;

					child = parent;
					parent = child / 2;
				}
				else { break; }
			}

			cout << "Data " << this->count++ << " Added!" << endl;
		}
	}
	void Pop() {
		int idx = 1;
		int left = idx * 2;
		int right = (idx * 2) + 1;

		if (this->count == 0) { cout << "!! Error: Priority Queue Empty !!" << endl; }
		else {
			isEmpty(left);
			isEmpty(right);

			if (this->datas[idx*2] > this->datas[(idx*2)+1]) {
				this->datas[idx] = this->datas[idx * 2];
				this->datas[idx * 2] = NULL;
			}
			else {
				this->datas[idx] = this->datas[(idx*2) +1];
				this->datas[(idx * 2) + 1] = NULL;
			}

		}
		
	}
	void isEmpty(int idx) {
		if (this->datas[idx] == NULL) {
			if (this->datas[idx * 2] > this->datas[(idx * 2) + 1]) {
				this->datas[idx] = this->datas[idx * 2];
				this->datas[idx * 2] = NULL;
			}
			else {
				this->datas[idx] = this->datas[(idx * 2) + 1];
				this->datas[(idx * 2) + 1] = NULL;
			}
		}
	}

	T Top() { return this->datas[1]; }
	int Count() { return this->count-1; }
	void showAll() {
		cout << "==== Priority Queue Data List ====" << endl;

		for (int i = 1; i < this->count; i++) {
			cout << this->datas[i] << " ";
			if (i % 5 == 0) { cout << endl; }
		}

		/*
		int sel = 1, count = 1;
		int left = 2, right = 3;

		while (count < this->count) {
			cout << this->datas[sel] << " ";
			if (count++ % 5 == 0) { cout << endl; }

			if (this->datas[left] >= this->datas[right]) {
				sel = left;

				if (left % 2 == 0) { left = left + 1; }
				else { left = left * 2; }
			}
			else {
				sel = right;

				if (right % 2 == 0) { right = right + 1; }
				else { right = right * 2; }
			}
		}
		*/

		cout << endl;
	}

};

int main() {
#pragma region 우선순위 큐
	priorityQueue<int> p_Queue;
	for (int i = 0; i < 12; i++) { p_Queue.Push((i+1)*10); }
	p_Queue.Push(150);
	p_Queue.Push(130);
	p_Queue.Push(140);
	for (int i = 16; i <= 20; i++) { p_Queue.Push(i * 10); }
	p_Queue.Push(210);
	cout << "큐의 데이터 개수: " << p_Queue.Count() << endl;
	cout << "큐의 top: " << p_Queue.Top() << endl;
	p_Queue.showAll();

	p_Queue.Pop();
	p_Queue.Pop();
	cout << "큐의 데이터 개수: " << p_Queue.Count() << endl;
	cout << "큐의 top: " << p_Queue.Top() << endl;
	p_Queue.showAll();


#pragma endregion


	return 0;
}