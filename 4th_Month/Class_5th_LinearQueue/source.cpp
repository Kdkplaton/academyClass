#include <iostream>

using namespace std;

template <typename T>
struct LinearQueue {
private:
    T* datas;
    int front, rear, size, count;
public:
    LinearQueue(int size = 5) {
        this->size = size;
        this->datas = new T[this->size];
        this->front = 0;
        this->rear = 0;
        this->count = 0;
    }
    ~LinearQueue() {
        while (this->rear != this->front) { Pop(); }
        delete datas;
        cout << "종료전 선형-큐 해제!" << endl;
    }

    void Push(T data) {
        if (this->rear < this->size) {
            datas[rear++] = data; this->count++;
            cout << "큐에 데이터 Push 됨!" << endl;
        }
        else { cout << "!! Push 실패 : 큐가 가득 찼습니다 !!" << endl; }
    }
    void Pop() {
        if (this->front < this->rear) {
            datas[front++] = NULL; this->count--;
            cout << "큐에서 데이터 Pop 됨!" << endl;
            if (this->front == this->rear) { this->front = 0; this->rear = 0; }
        }
        else { cout << "!! Pop 실패 : 큐가 비어있습니다 !!" << endl; }
    }

    void printAll() {
        if (this->front == this->rear) { cout << "!! 큐가 비어있음 !!" << endl; }
        for (int i = 0; i < this->count; i++) {
            cout << i + 1 << "번째 data: " << this->datas[this->front + i] << endl;
        }
        cout << endl;
    }
    void printCount() {
        cout << "큐에 데이터는 " << this->count << "개 있습니다." << endl;
    }

};

int main() {
#pragma region 큐
    cout << "선형 큐 시작!" << endl;
    LinearQueue<int> l_que1;
    l_que1.printCount();
    l_que1.printAll();

    l_que1.Push(10);
    l_que1.Pop();
    l_que1.Pop();
    l_que1.Push(20);
    l_que1.Push(30);
    l_que1.Push(40);
    l_que1.Push(50);
    l_que1.Push(60);
    l_que1.Push(70);
    l_que1.printCount();
    l_que1.printAll();

    l_que1.Pop();
    l_que1.Pop();
    l_que1.Pop();
    l_que1.printCount();
    l_que1.printAll();

    l_que1.Push(80);
    l_que1.Pop();
    l_que1.Push(90);
    l_que1.printCount();
    l_que1.printAll();

#pragma endregion

    return 0;
}
