#include <iostream>
#include <random>
#include <thread>
#pragma warning(disable:4244)
using namespace std;

const int PW_length = 10;

void findPW(int* from, int* finder, int idx) {
    for (int j = 0; j < 10; j++) {
        if (from[idx] == j) { finder[idx] = j; break; }
    }

    cout << "Found PW: ";
    for (int i = 0; i < PW_length; i++) {
        if (finder[i] == NULL) { cout << "X "; }
        else { cout << finder[i] << " "; }
    }
    cout << endl;
}

int main() {
#pragma region 브루트 포스(Brute Force)
    // 

    int PW[PW_length], find[PW_length];

    srand(time(0));
    for (int i = 0; i < PW_length; i++) { PW[i] = rand() % 10; find[i] = NULL; }

    cout << "Real  PW: ";
    for (int i = 0; i < PW_length; i++) { cout << PW[i] << " "; }
    cout << endl;

    for (int i = 0; i < PW_length; i++) { thread t(findPW, PW, find, i); }
    
#pragma endregion


    return 0;
}