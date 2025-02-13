#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
#pragma region Iterator
	// 컨테이너 내에 있는 원소를 순회하기 위해 사용되는 포인터

	/*vector<int> v1;
	vector<int>::iterator iter;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);


	for (iter = v1.begin(); iter != v1.end(); iter++) {
		cout << *iter << endl;
	}*/

#pragma endregion

#pragma region set
	/*set<int> s1;

	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(50);

	if (s1.find(60) != s1.end()) {
		cout << "Found" << endl;
	}
	else {
		cout << "Not Key Found" << endl;
	}

	s1.erase(40);
	set<int>::iterator iter;

	for (iter = s1.begin(); iter != s1.end(); iter++) {
		cout << *iter << endl;
	}*/


#pragma endregion

#pragma region map
	map<string, int> m1;

	m1.insert({ "Sword",1000 });
	m1.insert({ "Armor",2000 });
	m1.insert({ "Glove",800 });
	m1.insert({ "Pike",1200 });

	if (m1.find("Armor") != m1.end()) {
		cout << "Found" << endl;
	}
	else {
		cout << "Not Key Found" << endl;
	}

	m1.erase("Sword");

	for (map<string, int>::iterator iter = m1.begin(); iter != m1.end(); iter++) {
		cout << iter->first << " / " << iter->second << endl;
	}

#pragma endregion



	return 0;
}