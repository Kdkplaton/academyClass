#include <iostream>
using namespace std;

// c#, Java의 딕셔너리가 이것과 (거의) 같음
template <typename KEY, typename VALUE>
class HashTable {
	struct Node {
	protected:
		KEY key;
		VALUE value;
		Bucket* next;
	public:
		Node(KEY key = NULL, VALUE value = NULL) {
			this->key = key;
			this->value = value;
			this->next = nullptr;
		}
		~Node() {

		}

		KEY getKey() { return this->key; }
		void setKey(KEY input) { this->key = input; }
		VALUE getValue() { return this->value; }
		void setValue(VALUE input) { this->value = input; }
		Node* getNext() { return this->next; }
		void setNext(Node* newNode) { this->next = newNode; }
	};

	class Bucket {
		Node* head;
		int count;
	public:
		Bucket() {
			this->head = nullptr;
			this->count = 0;
		}
		~Bucket() {
			while (this->count > 0) { pop_front(); }
		}

		void pop_front() {
			Node* temp = this->head;
			this->head = this->head->getNext();
			delete temp;
			this->count--;
		}


		void addNode(Node* newNode) {
			Node* cur = this->head;
			while (cur->getNext() != nullptr) { cur = cur->getNext(); }

			cur->getNext(newNode);
		}
		int getCount() { return this->count; }
	};

private:
	Bucket* buckets;
	int size, count;
public:
	HashTable(int size = 6) {
		this->buckets = new Bucket[size];
		this->size = size;
		this->count = 0;
	}
	~HashTable() {
		// delete key, value;
	}

	template <typename T>
	int HashFunction(T key) {
		int res, min = 0;

		for (int i = 0; i < this->size; i++) {
			if(min > this->buckets[i]->count)
		}


		return res;
	}


	void Update(KEY k_Input, VALUE v_Input) {
		int isNew = true;
		Bucket* cursor = this->head;

		// 기존에 등록된 키(key) 인지 확인
		while (cursor->getNext() != nullptr) {
			if (cursor->getKey() == k_Input)
			{
				cursor->setValue(v_Input); isNew = false; break;
			}
			else { cursor = cursor->getNext(); }
		}
		// 미 감지 시점에서 cursor는 노드체인의 끝을 가리키고 있음
		
		// 기존에 등록된 키가 아니라면 추가
		if (isNew == true) {
			// 용량(size) 최대치 도달시 추가 실패
			if (this->count == this->size) {
				cout << "!! 테이블 용량 한계 !!" << endl;
				return;
			}
			// 용량이 남았을 경우 추가
			else {
				Bucket* newNode = new Bucket(k_Input, v_Input);
				cursor->next = newNode;
				
				newNode = nullptr;    delete newNode;
			}

		}
	}

	void printAll() {
		if (this->count == 0) { cout << "테이블이 비어있음!" << endl; }
		else {
			for (int i = 0; i < this->size; i++) {
				Bucket* cur = this->buckets[i];
				cout << i + 1 << "번째 Bucket" << endl;

				int counter = 0;
				while (cur != nullptr) {
					cout << counter + 1 << "번째 키[" << cur->getKey() << "]:값[" << cur->getValue() << "]" << endl;

					counter++;
					cur = cur->getNext();
				}
			}
		}
		cout << endl;
	}
};


int main() {
#pragma region 해시 테이블
	HashTable<string,int> hashTable;
	hashTable.printAll();

	hashTable.Update("Apple", 10);
	hashTable.Update("Banana", 20);
	hashTable.printAll();
	
	hashTable.Update("Candy", 30);
	hashTable.Update("Apple", 40);
	hashTable.printAll();

#pragma endregion





	return 0;
}