#include <iostream>
using namespace std;

// c#, Java의 딕셔너리가 이것과 (거의) 같음
template <typename KEY, typename VALUE>
class HashTable {
	struct Node {
	protected:
		KEY key;
		VALUE value;
		Node* next;
	public:
		Node(KEY Key = NULL, VALUE Value = NULL) {
			this->key = Key;
			this->value = Value;
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


		void addNode(KEY Key, VALUE Value) {
			Node* cur = this->head;
			bool isNew = true;

			// 기존에 등록된 [키(key):값(value)] 인지 확인
			while (cur->getNext() != nullptr) {
				if (cur->getKey() == Key)
				{
					if (cur->getValue() == Value) { isNew = false; break; }
				}
				else { cur = cur->getNext(); }
			}
			// 없으면 cursor는 노드체인의 끝을 가리키고 있음

			// 기존에 등록된 [키:값] 쌍이 아니라면 추가
			if (isNew == true) {
				Node* newNode = new Node(Key, Value);
				cur->setNext(newNode);

				newNode = nullptr;
				delete newNode;
				cout << "새 [키:값]노드 추가됨!" << endl;
				this->count++;
			}
			else { cout << "!! 이미 존재하는 키:값 쌍 !!" << endl; }
		}
		void deleteNode(KEY target) {
			Node* cur = this->head;
			Node* temp = nullptr;

			if (cur->getKey() == target) {
				temp = cur;
				this->head = cur->getNext();
				delete temp;
			}
			else {
				while (cur->getNext()->getNext() != nullptr) {
					if (cur->getNext()->getKey() == target) {
						temp = cur->getNext;
						cur->setNext(temp->getNext());
						delete temp;
						return;
					}
					cur = cur->getNext();
				}
			}

		}
		Node* getHead() { return this->head; }
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

	int HashFunction(KEY Key) {
		int res = (int)Key % this->size;
		return res;
	}
	//int HashFunction(const char* Key) {
	//	int res = Key % this->size;
	//	return res;
	//}

	void Insert(KEY Key, VALUE Value) {
		int hashKey = HashFunction(Key);
		Bucket* selected = this->buckets[hashKey];
		selected->addNode(Key, Value);
		this->count++;

		selected = nullptr;
		delete selected;
	}
	void Delete(KEY target) {
		int hashKey = HashFunction(target);
		Bucket* selected = &(this->buckets[hashKey]);
		selected->deleteNode(target);
		this->count--;

		selected = nullptr;
		delete selected;
	}

	void printAll() {
		if (this->count == 0) { cout << "테이블이 비어있음!" << endl; }
		else {
			for (int i = 0; i < this->size; i++) {
				Bucket* bucket = &(this->buckets[i]);
				Node* cur = bucket->getHead();
				if (bucket->getCount() == 0) { cout << i+1 << "번째 Bucket은 비어있음!" << endl; }
				else {
					cout << i + 1 << "번째 Bucket" << endl;

					int counter = 0;
					while (cur != nullptr) {
						cout << counter + 1 << "번째 키[" << cur->getKey() << "]:값[" << cur->getValue() << "]" << endl;

						counter++;
						cur = cur->getNext();
					}
				}				
			}
		}
		cout << endl;
	}
};


int main() {
#pragma region 해시 테이블
	HashTable<const char *,int> hashTable;
	hashTable.printAll();

	hashTable.Insert("Apple", 10);
	hashTable.Insert("Banana", 20);
	hashTable.Insert("Banana", 50);
	hashTable.Insert("Apple", 10);
	hashTable.printAll();
	
	hashTable.Insert("Candy", 30);
	hashTable.Insert("Apple", 40);
	hashTable.Insert("Candy", 60);
	hashTable.Insert("Apple", 70);
	hashTable.printAll();

#pragma endregion





	return 0;
}