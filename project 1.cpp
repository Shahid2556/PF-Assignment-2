#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to add student record
void addStudent() {
    string name, rollNo, dept;
    float gpa;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Roll Number: ";
    getline(cin, rollNo);
    cout << "Enter Department: ";
    getline(cin, dept);
    cout << "Enter GPA: ";
    cin >> gpa;

    ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << name << "," << rollNo << "," << dept << "," << gpa << endl;
        file.close();
        cout << "Student record added successfully.\n";
    }
    else {
        cout << "Error opening file.\n";
    }
}

// Function to view all student records
void viewAllStudents() {
    ifstream file("students.txt");
    string name, rollNo, dept, line;
    float gpa;

    if (file.is_open()) {
        cout << "\nName\t\tRoll No\t\tDepartment\tGPA\n";
        cout << "-----------------------------------------------\n";

        while (getline(file, line)) {
            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);
            size_t p3 = line.find(',', p2 + 1);

            name = line.substr(0, p1);
            rollNo = line.substr(p1 + 1, p2 - p1 - 1);
            dept = line.substr(p2 + 1, p3 - p2 - 1);
            gpa = stof(line.substr(p3 + 1));

            cout << name << "\t" << rollNo << "\t" << dept << "\t" << gpa << endl;
        }
        file.close();
    }
    else {
        cout << "Error reading file.\n";
    }
}

// Function to search student by roll number
void searchStudent() {
    string searchRoll, name, rollNo, dept, line;
    float gpa;
    bool found = false;

    cin.ignore();
    cout << "Enter Roll Number to search: ";
    getline(cin, searchRoll);

    ifstream file("students.txt");
    while (getline(file, line)) {
        size_t p1 = line.find(',');
        size_t p2 = line.find(',', p1 + 1);
        size_t p3 = line.find(',', p2 + 1);

        name = line.substr(0, p1);
        rollNo = line.substr(p1 + 1, p2 - p1 - 1);
        dept = line.substr(p2 + 1, p3 - p2 - 1);
        gpa = stof(line.substr(p3 + 1));

        if (rollNo == searchRoll) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << name << "\nRoll No: " << rollNo
                << "\nDepartment: " << dept << "\nGPA: " << gpa << endl;
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Student not found.\n";
    }
}

// Function to update GPA of student
void updateGPA() {
    string searchRoll, name, rollNo, dept, line;
    float gpa;
    bool updated = false;

    cin.ignore();
    cout << "Enter Roll Number to update GPA: ";
    getline(cin, searchRoll);

    ifstream inFile("students.txt");
    ofstream tempFile("temp.txt");

    while (getline(inFile, line)) {
        size_t p1 = line.find(',');
        size_t p2 = line.find(',', p1 + 1);
        size_t p3 = line.find(',', p2 + 1);

        name = line.substr(0, p1);
        rollNo = line.substr(p1 + 1, p2 - p1 - 1);
        dept = line.substr(p2 + 1, p3 - p2 - 1);
        gpa = stof(line.substr(p3 + 1));

        if (rollNo == searchRoll) {
            cout << "Enter new GPA: ";
            cin >> gpa;
            updated = true;
        }

        tempFile << name << "," << rollNo << "," << dept << "," << gpa << endl;
    }

    inFile.close();
    tempFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (updated)
        cout << "GPA updated successfully.\n";
    else
        cout << "Student not found.\n";
}

// Function to delete a student record
void deleteStudent() {
    string searchRoll, name, rollNo, dept, line;
    float gpa;
    bool deleted = false;

    cin.ignore();
    cout << "Enter Roll Number to delete: ";
    getline(cin, searchRoll);

    ifstream inFile("students.txt");
    ofstream tempFile("temp.txt");

    while (getline(inFile, line)) {
        size_t p1 = line.find(',');
        size_t p2 = line.find(',', p1 + 1);
        size_t p3 = line.find(',', p2 + 1);

        name = line.substr(0, p1);
        rollNo = line.substr(p1 + 1, p2 - p1 - 1);
        dept = line.substr(p2 + 1, p3 - p2 - 1);
        gpa = stof(line.substr(p3 + 1));

        if (rollNo == searchRoll) {
            deleted = true;
            continue;
        }

        tempFile << name << "," << rollNo << "," << dept << "," << gpa << endl;
    }

    inFile.close();
    tempFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (deleted)
        cout << "Student record deleted successfully.\n";
    else
        cout << "Student not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student Record\n";
        cout << "2. View All Student Records\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Update Student GPA\n";
        cout << "5. Delete Student Record\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: viewAllStudents(); break;
        case 3: searchStudent(); break;
        case 4: updateGPA(); break;
        case 5: deleteStudent(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
