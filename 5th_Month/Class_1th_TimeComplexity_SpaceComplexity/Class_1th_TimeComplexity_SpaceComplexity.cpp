#include <iostream>

using namespace std;

int main()
{
#pragma region 시간 복잡도
    // 컴퓨터 프로그램의 입력값과 연산 수행 시간의 상관 관계를 나타내는 척도

    // O(1)     : 입력 값의 수가 늘어도 쇼요시간은 변하지 않음
    // O(log n) : 입력 값의 수가 많을수록 소요시간의 증가는 감소함
    // O(n)     : 입력 값의 수 만큼 소요시간이 증가함
    // O(n^2)   : 입력 값의 수의 제곱만큼 소요시간이 증가함
    // O(n!)    : 입력 값의 수가 증가할수록 소요시간이 기하급수적으로 증가함

#pragma region O(1) 상수 시간
    // 입력 크기와 상관 없이 일정한 시간 복잡도를 가지는 시간

    // ex) 배열의 요소 접근
#pragma endregion
#pragma region O(log n) 로그 시간
    // 데이터의 크기에 따라 실행 시간이 로그 함수의 형태로 증가하는 시간 복잡도

    // ex) 이진 탐색
#pragma endregion
#pragma region O(n) 선형 시간
    // 입력에 따라 걸리는 시간이 선형적으로 증가되는 시간 복잡도

    // ex) 순차 탐색
#pragma endregion
#pragma region O(n²) 제곱 시간
    // 입력되는 데이터를 기준으로 n²만큼의 시간이 증가하는 사간 복잡도

    // ex) 2 for statement
#pragma endregion
#pragma region O(n!) 팩토리얼 시간
// 

// ex) 
#pragma endregion

#pragma endregion

#pragma region 공간 복잡도
    // 프로그램 실행과 완료에 얼마나 많은 공간이 필요한 지 나타내는 척도

#pragma region 고정 공간
    // 코드가 저장되는 공간으로 알고리즘 실행을 위해 시스템이 필요로 하는 공간
    // 배열
#pragma endregion
#pragma region 가변 공간
    // 문제를 해결하기 위해 알고리즘이 필요한 공간으로 순환 프로그램일 경우 순환 스택을 의미함
    // 
#pragma endregion 
    // 

#pragma endregion

#pragma region 점근적 표기법
    // 상수 계수와 중요하지 않은 항목 제거하여 표기하는 표기법

    // 점근적 표기법 -> n²

    // 높은 수가 낮은 차수에 붙어있어도 n이 무한대로 갈 수 있기 때문에 제일 높은 차수가 됨

#pragma endregion


    return 0;
}
