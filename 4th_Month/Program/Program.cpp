#include <iostream>

using namespace std;

template <typename T>
struct Node {
private:
    T data;
    Node* next;
public:
    Node(int data = 0) {
        this->data = data;      // 노드 생성시 초기값 0 설정
        this->next = nullptr;
    }
    // 소멸자 실행시 연결된 노드 소멸자 실행 (연결된 노드가 존재 한다면 실행)
    ~Node() {
        // if (this->next != nullptr) { this->next->~Node(); }
    }

    int getData() {
        return this->data;
    }
};

template <typename T, class N>
class SingleLinkedList : public Node<N> {
private:
    N* head;
    int size;
public:
    SingleLinkedList() {
        // 싱글-링크드-리스트 생성시 (헤드)노드를 하나 생성 / 자동으로 size도 1로 초기화
        this->head = new N;
        this->size = 1;
    }
    // 싱글-링크드-리스트 소멸시 연결된 노드 소멸자 실행 
    // 노드와 연결된 노드의 소멸자 전부 호출하여 전체 해제
    ~SingleLinkedList() {
        // this->head->~Node();
    }

    void push_front(T data) {
        N* newNode = new N;
        newNode->data = data;
        newNode->next = head->next;
        head = newNode;
    }
    void push_end(T data) {
        N* newNode = new N;
        newNode->data = data;

        N* cur = this->head;     // 커서 설정
        
        // 리스트 끝의 연결지점으로 이동
        while (cur->next != nullptr) { cur = cur->next; }
        
        cur = newNode;
        this->size++;
    }

    void printAll() {
        N* cur = this->head;     // 커서 설정
        int count = 1;
        
        // 리스트 끝으로 이동하면서 출력
        while (cur != nullptr) {
            cout << "노드 " << count << "의 data: " << cur->getData() << endl;
            cur = cur->next;
        }
    }
    
};

template <typename T>
int main()
{
    SingleLinkedList<int> SLL;
    //SLL->printAll();

    //SLL->newNode(10);
    //SLL->newNode(20);
    //SLL->newNode(30);
    //SLL->newNode(40);
    //SLL->printAll();

    return 0;
}
