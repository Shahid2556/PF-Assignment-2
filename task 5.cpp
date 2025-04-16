#include <iostream>
using namespace std;

void printCharacters(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        cout << str[i] << endl;
    }
}

int main() {
    char text[100];

    cout << "Enter a string: ";
    cin.getline(text, 100);

    cout << "Characters in the string:\n";
    printCharacters(text);

    return 0;
}
