#include <iostream>
using namespace std;

void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int source[5], destination[5];

    cout << "Enter 5 integers for the source array:\n";
    for (int i = 0; i < 5; i++) {
        cin >> source[i];
    }

    copyArray(source, destination, 5);

    cout << "Contents of the destination array:\n";
    for (int i = 0; i < 5; i++) {
        cout << destination[i] << " ";
    }
    cout << endl;

    return 0;
}
