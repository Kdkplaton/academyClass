#include <iostream>
#include <random>
#include <time.h>

using namespace std;

void merge_sort(int list[], int start, int end) {
	int len = (end - start) + 1;
	int mid = (end + start) / 2;

	if (len > 1) {
		merge_sort(list, start, mid);
		merge_sort(list , mid+1, end);

		int* temp = new int[len];
		for (int i = 0; i < len; i++) { temp[i] = NULL; }
		
		int p1 = start, p2 = mid+1;
		cout << "p1: " << p1 << " p2: " << p2 << " ";
		
		for (int i = 0; i < len; i++) {
			if (list[p1] <= list[p2]) { 
				if (p1 <= mid) { temp[i] = list[p1++]; }
			}
			else {
				if (p2 <= end) { temp[i] = list[p2++]; }
			}
		}

		cout << "temp: ";
		for (int i = 0; i < len; i++) { cout << temp[i] << " "; }
		cout << endl;

		for (int i = 0; i < len; i++) { list[start+i] = temp[i]; }

		delete[] temp;
	}
	else {
		if (len > 0) {
			if (list[start] > list[end]) { swap(list[start], list[end]); }
		}
		else { return; }
	}

	cout << "start: " << start << " end: " << end << " ";
	cout << "부분배열: ";
	for (int i = start; i <= end; i++) { cout << list[i] << " "; }
	cout << endl;
}

int main() {
#pragma region 병합 정렬 (Merge Sort)
	// 하나의 리스트를 두 개의 균일한 크기로 분할하고 분할된 부분 리스트를 정렬한 다음,
	// 두 개의 정렬된 부분 리스트를 합하여 전체가 정렬된 리스트가 되게 하는 방법

	// 1.   리스트의 길이가 0 또는 1이면 이미 정렬된 것으로 간주 함

	// 2.   그렇지 않은경우
	// 2-1. 정렬되지 않은 리스트를 절반으로 잘라 비슷한 크기의 두 부분 리스트로 나눔
	// 2-2. 각 부분 리스트를 재귀적으로 병합 정렬을 이용하여 정렬
	// 2-3. 두 부분 리스트를? 다시 하나의 정렬된 리스트로 병합

	srand(time(0));

	int datas[10];
	for (int i = 0; i < 10; i++) { datas[i] = rand() % 100 + 1; }

	cout << "Before Sort: ";
	for (int i = 0; i < 10; i++) { cout << datas[i] << " "; }
	cout << endl;

	merge_sort(datas, 0, 9);

	cout << "After  Sort: ";
	for (int i = 0; i < 10; i++) { cout << datas[i] << " "; }
	cout << endl;

#pragma endregion

	
	return 0;
}