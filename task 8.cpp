#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countWordsInFile(string filename) {
    ifstream file(filename);
    string word;
    int count = 0;

    if (file.is_open()) {
        while (file >> word) {
            count++;
        }
        file.close();
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }

    return count;
}

int main() {
    string filename = "output.txt";

    int wordCount = countWordsInFile(filename);
    cout << "Number of words in " << filename << ": " << wordCount << endl;

    return 0;
}
