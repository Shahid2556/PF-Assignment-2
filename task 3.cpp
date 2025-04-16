#include <iostream>
#include <cstring>
using namespace std;

int countVowels(char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    char text[100];

    cout << "Enter a string: ";
    cin.getline(text, 100);

    int vowels = countVowels(text);
    cout << "Number of vowels: " << vowels << endl;

    return 0;
}
