#include <iostream>
#include <cmath>
using namespace std;


int calculate_level(int index) {
    return static_cast<int>(log2(index + 1));
}


void print_pyramid(int heap[], int n) {
    if (n == 0) {
        return;
    }


    cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;


    cout << "Пирамида:" << endl;
    for (int i = 0; i < n; ++i) {
        int level = calculate_level(i);
        if (i == 0) {
            cout << level << " root " << heap[i] << endl;
        } else if (i % 2 == 1) {
            cout << level << " left(" << heap[(i - 1) / 2] << ") " << heap[i] << endl;
        } else {
            cout << level << " right(" << heap[(i - 2) / 2] << ") " << heap[i] << endl;
        }
    }
}

int main() {

    int arrays[][10] = {
        {1, 3, 6, 5, 9, 8, 0, 0, 0, 0},
        {94, 67, 18, 44, 55, 12, 6, 42, 0, 0},
        {16, 11, 9, 10, 5, 6, 8, 1, 2, 4}
    };

    for (auto& array : arrays) {

        int n = sizeof(array) / sizeof(array[0]);


        print_pyramid(array, n);

        cout << endl;
    }

    return 0;
}