#include <iostream>
#include <random>
#include <time.h>

using namespace std;

void QuickSort(int list[], int start, int end) {
	if (start >= end) return;

	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {

		while (left <= end && list[pivot] >= list[left]) { left++; }
		while (right > start && list[pivot] <= list[right]) { right--; }

		if (left > right) { swap(list[pivot], list[right]); }
		else { swap(list[left], list[right]); }
	}

	QuickSort(list, start, right - 1);
	QuickSort(list, left, end);		// left >= right +1
}

int main() {
#pragma region 퀵 정렬
	// 기준점을 획득한 다음 기준점을 기준으로 배열을 나누고 한 쪽에는 기준점보다 
	// 작은 값들이 위치하게 하고 다른 한 쪽에는 기준점보다 큰 값을이 위치하게 정렬

	// 나누어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여
	// 모든 배열이 기본 배열이 될 때까지 반복하면서 정렬하는 알고리즘

	srand(time(0));

	// int datas[10] = { 4,7,3,10,6,1,9,2,8,5 };
	int datas[10];
	for (int i = 0; i < 10; i++) { datas[i] = rand() % 10 + 1; }

	cout << "Before Sort - datas: ";
	for (int i = 0; i < 10; i++) { cout << datas[i] << " "; }
	cout << endl;

	QuickSort(datas, 0, 9);

	cout << "After Sort - datas: ";
	for (int i = 0; i < 10; i++) { cout << datas[i] << " "; }
	cout << endl;

#pragma endregion


	return 0;
}