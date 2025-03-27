#include <iostream>

using namespace std;

int Greedy(int input) {
	int res = 0;

	res += input / 50000;
	input %= 50000;

	res += input / 10000;
	input %= 10000;

	res += input / 5000;
	input %= 5000;

	res += input / 1000;
	input %= 1000;

	res += input / 500;
	input %= 500;

	res += input / 100;
	input %= 100;

	res += input / 50;
	input %= 50;

	res += input / 10;
	input %= 10;

	return res;
}

int main() {
#pragma region 탐욕법 (Greed Algorithm)
	// 최적의 해를 구하는 데에 사용되는 근사적인 방법으로 여러 경우 중
	// 하나를 검색해야 할 때마다 그 순간에 최적이라고 생각되는 것을 
	// 선택해 나가는 방식으로 진행하여 최종적인 해답을 구하는 알고리즘

	// 1. 탐욕 선택 속성
	// 각 단계에서 '최적의 선택'을 했을 때 전체 문제에 대한 최적의 해를 구할 수 있는 경우

	// 2. 최적 부분 구조
	// 전체 문제의 최적의 해가 '부분 문제의 최적의 해로 구성'될 수 있는 경우

	// 그리디 알고리즘 단계
	// 1. 문제의 최적 부분 구조 결정
	// 2. 문제의 구조에 맞게 선택 절차 정의
	// 3. 선택 절차에 따라 선택을 수행
	// 4. 선택된 해가 문제의 조건을 만족 여부 검사
	// 5. 조건을 만족하지 않으면 해당 해 제외
	// 6. 모든 선택이 완료되면 해답 검사
	// 7. 조건을 만족하지 않으면 해답 미인정

	// 탐욕 알고리즘으로 문제를 해결하는 방법
	// 1. 선택 절차 (Selection Procedure) : 현재 상태에서의 최적의 해답 선택
	// 2. 적절성 검사 (Feasibility Check) : 선택된 해가 문제의 조건을 만족하는지 검사
	// 3. 해답 검사 (Solution Check) : 원래의 문제 해결여부 검사, 해결되지 않았다면 선택 절차로 돌아가 반복


	int input;
	cout << "돈: ";
	cin >> input;

	cout << "지폐+동전의 수: " << Greedy(input) << endl;

#pragma endregion

	return 0;
}