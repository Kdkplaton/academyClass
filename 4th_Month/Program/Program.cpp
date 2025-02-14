#include <iostream>

using namespace std;

template <typename T>
class SingleLinkedList {
    struct Node {
    private:
        T data;
        Node* next;
    public:
        Node(int data = 0) {
            this->data = data;      // 노드 생성시 초기값 0 설정
            this->next = nullptr;
        }
        ~Node() {
            if (this->next == nullptr) {}
            else { this->next->~Node(); }
        }

        void setData(T data)        { this->data = data; }
        int getData()               { return this->data; }
        void setNext(Node* next)    { this->next = next; }
        Node* getNext()             { return next; }

    };

private:
    Node* head;
    int size;
public:  
    SingleLinkedList() {
        // 싱글-링크드-리스트 생성시 (헤드)노드를 하나 생성 / 자동으로 size도 1로 초기화
        this->head = new Node;
        this->size = 1;
    }
    // 싱글-링크드-리스트 소멸시 연결된 노드 소멸자 실행 
    // 노드와 연결된 노드의 소멸자 전부 호출하여 전체 해제
    ~SingleLinkedList() {
        this->head->~Node();
    }

    void push_front(T data) {
        Node* newNode = new Node(data);

        if (this->head == nullptr) {}
        else { newNode->setNext(this->head->getNext()); }
        
        this->head = newNode;
        this->size++;
        cout << "Node added Front!" << endl;
    }
    void push_end(T data) {
        Node* newNode = new Node(data);
        Node* cur = this->head;     // 커서 설정
        
        if (cur == nullptr) { this->head == newNode; }
        else {
            // 리스트 끝의 연결지점으로 이동
            while (cur->getNext() != nullptr) {
                cur = cur->getNext();
            }
            cur->setNext(newNode);
        }

        this->size++;
        cout << "Node added End!" << endl;
    }
    void push_at(int pos, T data) {
        Node* cur = this->head;     // 커서 설정
        
        if (this->size <= 1) { this->push_front(data); }
        else {
            Node* newNode = new Node(data);

            for (int i = 0; i < pos - 2; i++) {
                if (cur->getNext() == nullptr) { this->push_end(data); return; }
                else { cur = cur->getNext(); }
            }

            newNode->setNext(cur->getNext());
            cur->setNext(newNode);
        }
        
        cout << pos << "번째 노드의 data: " << cur->getData() << endl;
    }

    void delete_front() {
        Node* target = this->head;

        if (this->head == nullptr) { cout << "노드가 이미 없음!" << endl; }
        else {
            if (this->head->getNext() == nullptr) {
                delete target;
                this->head = nullptr;
            }
            else {
                this->head = this->head->getNext();
                this->head->setNext(this->head->getNext());
                delete target;
            }
            this->size--;
            cout << "Front node Deleted!" << endl;
        }

    }
    void delete_end() {
        Node* cur = this->head;     // 커서 설정
        Node* end;
        
        if (this->head == nullptr) { cout << "노드가 이미 없음!" << endl; }
        else {
            // 커서를 끝에서 1개 전으로 이동
            while (cur->getNext()->getNext() != nullptr) { cur = cur->getNext(); }
            end = cur->getNext();
            cur->setNext(end->getNext());       // end->getNext() 는 nullptr과 같음
            delete end->getNext();

            this->size--;
            cout << "End node Deleted!" << endl;
        }
        
    }

    void printAll() {
        Node* cur = this->head;     // 커서 설정
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
        Node* cur = this->head;     // 커서 설정
        for (int i = 0; i < pos - 1; i++) {
            if (cur->getNext() == nullptr) { cout << pos << "번째 노드는 존재하지 않음!" << endl; return; }
            else { cur = cur->getNext(); }
        }
        cout << pos << "번째 노드의 data: " << cur->getData() << endl;
    }
    void printSize() {
        cout << "리스트의 size: " << this->size << endl;
    }
    
};

int main()
{
    SingleLinkedList<int> SLL;
    SLL.printSize();
    SLL.printAll();

    SLL.delete_front();
    SLL.delete_front();
    SLL.printSize();
    SLL.printAll();

    SLL.push_front(10);
    SLL.push_end(20);
    SLL.push_end(30);
    SLL.push_end(40);
    SLL.printSize();
    SLL.printAt(3);
    SLL.printAt(1);
    SLL.printAt(4);
    SLL.printAll();

    SLL.delete_front();
    SLL.delete_end();
    SLL.printSize();
    SLL.printAt(2);
    SLL.printAt(3);
    SLL.push_at(2, 50);
    SLL.printAt(2);
    SLL.printAt(3);
    SLL.printAll();

    return 0;
}
