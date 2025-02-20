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

    // private 멤버 변수에 접근가능한 기능(함수)
    void setData(T data) { this->data = data; }
    int getData() { return this->data; }
    void setNext(Node* next) { this->next = next; }
    Node* getNext() { return next; }
    void setPrev(Node* prev) { this->prev = prev; }
    Node* getPrev() { return this->prev; }
};

template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;
    int size;
public:
    CircularLinkedList() {
        // 리스트 생성시 (헤드)노드를 하나 생성 / 자동으로 size도 1로 초기화
        this->head = new Node<T>();
        this->head->setNext(this->head);
        this->size = 1;
    }
    // 소멸시 연결된 노드 소멸자 실행 
    // 노드와 연결된 노드의 소멸자 전부 호출하여 전체 해제
    ~CircularLinkedList() {
        while (this->head != nullptr) { delete_front(); }
        cout << "!! 종료전 삭제 완료 !!" << endl;
    }

    void push_front(T data) {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* cur = this->head;

        if (this->head == nullptr) {
            this->head = newNode;
            this->head->setNext(newNode);
        }
        else {
            newNode->setNext(this->head->getNext());
            this->head->setNext(newNode);
        }

        this->size++;
        cout << "Node added Front!" << endl;
    }
    void push_end(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (this->head == nullptr) { this->head->setNext(newNode); }
        else {
            newNode->setNext(this->head->getNext());
            this->head->setNext(newNode);
        }

        this->head = newNode;
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
            newNode->setPrev(cur);
            cur->getNext()->setPrev(newNode);
            cur->setNext(newNode);
        }
        cout << "Node inserted At: " << pos << "!" << endl;
        this->size++;
    }

    void delete_front() {
        Node<T>* target = this->head;       // head 체크

        if (target == nullptr) { cout << "노드가 이미 없음!" << endl; }        // 노드가 1개도 없을 경우
        else {
            target = target->getNext();
            if (target == this->head) {     // 노드가 1개만 있을 경우
                this->head = nullptr;
                delete target;
            }
            else {
                this->head->setNext(target->getNext());
                delete target;
            }

            this->size--;
            cout << "Front node Deleted!" << endl;
        }

    }
    void delete_end() {
        Node<T>* cur = this->head;       // 대상 지정
        
        if (this->head == nullptr) { cout << "노드가 이미 없음!" << endl; }        // 노드가 1개도 없을 경우
        else {
            if (cur->getNext() == cur) {     // 노드가 1개만 있을 경우
                delete cur;
                this->head = nullptr;
            }
            else {
                while (cur->getNext() != this->head) { cur = cur->getNext(); }      // head 이전 노드로 커서 이동

                cur->setNext(this->head->getNext());
                delete this->head;
                this->head = cur;
            }

            this->size--;
            cout << "End node Deleted!" << endl;
        }

    }

    void printAll() {
        Node<T>* cur = this->head;     // 커서 설정
        int count = 1;

        // 리스트 끝으로 이동하면서 출력
        if (cur == nullptr) { cout << "!! 노드가 한개도 없음 !!" << endl; }
        else {
            cur = cur->getNext();
            cout << "!! 정방향 출력 !!" << endl;
            while (true) {
                cout << "노드 " << count << "의 data: " << cur->getData() << endl;
                count++;

                if (cur == this->head) break;
                cur = cur->getNext();
            }
        }
        cout << endl;
    }
    void printAt(int pos) {
        Node<T>* cur = this->head;     // 커서 설정
        for (int i = 0; i < pos; i++) {
            if (pos > this->size) { cout << "!! 노드 수는 총 " << this->size << "개 !!" << endl; return; }
            else { cur = cur->getNext(); }
        }
        cout << pos << "번째 노드의 data: " << cur->getData() << endl;
    }
    void printSize() { cout << "리스트의 size: " << this->size << endl; }

    // 양방향 연결리스트 전용 기능(함수)
    void printAllfromEnd() {        // 양방향 전용
        Node<T>* cur = this->tail;     // 커서 설정
        int count = this->size;

        // 리스트 끝으로 이동하면서 출력
        if (cur == nullptr) { cout << "노드 없음!" << endl; }
        else {
            cout << "!! 역방향 출력 !!" << endl;
            while (cur != nullptr) {
                cout << "노드 " << count << "의 data: " << cur->getData() << endl;
                count--;

                if (cur == this->head) break;
                cur = cur->getPrev();
            }
        }
        cout << endl;
    }
    void printTrio(int pos) {       // 지정된 위치의 노드와, 그 앞, 뒤의 노드까지 총 3개 출력  |  양방향 전용
        Node<T>* cur;
        int fromEnd = this->size - pos;
        int prev, next;

        if (pos == 1) {
            cur = this->head;
            prev = this->size;
            next = 2;
        }
        else if (pos == this->size) {
            cur = this->tail;
            next = 1;
            prev = this->size - 1;
        }
        else if (fromEnd < pos) {
            cur = this->tail;
            for (int i = 0; i < fromEnd; i++) { cur = cur->getPrev(); }

            prev = pos - 1;
            next = pos + 1;
        }
        else {
            cur = this->head;

            for (int i = 0; i < pos; i++) { cur = cur->getNext(); }

            if (pos == 1) { prev = this->size; }
            else { prev = pos - 1; }

            if (pos == this->size) { next = 0; }
            else { next = pos + 1; }
        }

        cout << "노드 " << pos << "와 그 앞뒤의 노드 Data 출력!" << endl;
        cout << "노드" << prev << "의 Data: " << cur->getPrev()->getData() << endl;
        cout << "노드" << pos << "의 Data: " << cur->getData() << endl;
        cout << "노드" << next << "의 Data: " << cur->getNext()->getData() << endl;
        cout << endl;
    }

};


int main()
{
#pragma region 원형 연결 리스트
    cout << "원형 연결 리스트 시작!" << endl;
    CircularLinkedList<int> CLL;
    CLL.printSize();
    CLL.printAll();

    CLL.delete_front();
    CLL.delete_front();
    CLL.printSize();
    CLL.printAll();

    CLL.push_front(20);
    CLL.push_end(30);
    CLL.push_end(40);
    CLL.push_front(10);
    CLL.push_end(50);
    CLL.push_end(60);
    CLL.push_end(70);
    CLL.push_end(80);
    CLL.push_end(90);
    CLL.printSize();
    CLL.printAll();
    CLL.delete_end();
    CLL.delete_front();
    CLL.delete_end();
    CLL.printSize();
    CLL.printAll();

#pragma endregion



    return 0;
}
