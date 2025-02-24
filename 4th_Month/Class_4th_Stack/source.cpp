#include <iostream>

using namespace std;

template <typename T>
struct Stack {
private:
    T* datas;
    int top, size;
public:
    Stack(int size = 5) {
        this->size = size;
        this->datas = new T[this->size];
        this->top = 0;
    }
    ~Stack() {
        while (this->top > 0) { Pop(); }
        // delete datas;        // 스택 메모리에 저장되므로 delete 할 필요가 없음
        cout << "종료전 스택 해제!" << endl;
    }

    void Push(T data) {
        if (this->top < this->size) {
            datas[top++] = data;
            cout << "스택에 데이터 Push 됨!" << endl;
        }
        else { cout << "!! Push 실패 : 스택이 가득참 !!" << endl; }
    }
    void Pop() {
        if (this->top > 0) {
            datas[top--] = NULL;
            cout << "스택에서 데이터 Pop 됨!" << endl;
        }
        else { cout << "!! Pop 실패 : 스택이 비었음 !!" << endl; }
    }
    const T Top() {
        T temp = this->datas[this->top - 1];
        return temp;
    }

    void printAll() {
        if (this->top == 0) { cout << "!! 스택이 비어있음 !!" << endl; }
        else {
            for (int i = 0; i < this->top; i++) { cout << i + 1 << "번째 data: " << this->datas[i] << endl; }
        }
        cout << endl;
    }
    const int Count() {
        return this->top;
    }

};

int main()
{
#pragma region 스택
    cout << "스택 시작!" << endl;
    Stack<int> stk1;
    cout << "스택에 데이터는 " << stk1.Count() << "개 있습니다." << endl;
    stk1.printAll();

    stk1.Push(10);
    stk1.Pop();
    stk1.Pop();
    stk1.Push(20);
    stk1.Push(30);
    stk1.Push(40);
    stk1.Push(50);
    stk1.Push(60);
    stk1.Push(70);
    cout << "스택에 데이터는 " << stk1.Count() << "개 있습니다." << endl;
    cout << "top의 값: " << stk1.Top() << endl;
    stk1.printAll();

    stk1.Pop();
    stk1.Pop();
    cout << "스택에 데이터는 " << stk1.Count() << "개 있습니다." << endl;
    stk1.printAll();

    stk1.Push(80);
    stk1.Pop();
    stk1.Push(90);
    cout << "스택에 데이터는 " << stk1.Count() << "개 있습니다." << endl;
    stk1.printAll();

#pragma endregion


    return 0;
}
