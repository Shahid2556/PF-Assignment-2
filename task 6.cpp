#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int numbers[5];

    cout << "Enter 5 integers:\n";
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    int maximum = findMax(numbers, 5);
    cout << "Maximum value: " << maximum << endl;

    return 0;
}
