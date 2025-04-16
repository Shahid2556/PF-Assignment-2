#include <iostream>
#include <fstream>
using namespace std;

void saveToFile(string text) {
    ofstream file("output.txt");
    if (file.is_open()) {
        file << text;
        file.close();
        cout << "Text saved to output.txt successfully." << endl;
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }
}

int main() {
    string userInput;

    cout << "Enter text to save in file: ";
    getline(cin, userInput);

    saveToFile(userInput);

    return 0;
}
