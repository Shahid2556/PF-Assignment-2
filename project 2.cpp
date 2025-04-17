#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to add a new player
void addPlayer() {
    string name, team, role;
    int runs, wickets;

    cin.ignore();
    cout << "Enter Player Name: ";
    getline(cin, name);
    cout << "Enter Team Name: ";
    getline(cin, team);
    cout << "Enter Role (batsman/bowler/all-rounder): ";
    getline(cin, role);
    cout << "Enter Total Runs: ";
    cin >> runs;
    cout << "Enter Total Wickets: ";
    cin >> wickets;

    ofstream file("players.txt", ios::app);
    if (file.is_open()) {
        file << name << "," << team << "," << role << "," << runs << "," << wickets << endl;
        file.close();
        cout << "Player added successfully.\n";
    }
    else {
        cout << "Unable to open file.\n";
    }
}

// Function to view all player records
void viewAllPlayers() {
    ifstream file("players.txt");
    string line, name, team, role;
    int runs, wickets;

    if (file.is_open()) {
        cout << "\nName\t\tTeam\t\tRole\t\tRuns\tWickets\n";
        cout << "-----------------------------------------------------------\n";
        while (getline(file, line)) {
            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);
            size_t p3 = line.find(',', p2 + 1);
            size_t p4 = line.find(',', p3 + 1);

            name = line.substr(0, p1);
            team = line.substr(p1 + 1, p2 - p1 - 1);
            role = line.substr(p2 + 1, p3 - p2 - 1);
            runs = stoi(line.substr(p3 + 1, p4 - p3 - 1));
            wickets = stoi(line.substr(p4 + 1));

            cout << name << "\t" << team << "\t" << role << "\t" << runs << "\t" << wickets << endl;
        }
        file.close();
    }
    else {
        cout << "Error reading file.\n";
    }
}

// Function to search by name or team
void searchPlayer() {
    string query, name, team, role, line;
    int runs, wickets;
    bool found = false;

    cin.ignore();
    cout << "Enter Player Name or Team to search: ";
    getline(cin, query);

    ifstream file("players.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);
            size_t p3 = line.find(',', p2 + 1);
            size_t p4 = line.find(',', p3 + 1);

            name = line.substr(0, p1);
            team = line.substr(p1 + 1, p2 - p1 - 1);
            role = line.substr(p2 + 1, p3 - p2 - 1);
            runs = stoi(line.substr(p3 + 1, p4 - p3 - 1));
            wickets = stoi(line.substr(p4 + 1));

            if (name == query || team == query) {
                cout << "\nName: " << name << "\nTeam: " << team << "\nRole: " << role;
                cout << "\nRuns: " << runs << "\nWickets: " << wickets << "\n";
                found = true;
            }
        }
        file.close();
    }

    if (!found) {
        cout << "No matching player found.\n";
    }
}

// Function to update player stats
void updateStats() {
    string searchName, name, team, role, line;
    int runs, wickets;
    bool updated = false;

    cin.ignore();
    cout << "Enter Player Name to update stats: ";
    getline(cin, searchName);

    ifstream inFile("players.txt");
    ofstream tempFile("temp.txt");

    while (getline(inFile, line)) {
        size_t p1 = line.find(',');
        size_t p2 = line.find(',', p1 + 1);
        size_t p3 = line.find(',', p2 + 1);
        size_t p4 = line.find(',', p3 + 1);

        name = line.substr(0, p1);
        team = line.substr(p1 + 1, p2 - p1 - 1);
        role = line.substr(p2 + 1, p3 - p2 - 1);
        runs = stoi(line.substr(p3 + 1, p4 - p3 - 1));
        wickets = stoi(line.substr(p4 + 1));

        if (name == searchName) {
            cout << "Enter new runs: ";
            cin >> runs;
            cout << "Enter new wickets: ";
            cin >> wickets;
            updated = true;
        }

        tempFile << name << "," << team << "," << role << "," << runs << "," << wickets << endl;
    }

    inFile.close();
    tempFile.close();

    remove("players.txt");
    rename("temp.txt", "players.txt");

    if (updated)
        cout << "Player stats updated successfully.\n";
    else
        cout << "Player not found.\n";
}

// Function to delete player record
void deletePlayer() {
    string searchName, name, team, role, line;
    int runs, wickets;
    bool deleted = false;

    cin.ignore();
    cout << "Enter Player Name to delete: ";
    getline(cin, searchName);

    ifstream inFile("players.txt");
    ofstream tempFile("temp.txt");

    while (getline(inFile, line)) {
        size_t p1 = line.find(',');
        size_t p2 = line.find(',', p1 + 1);
        size_t p3 = line.find(',', p2 + 1);
        size_t p4 = line.find(',', p3 + 1);

        name = line.substr(0, p1);
        team = line.substr(p1 + 1, p2 - p1 - 1);
        role = line.substr(p2 + 1, p3 - p2 - 1);
        runs = stoi(line.substr(p3 + 1, p4 - p3 - 1));
        wickets = stoi(line.substr(p4 + 1));

        if (name == searchName) {
            deleted = true;
            continue;
        }

        tempFile << name << "," << team << "," << role << "," << runs << "," << wickets << endl;
    }

    inFile.close();
    tempFile.close();

    remove("players.txt");
    rename("temp.txt", "players.txt");

    if (deleted)
        cout << "Player record deleted.\n";
    else
        cout << "Player not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- PSL Management System ---\n";
        cout << "1. Add Player Record\n";
        cout << "2. View All Players\n";
        cout << "3. Search Player by Name or Team\n";
        cout << "4. Update Player Stats\n";
        cout << "5. Delete Player Record\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addPlayer(); break;
        case 2: viewAllPlayers(); break;
        case 3: searchPlayer(); break;
        case 4: updateStats(); break;
        case 5: deletePlayer(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
