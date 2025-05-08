#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class DirectoryManager {
private:
    map<string, vector<string>> directory;

public:
    // Add a new folder if it doesn't already exist
    void addFolder(const string& folderName) {
        if (directory.find(folderName) == directory.end()) {
            directory[folderName] = vector<string>();
            cout << "Folder '" << folderName << "' created.\n";
        } else {
            cout << "Folder '" << folderName << "' already exists.\n";
        }
    }

    // Add a file to an existing folder
    void addFileToFolder(const string& folderName, const string& fileName) {
        if (directory.find(folderName) != directory.end()) {
            directory[folderName].push_back(fileName);
            cout << "File '" << fileName << "' added to folder '" << folderName << "'.\n";
        } else {
            cout << "Folder '" << folderName << "' does not exist. Please create it first.\n";
        }
    }

    // Display the full directory structure
    void displayStructure() const {
        cout << "\n--- Directory Structure ---\n";
        for (map<string, vector<string>>::const_iterator it = directory.begin(); it != directory.end(); ++it) {
            cout << "Folder: " << it->first << "\n";
            for (vector<string>::const_iterator fileIt = it->second.begin(); fileIt != it->second.end(); ++fileIt) {
                cout << "  - " << *fileIt << "\n";
            }
        }
    }
};

int main() {
    DirectoryManager dm;
    string command, folder, file;

    while (true) {
        cout << "\nCommands:\n"
             << "1. add_folder <folder_name>\n"
             << "2. add_file <folder_name> <file_name>\n"
             << "3. show\n"
             << "4. exit\n"
             << "Enter command: ";

        cin >> command;

        if (command == "add_folder") {
            cin >> folder;
            dm.addFolder(folder);
        } else if (command == "add_file") {
            cin >> folder >> file;
            dm.addFileToFolder(folder, file);
        } else if (command == "show") {
            dm.displayStructure();
        } else if (command == "exit") {
            break;
        } else {
            cout << "Invalid command. Try again.\n";
        }
    }

    return 0;
}
