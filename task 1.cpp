#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": " << arr[i] << endl;
    }
}

int main() {
    int numbers[5];

    cout << "Enter 5 integers:\n";
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    cout << "The array elements are:\n";
    printArray(numbers, 5);

    return 0;
}
