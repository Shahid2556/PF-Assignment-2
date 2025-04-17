#include <iostream>
using namespace std;

bool isPalindrome(char str[]) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    int start = 0;
    int end = length - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main() {
    char text[100];

    cout << "Enter a string: ";
    cin.getline(text, 100);

    if (isPalindrome(text)) {
        cout << "The string is a palindrome." << endl;
    }
    else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
