#include <iostream>
#include <random>
using namespace std;

int main() {
#pragma region 브루트 포스(Brute Force)
    // 

    const int PW_length = 10;

    int PW[PW_length], find[PW_length];

    srand(time(0));
    for (int i = 0; i < PW_length; i++) { PW[i] = rand() % 10; find[i] = NULL; }

    cout << "Real  PW: ";
    for (int i = 0; i < PW_length; i++) { cout << PW[i] << " "; }
    cout << endl;

    cout << "Found PW: ";
    for (int i = 0; i < PW_length; i++) {
        if (find[i] == NULL) { cout << "X "; }
        else { cout << find[i] << " "; }
    }
    cout << endl;

#pragma endregion


    return 0;
}