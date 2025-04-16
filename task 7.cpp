#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char str[]) {
    int length = strlen(str);
    for (int i = length - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;
}

int main() {
    char text[100];

    cout << "Enter a string: ";
    cin.getline(text, 100);

    cout << "Reversed string: ";
    reverseString(text);

    return 0;
}
