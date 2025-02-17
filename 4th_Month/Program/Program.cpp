#include <iostream>

using namespace std;

template <typename T>
struct Node {
private:
    T data;
    Node* next;
    Node* prev;
public:
    Node(T data = 0) {
        this->data = data;      // 노드 생성시 초기값 설정
        this->next = nullptr;
        this->prev = nullptr;
    }
    ~Node() {       // head가 첫 노드를 가리키므로 이전노드는 고려하지 않음 (처음 -> 끝 방향 실행)
        if (this->next == nullptr) {}
        else { this->next->~Node(); }
    }

    // private 멤버 변수에 접근가능한 기능(함수)
    void setData(T data) { this->data = data; }
    int getData() { return this->data; }
    void setNext(Node* next) { this->next = next; }
    Node* getNext() { return next; }
    void setPrev(Node* prev) { this->prev = prev; }
    Node* getPrev() { return this->prev; }

};

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    DoubleLinkedList() {
        // 리스트 생성시 (헤드)노드를 하나 생성 / 자동으로 size도 1로 초기화
        this->head = new Node<T>();
        this->tail = this->head;
        this->size = 1;
    }
    // 소멸시 연결된 노드 소멸자 실행 
    // 노드와 연결된 노드의 소멸자 전부 호출하여 전체 해제
    ~DoubleLinkedList() {
        this->head->~Node();
    }

    void push_front(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (this->head == nullptr) { this->tail = newNode; }    // head가 비어있다면 tail도 비어있음
        else {
            newNode->setNext(this->head->getNext());
            newNode->getNext()->setPrev(newNode);
        }

        this->head = newNode;
        this->size++;
        cout << "Node added Front!" << endl;
    }
    void push_end(T data) {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* cur = this->tail;     // 커서 설정
        
        if (cur == nullptr) { this->head == newNode; }    // tail이 비어있다면 head도 비어있음
        else {
            newNode->setPrev(cur);
            cur->setNext(newNode);
        }

        this->tail = newNode;
        this->size++;
        cout << "Node added End!" << endl;
    }
    void push_at(int pos, T data) {
        Node<T>* cur = this->head;     // 커서 설정

        if (this->size <= 1) { this->push_front(data); }
        else {
            Node<T>* newNode = new Node<T>(data);

            if (pos > size) { this->push_end(data); }
            else {
                for (int i = 0; i < pos - 2; i++) {
                    if (cur->getNext() == nullptr) {}
                    else { cur = cur->getNext(); }
                }
            }

            newNode->setNext(cur->getNext());
            cur->setNext(newNode);
        }
        cout << "Node inserted At: " << pos << "!" << endl;
    }

    void delete_front() {
        Node<T>* target = this->head;

        if (target == nullptr) { cout << "노드가 이미 없음!" << endl; }
        else {
            if (target->getNext() == nullptr) {
                delete target;
                this->head = nullptr;
                this->tail = nullptr;
            }
            else {
                this->head = this->head->getNext();     // head를 2번째 것으로 설정
                this->head->setPrev(nullptr);      // 2번째 것을 가리키는 head의 prev를 nullptr로 설정
                delete target;                          // 1번째 것을 삭제
            }
            this->size--;
            cout << "Front node Deleted!" << endl;
        }

    }
    void delete_end() {
        Node<T>* target = this->tail;     // 커서 설정

        if (this->head == nullptr) { cout << "노드가 이미 없음!" << endl; }
        else {
            if (target->getPrev() == nullptr) {
                delete target;
                this->head = nullptr;
                this->tail = nullptr;
            }
            else {
                this->tail = target->getPrev();                 // tail을 끝의 이전 노드로 설정
                target->getPrev()->setNext(nullptr);       // 끝의 이전 노드의 next를 nullptr로 설정
                delete target;                                  // 끝 노드 삭제
            }

            this->size--;
            cout << "End node Deleted!" << endl;
        }

    }

    // push_at 수정해야 함
    // prev 관련 함수 작성해야 함

    void printAll() {
        Node<T>* cur = this->head;     // 커서 설정
        int count = 1;

        // 리스트 끝으로 이동하면서 출력
        if (cur == nullptr) { cout << "노드 없음!" << endl; }
        else {
            while (cur != nullptr) {
                cout << "노드 " << count << "의 data: " << cur->getData() << endl;
                cur = cur->getNext();
                count++;
            }
        }
        cout << endl;
    }
    void printAt(int pos) {
        Node<T>* cur = this->head;     // 커서 설정
        for (int i = 0; i < pos - 1; i++) {
            if (cur->getNext() == nullptr) { cout << pos << "번째 노드는 존재하지 않음!" << endl; return; }
            else { cur = cur->getNext(); }
        }
        cout << pos << "번째 노드의 data: " << cur->getData() << endl;
    }
    void printSize() { cout << "리스트의 size: " << this->size << endl; }

};

int main()
{
#pragma region 양방향 연결 리스트
    cout << "Double Linked List 시작!" << endl;
    DoubleLinkedList<int> DLL;
    DLL.printSize();
    DLL.printAll();

    DLL.delete_end();
    DLL.delete_end();
    DLL.printSize();
    DLL.printAll();

    DLL.push_front(10);
    DLL.push_end(20);
    DLL.push_end(30);
    DLL.push_end(40);
    DLL.printSize();
    DLL.printAll();

    DLL.delete_front();
    DLL.delete_end();
    DLL.printSize();
    DLL.printAll();

#pragma endregion

    

    return 0;
}
