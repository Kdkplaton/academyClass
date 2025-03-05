#include <iostream>
using namespace std;

// c#, Java의 딕셔너리가 이것과 (거의) 같음
template <typename KEY, typename VALUE>
class HashTable {
	struct Node {
	private:
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
			// 할당해제는 Bucket에서 실행됨
		}

		KEY getKey() { return this->key; }
		void setKey(KEY input) { this->key = input; }
		VALUE getValue() { return this->value; }
		void setValue(VALUE input) { this->value = input; }
		Node* getNext() { return this->next; }
		void setNext(Node* newNode) { this->next = newNode; }
	};

	class Bucket {
	private:
		Node* head;
		int count;
	public:
		Bucket() {
			this->head = nullptr;
			this->count = 0;
			//cout << "Bucket 생성됨!" << endl;
		}
		~Bucket() {
			while (this->count > 0) { pop_front(); }
		}
		void pop_front() {			// 맨 앞의 노드 할당해제
			Node* temp = this->head;
			this->head = this->head->getNext();
			delete temp;
			this->count--;
		}

		int addNode(KEY Key, VALUE Value) {
			Node* cur = this->head;
			bool isNew = true;

			if (cur == nullptr) { isNew = 1; }
			else {
				// 기존에 등록된 [키(key):값(value)] 인지 확인
				while (cur->getNext() != nullptr) {			// 마지막 노드 이전노드까지 체크
					if ((cur->getKey() == Key) && (cur->getValue() == Value)) { isNew = false; break; }
					else { cur = cur->getNext(); }
				}
				if ((cur->getKey() == Key) && (cur->getValue() == Value)) { isNew = false; }			// 마지막 노드 체크
				else { isNew = true; }
				// 없으면 cursor는 노드체인의 끝 노드를 가리키고 있음
			}

			// 기존에 등록된 [키:값] 쌍이 아니라면 추가
			if (isNew == true) {
				Node* newNode = new Node(Key, Value);
				if (cur == nullptr) { this->head = newNode; }
				else { cur->setNext(newNode); }

				this->count++;
				newNode = nullptr;
				delete newNode;
				cout << "새 [키:값] 추가됨!" << endl;
				return 1;
			}
			else { cout << "!! 이미 존재하는 키:값 쌍 !!" << endl; return 0; }
		}
		int deleteNode(KEY target) {
			Node* cur = this->head;
			Node* temp = nullptr;
			int before = this->count;
			bool isExist = false;

			if (cur == nullptr) {}
			else {
				// Head 노드 다음의 노드들 전부 체크
				while (cur->getNext() != nullptr) {
					if (cur->getNext()->getKey() == target) {
						temp = cur->getNext();
						cur->setNext(temp->getNext());
						this->count--;    isExist = true;
						delete temp;    temp = nullptr;
						cout << "목표 노드 삭제됨!" << endl;
					}
					else { cur = cur->getNext(); }
				}

				// Head 노드 체크
				if (this->head->getKey() == target) {
					temp = cur;
					this->head = cur->getNext();
					this->count--;    isExist = true;
					delete temp;    temp = nullptr;
					cout << "목표 노드 삭제됨!" << endl;
				}
			}

			if (isExist == false) { cout << "존재하지 않는 KEY!!" << endl; return 0; }
			else { return (this->count - before); }
		}

		void initHead() { this->head = nullptr; }
		Node* getHead() { return this->head; }
		int getCount() { return this->count; }
	};

private:
	Bucket* buckets;
	int size, count;
public:
	HashTable(int size = 6) {
		this->buckets = new Bucket[size]();
		this->size = size;
		this->count = 0;

		/*for (int i = 0; i < size; i++) {
			Bucket* temp = &(this->buckets[i]);
			temp->initHead();
		}*/
	}
	~HashTable() {
		for (int i = 0; i < this->size; i++) { this->buckets[i].~Bucket(); }
		delete[] this->buckets;
	}

	int HashFunction(KEY Key) {
		int res = (int)Key % this->size;
		return res;
	}

	void Insert(KEY Key, VALUE Value) {
		int hashKey = HashFunction(Key);
		Bucket* selected = &(this->buckets[hashKey]);

		int diff = selected->addNode(Key, Value);
		this->count += diff;

		selected = nullptr;
		delete selected;
	}
	void Delete(KEY target) {
		int hashKey = HashFunction(target);
		Bucket* selected = &(this->buckets[hashKey]);

		int diff = selected->deleteNode(target);
		this->count += diff;

		selected = nullptr;
		delete selected;
	}

	void Count() { cout << "해시-테이블의 데이터 개수: " << this->count << endl; }
	void printAll() {
		if (this->count == 0) { cout << "테이블이 비어있음!" << endl; }
		else {
			for (int i = 0; i < this->size; i++) {
				Bucket* bucket = &(this->buckets[i]);
				Node* cur = bucket->getHead();
				if (bucket->getCount() == 0) { cout << i + 1 << "번째 Bucket : 비었음!" << endl; }
				else {
					cout << i + 1 << "번째 Bucket : ";

					int counter = 0;
					while (cur != nullptr) {
						cout << "[" << cur->getKey() << ":" << cur->getValue() << "] ";

						counter++;
						cur = cur->getNext();
					}
					cout << endl;
				}
			}
		}
		cout << endl;
	}
};

int main() {
#pragma region 해시 테이블
	HashTable<const char*, int> hashTable;
	hashTable.Count();
	hashTable.printAll();

	hashTable.Insert("Apple", 10);
	hashTable.Insert("Banana", 20);
	hashTable.Insert("Banana", 50);
	hashTable.Insert("Apple", 10);
	hashTable.Count();
	hashTable.printAll();

	hashTable.Insert("Candy", 30);
	hashTable.Insert("Apple", 40);
	hashTable.Insert("Candy", 60);
	hashTable.Insert("Apple", 70);
	hashTable.Count();
	hashTable.printAll();

	hashTable.Delete("Apple");
	hashTable.Delete("Dream");
	hashTable.Count();
	hashTable.printAll();


#pragma endregion

	return 0;
}