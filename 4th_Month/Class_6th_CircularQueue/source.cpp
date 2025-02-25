#include <iostream>

using namespace std;

template <typename T>
struct CircularQueue {
private:
    T* datas;
    int front, rear, size, capacity;       // SIZE -> capacity
public:
    CircularQueue(int capacity = 5) {
        this->capacity = capacity;
        this->datas = new T[capacity];
        this->size = 0;
        this->front = 0;
        this->rear = 0;

    }
    ~CircularQueue() {
        while (this->size > 0) { Pop(); }
        delete datas;
        cout << "종료전 원형-큐 해제!" << endl;
    }

    void Push(T data) {
        if (this->size < this->capacity) {
            if (this->rear == this->capacity) { this->rear = 0; }

            datas[this->rear++] = data;
            this->size++;

            cout << "원형-큐에 데이터 Push 됨!" << endl;
        }
        else { cout << "!! 큐가 가득 찼습니다 !!" << endl; }
    }
    void Pop() {
        if (this->size != 0) {
            if (this->front == this->capacity) { this->front = 0; }

            datas[this->front++] = NULL;
            this->size--;

            cout << "원형-큐에서 데이터 Pop 됨!" << endl;
        }
        else { cout << "!! 큐가 비어있습니다 !!" << endl; }
    }

    void printAll() {
        if (this->size == 0) { cout << "!! 큐가 비어있음 !!" << endl; }
        int idx;
        for (int i = 0; i < this->size; i++) {
            idx = this->front + i;
            if (idx >= this->capacity) { idx -= this->capacity; }

            cout << i + 1 << "번째 data: " << this->datas[idx] << endl;
        }
        cout << endl;
    }
    void printCount() {
        cout << "원형-큐에 데이터는 " << this->size << "개 있습니다." << endl;
    }

    void printFront() { cout << "front의 위치: " << this->front << endl; }
    void printRear() { cout << "rear의 위치: " << this->rear << endl; }

};

int main() {
#pragma region 원형 큐
    cout << "원형 큐 시작!" << endl;
    CircularQueue<int> c_que1;
    c_que1.printCount();
    c_que1.printAll();

    c_que1.Push(10);
    c_que1.Push(20);
    c_que1.Pop();
    c_que1.Pop();
    c_que1.Pop();
    c_que1.Push(30);
    c_que1.Push(40);
    c_que1.Push(50);
    c_que1.Push(60);
    c_que1.Push(70);
    c_que1.Push(80);
    c_que1.printFront();
    c_que1.printRear();
    c_que1.printCount();
    c_que1.printAll();

    c_que1.Pop();
    c_que1.Pop();
    c_que1.Pop();
    c_que1.Pop();
    c_que1.Pop();
    c_que1.Pop();
    c_que1.printCount();
    c_que1.printFront();
    c_que1.printRear();
    c_que1.printAll();

    c_que1.Push(90);
    c_que1.Pop();
    c_que1.Push(100);
    c_que1.Push(110);
    c_que1.Pop();
    c_que1.Push(120);
    c_que1.Push(130);
    c_que1.printCount();
    c_que1.printFront();
    c_que1.printRear();
    c_que1.printAll();

    cout << endl;

#pragma endregion


    return 0;
}