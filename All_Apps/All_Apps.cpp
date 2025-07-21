#include <bits/stdc++.h>
using namespace std;

// Define a struct to represent a Task
struct Task {
    string description;
    bool isComplete;

    Task(string desc) : description(desc), isComplete(false) {}
};

// Function to display the menu
void displayMenu() {
    cout << "\nTo-Do List Menu:" << endl;
    cout << "0. Return to the main menu" << endl;
    cout << "1. Add a Task" << endl;
    cout << "2. View All Tasks" << endl;
    cout << "3. Mark Task as Complete" << endl;
    cout << "4. Remove a Task" << endl;
    cout << "5. Undo" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    cout << "Enter the task description: ";
    string description;
    cin.ignore();  // Ignore newline character left in input buffer
    getline(cin, description);
    tasks.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "\nTo-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].isComplete) {
            cout << " [Complete]";
        }
        cout << endl;
    }
}

// Function to mark a task as complete
void markTaskComplete(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "Enter the task number to mark as complete: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isComplete = true;
        cout << "Task marked as complete!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks, stack<Task>& removedTasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "Enter the task number to remove: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        removedTasks.push(tasks[taskNumber - 1]);
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to undo the last removal
void undo(vector<Task>& tasks, stack<Task>& removedTasks) {
    if (removedTasks.empty()) {
        cout << "No tasks to undo." << endl;
        return;
    }
    tasks.push_back(removedTasks.top());
    removedTasks.pop();
    cout << "Task restored successfully!" << endl;
}

// Function to save tasks to a file
void saveToFile(const vector<Task>& tasks) {
    ofstream file("Doc1.csv");
    if (!file.is_open()) {
        cout << "Unable to open file for writing." << endl;
        return;
    }
    for (const auto& task : tasks) {
        file << task.description << "," << task.isComplete << endl;
    }
    file.close();
    cout << "Tasks saved to file." << endl;
}

// Function to load tasks from a file
void loadFromFile(vector<Task>& tasks) {
    ifstream file("Doc1.csv");
    if (!file.is_open()) {
        cout << "No saved tasks found." << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            string description = line.substr(0, commaPos);
            bool isComplete = (line.substr(commaPos + 1) == "1");
            tasks.push_back(Task(description));
            tasks.back().isComplete = isComplete;
        }
    }
    file.close();
}

void openFileLocation(const string &filePath)
{
    string command = "explorer /select," + filePath;
    system(command.c_str());
}

void main1() {
    system("cls");
    vector<Task> tasks;
    stack<Task> removedTasks;

    // Load tasks from file at the start
    loadFromFile(tasks);

    int choice;
    
    
    while (true) {
        displayMenu();
        if (!(cin >> choice)) {
            cout << "Invalid choice. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            markTaskComplete(tasks);
            break;
        case 4:
            removeTask(tasks, removedTasks);
            break;
        case 5:
            undo(tasks, removedTasks);
            break;
        case 6:
            saveToFile(tasks);
            cout << "Exiting the program. Goodbye!" << endl;
            return ;

        case 0:
            return ;
        case 28:
        {
            string filePath = "Enter your file path"; // Replace with your file's path
            openFileLocation(filePath);
            system("cls");
            break;
        }
        default:
            cout << "Invalid choice. Please choose a valid option." << endl;
            break;
        }
    }
    return;
    
}



    // Define a constant for phone number length
    const int PHONE_NUMBER_LENGTH = 10;

    struct Contact {
        string name;
        string phoneNumber;
    };

    class Solution {
    public:
        // Function to remove duplicate contacts
        vector<Contact> removeDuplicates(vector<Contact>& contacts) {
            vector<Contact> uniqueContacts;
            if (!contacts.empty()) {
                uniqueContacts.push_back(contacts[0]);
                for (int i = 1; i < contacts.size(); i++) {
                    bool duplicate = false;
                    for (int k = 0; k < uniqueContacts.size(); k++) {
                        if (contacts[i].phoneNumber == uniqueContacts[k].phoneNumber) {
                            duplicate = true;
                            break;
                        }
                    }
                    if (!duplicate) {
                        uniqueContacts.push_back(contacts[i]);
                    }
                }
            }
            return uniqueContacts;  
        }

         // Function to modify a contact
    void modifyContact(vector<Contact>& contacts) {
        string phoneNumber;
        cout << "Enter phone number to modify: ";
        cin >> phoneNumber;

        for (auto& contact : contacts) {
            if (contact.phoneNumber == phoneNumber) {
                cout << "Enter new name: ";
                cin.ignore(); // ignore newline character left in input buffer
                getline(cin, contact.name);
                cout << "Enter new phone number: ";
                cin >> contact.phoneNumber;
                cout << "Contact modified successfully." << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }





        void searchContact(const vector<Contact>& contacts, const string& query) {
    bool found = false;
    for (const Contact& contact : contacts) {
        if (contact.name == query || contact.phoneNumber == query) {
            cout << "Contact found: " << contact.name << " - " << contact.phoneNumber << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Contact not found." << endl;
    }
}




void searchContacts(const vector<Contact>& contacts) {
    string query;
    cout << "Enter phone number to search: ";
    getline(cin, query);

    if (query.empty()) {
        cout << "Please enter a valid phone number." << endl;
        return;
    }

    bool found = false;
    for (const Contact& contact : contacts) {
        if (contact.phoneNumber.find(query) != string::npos) {
            cout << "Contact found: " << contact.name << " - " << contact.phoneNumber << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Contact not found." << endl;
    }
}
    };

    // Function to save contacts to a file
    void saveToFile(const vector<Contact>& contacts) {
        ofstream file("Doc2.csv");
        if (!file.is_open()) {
            throw runtime_error("Unable to open file for writing.");
        }
        for (const auto& contact : contacts) {
            file << contact.name << "," << contact.phoneNumber << endl;
        }
        file.close();
    }

    // Function to load contacts from a file
    void loadFromFile(vector<Contact>& contacts) {
        ifstream file("Doc2.csv");
        if (!file.is_open()) {
            return;
        }
        string line;
        while (getline(file, line)) {
            size_t commaPos = line.find(',');
            if (commaPos != string::npos) {
                string name = line.substr(0, commaPos);
                string phoneNumber = line.substr(commaPos + 1);
                Contact contact = {name, phoneNumber};
                contacts.push_back(contact);
            }
        }
        file.close();
    }

    // Function to display file contents
    void displayFileContents() {
        ifstream file("Doc2.csv");
        if (!file.is_open()) {
            cout << "File not found or unable to open." << endl;
            return;
        }
        string line;
        bool isEmpty = true;
        while (getline(file, line)) {
            cout << line << endl;
            isEmpty = false;
        }
        if (isEmpty) {
            cout << "File is empty." << endl;
        }
        file.close();
    }

    void main2() {
        system("cls");
        vector<Contact> contacts;
        loadFromFile(contacts);
        string phoneNumber;
        string name;
        int choice;
        Solution solution;

        // Collect contacts
        while (true) {
            cout << "0. Return to the main menu" << endl;
            cout << "1. Add number" << endl;
            cout << "2. View numbers" << endl;
            cout << "3. Merge the contacts" << endl;
            cout << "4. Remove a Number" << endl;
            cout << "5. Search a number" << endl;
            cout << "6. Modify a number" << endl;
            cout << "7. Save and Exit" << endl;
            cout << "8. Exit without saving" << endl;
            cout << "Enter your choice: ";
            
            if (!(cin >> choice)) {
            cout << "Invalid choice. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
            }
            switch (choice) {
            case 1:
                cout << "Enter 10-digit phone numbers and names " << endl;
                cout << "Enter phone number: ";
                cin >> phoneNumber;
                

                if (phoneNumber.length() == PHONE_NUMBER_LENGTH && all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit)) {
                    cout << "Enter name: ";
                    cin.ignore(); // ignore newline character left in input buffer
                    getline(cin, name);
                    Contact contact = {name, phoneNumber};
                    contacts.push_back(contact);
                } else {
                    cout << "Invalid input. Please enter a 10-digit number." << endl;
                }
                cout << endl;
                break;

            case 2:
                if (contacts.empty()) {
                    cout << "No contacts available." << endl;
                } else {
                    for (const Contact &contact : contacts) {
                        cout << contact.name << ": " << contact.phoneNumber << endl;
                    }
                }
                cout << endl;
                break;
                
            case 3:
                // Remove duplicates
                contacts = solution.removeDuplicates(contacts);
                cout << "Unique contacts:" << endl;
                for (const Contact &contact : contacts) {
                    cout << contact.name << ": " << contact.phoneNumber << endl;
                }
                cout << endl;
                break;

            case 7:
                // Save and exit
                saveToFile(contacts);
                cout << "Contacts saved to file." << endl;
                cout << "Exiting..." << endl;
                cout << endl;
                return ;

            case 4:
                // Remove a number
                cout << "Enter phone number to remove: ";
                cin >> phoneNumber;
                for (auto it = contacts.begin(); it != contacts.end(); ++it) {
                    if (it->phoneNumber == phoneNumber) {
                        contacts.erase(it);
                        cout << "Number removed successfully." << endl;
                        cout << endl;
                        break;
                    }
                }
                break;

            case 5:
                // Search a number
                cout << "Enter name or number to search: ";
                cin.ignore(); // ignore newline character left in input buffer
                if(getline(cin, name)){
                solution.searchContact(contacts,name);
                cout << endl;
                break;
                }else{
                    solution.searchContacts(contacts);
                    cout<<endl;
                    break;
                }

            case 8:
                // Exit without saving
                cout << "Exiting without saving..." << endl;
                cout << endl;
                return ;

            case 6:
                // Modify a contact
                solution.modifyContact(contacts);
                cout << endl;
                break;
            case 0:
                // Modify a contact
                
                return;
            case 28:
            {
                string filePath = "Enter your file path"; // Replace with your file's path
                openFileLocation(filePath);
                system("cls");
                break;
            }
            default:
                cout << "Invalid input!" << endl;
            }
        }
        system("pause");
        return ;
    }

using namespace std;

class PasswordManager {
private:
    map<string, string> passwords;
    string masterPasswordHash;

    // Simple hash function, you can replace it with a more secure one like SHA-256
    string hashPassword(string password) {
        hash<string> hasher;
        return to_string(hasher(password));
    }

    // Store the master password hash in a file
    void storeMasterPasswordHash() {
        ofstream file("master_password_hash.txt");
        if (file.is_open()) {
            file << masterPasswordHash;
            file.close();
        } else {
            cout << "Unable to open file to store master password hash." << endl;
        }
    }

    // Load the master password hash from a file
    void loadMasterPasswordHash() {
        ifstream file("master_password_hash.txt");
        if (file.is_open()) {
            getline(file, masterPasswordHash);
            file.close();
        }
    }


public:
    // Constructor to load the master password hash when the program starts
    PasswordManager() {
        loadMasterPasswordHash();
    }

    bool isMasterPasswordSet() {
        return !masterPasswordHash.empty();  // If the hash is not empty, password is set
    }

    // Set the master password if not already set
    void setMasterPassword(string password) {
        if (!isMasterPasswordSet()) {
            masterPasswordHash = hashPassword(password);
            storeMasterPasswordHash(); // Store the hash in the file
            cout << "Master password set successfully!" << endl;
        } else {
            cout << "Master password is already set and cannot be changed!" << endl;
        }
    }

    // Verify if the entered master password is correct
    bool verifyMasterPassword(string password) {
        return hashPassword(password) == masterPasswordHash;
    }
    // Add a password for a username
    void addPassword(string username, string password) {
        passwords[username] = password;
    }

    // Display all stored passwords
    void displayPasswords() {
        cout << "Stored Passwords:" << endl;
        for (auto& pair : passwords) {
            cout << "Username: " << pair.first << ", Password: " << pair.second << endl;
        }
    }

    // Store passwords to a file
    void storePasswordsToFile() {
        ofstream file("Doc3.csv");
        if (file.is_open()) {
            for (auto& pair : passwords) {
                file << pair.first << ":" << pair.second << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    }

    // Load passwords from a file
    void loadPasswordsFromFile() {
        ifstream file("Doc3.csv");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t colonPos = line.find(":");
                if (colonPos != string::npos) {
                    string username = line.substr(0, colonPos);
                    string password = line.substr(colonPos + 1);
                    addPassword(username, password);
                }
            }
            file.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    }

    // Search for a password by username
    void searchPassword(string username) {
        if (passwords.count(username)) {
            cout << "Username: " << username << ", Password: " << passwords[username] << endl;
        } else {
            cout << "Username not found." << endl;
        }
    }

    // Update a password for a username
    void updatePassword(string username, string newPassword) {
        if (passwords.count(username)) {
            passwords[username] = newPassword;
            cout << "Password updated successfully." << endl;
        } else {
            cout << "Username not found." << endl;
        }
    }

    // Display all passwords after verifying the master password
    void displayAllPasswords(string password) {
        if (verifyMasterPassword(password)) {
            displayPasswords();
        } else {
            cout << "Invalid master password. Access denied." << endl;
        }
    }
};

// Function to hide input when entering a password
string enterPassword() {
    string password;
    char ch;
    cout << "Enter password: ";
    while ((ch = _getch()) != 13) { // 13 is ASCII value of Enter
        if(ch == 8){
            password.pop_back();
            cout << "\b \b";
        }else{
        password.push_back(ch);
        cout << '*'; // Mask the input with *
    }
    }
    cout << endl;
    return password;
}

// Function to display the menu
void displayMenu1() {
    cout << "Password Manager Menu:" << endl;
    cout << "0. return to the main menu" << endl;
    cout << "1. Generate a new password" << endl;
    cout << "2. Search for a password" << endl;
    cout << "3. Update a password" << endl;
    cout << "4. Display all passwords" << endl;
    cout << "5. Change master password" << endl;  // New option to change master password
    cout << "6. Exit" << endl;
    cout << "7. Exit without saving" << endl;
    cout << "Enter your choice: ";
}
string generatePassword(int length, bool useNumbers, bool useSpecialChars) {
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (useNumbers) {
        chars += "0123456789";
    }
    if (useSpecialChars) {
        chars += "!@#$%^&*()_+-={}:<>?,";
    }

    string password = "";
    srand(time(0)); // seed random number generator
    for (int i = 0; i < length; i++) {
        password += chars[rand() % chars.length()];
    }
    return password;
}

// Function to change the master password
void changeMasterPassword(PasswordManager& passwordManager) {
    if (!passwordManager.isMasterPasswordSet()) {
        cout << "No master password is set. Please set a master password first." << endl;
        return;
    }

    cout << "Enter current master password to change it: ";
    string currentPassword = enterPassword();

    // Verify the current master password
    if (passwordManager.verifyMasterPassword(currentPassword)) {
        cout << "Enter a new master password: ";
        string newPassword = enterPassword();
        passwordManager.setMasterPassword(newPassword);  // Update the master password
        cout << "Master password changed successfully!" << endl;
    } else {
        cout << "Incorrect master password. Cannot change the password." << endl;
    }
}

void main3() {
    system("cls");
    PasswordManager passwordManager;

    // Check if the master password is already set
    if (passwordManager.isMasterPasswordSet()) {
        cout << "Master password is already set." << endl;
    } else {
        cout << "Set a master password for the password manager (this can only be done once): ";
        string masterPassword = enterPassword();
        passwordManager.setMasterPassword(masterPassword);
    }

    system("cls");
    passwordManager.loadPasswordsFromFile();

    int choice;
    while (true) {
        displayMenu1();
        if (!(cin >> choice)) {
            cout << "Invalid choice. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
            case 1: {
                int length;
                bool useNumbers, useSpecialChars;

                cout << "Enter the length of the password: ";
                cin >> length;

                cout << "Do you want to include numbers in the password? (y/n): ";
                char numChoice;
                cin >> numChoice;
                useNumbers = (numChoice == 'y');

                cout << "Do you want to include special characters in the password? (y/n): ";
                char specialChoice;
                cin >> specialChoice;
                useSpecialChars = (specialChoice == 'y');

                string username;
                cout << "Enter a username: ";
                cin.ignore();
                getline(cin, username);

                string password = generatePassword(length, useNumbers, useSpecialChars);
                cout << "Generated password: " << password << endl << endl;
                passwordManager.addPassword(username, password);

                break;
            }
            case 2: {
                string username;
                cout << "Enter a username to search: ";
                cin >> username;
                passwordManager.searchPassword(username);
                system("pause");
                system("cls");

                break;
            }
            case 3: {
                string username, newPassword;
                cout << "Enter a username to update: ";
                cin >> username;
                cout << "Enter a new password: ";
                cin >> newPassword;
                passwordManager.updatePassword(username, newPassword);
                break;
            }
            case 4: {
                string password;
                cout << "Enter master password to display all passwords: ";
                password = enterPassword();
                passwordManager.displayAllPasswords(password);
                break;
            }
            case 5: {
                changeMasterPassword(passwordManager);  // Call the new function
                break;
            }
            case 6: {
                passwordManager.storePasswordsToFile();
                return ;
            }
            case 7: {
                cout << "Exiting without saving..." << endl;
                return ;
            }
            case 0: {
                
                return ;
            }
            case 28:
            {
                string filePath = "Enter your file path"; // Replace with your file's path
                openFileLocation(filePath);
                system("cls");
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return ;
}

class UsernameManager {
private:
    map<string, string> usernames;

public:
    // Add a username for an identifier (like email or ID)
    void addUsername(string identifier, string username) {
        usernames[identifier] = username;
    }

    // Display all stored usernames
    void displayUsernames() {
        cout << "Stored Usernames:" << endl;
        for (auto& pair : usernames) {
            cout << "Identifier: " << pair.first << ", Username: " << pair.second << endl;
        }
    }

    // Store usernames to a file
    void storeUsernamesToFile() {
        ofstream file("Doc4.csv");
        if (file.is_open()) {
            for (auto& pair : usernames) {
                file << pair.first << ":" << pair.second << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    }

    // Load usernames from a file
    void loadUsernamesFromFile() {
        ifstream file("Doc4.csv");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t colonPos = line.find(":");
                if (colonPos != string::npos) {
                    string identifier = line.substr(0, colonPos);
                    string username = line.substr(colonPos + 1);
                    addUsername(identifier, username);
                }
            }
            file.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    }

    // Search for a username by identifier
    void searchUsername(string identifier) {
        if (usernames.count(identifier)) {
            cout << "Identifier: " << identifier << ", Username: " << usernames[identifier] << endl;
        } else {
            cout << "Identifier not found." << endl;
        }
    }

    // Update a username for an identifier
    void updateUsername(string identifier, string newUsername) {
        if (usernames.count(identifier)) {
            usernames[identifier] = newUsername;
            cout << "Username updated successfully." << endl;
        } else {
            cout << "Identifier not found." << endl;
        }
    }
};

// Function to hide input when entering a username
string enterUsername() {
    string username;
    char ch;
    cout << "Enter username: ";
    while ((ch = _getch()) != 13) { // 13 is ASCII value of Enter
        username.push_back(ch);
        cout << '*'; // Mask the input with *
    }
    cout << endl;
    return username;
}

// Function to display the menu
void displayMenu65() {
    cout << "Username Manager Menu:" << endl;
    cout << "0. Return to main menu" << endl;
    cout << "1. Generate a new username" << endl;
    cout << "2. Search for a username" << endl;
    cout << "3. Update a username" << endl;
    cout << "4. Display all usernames" << endl;
    cout << "5. Exit" << endl;
    cout << "6. Exit without saving" << endl;
    cout << "Enter your choice: ";
}

// Username generation function
string generateUsername(int length, bool useNumbers, bool useSpecialChars) {
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (useNumbers) {
        chars += "0123456789";
    }
    if (useSpecialChars) {
        chars += "._";
    }

    string username = "";
    srand(time(0)); // seed random number generator
    for (int i = 0; i < length; i++) {
        username += chars[rand() % chars.length()];
    }
    return username;
}

void main4() {
    system("cls");
    UsernameManager usernameManager;

    system("cls");
    usernameManager.loadUsernamesFromFile();

    int choice;
    while (true) {
        displayMenu65();
        if (!(cin >> choice)) {
            cout << "Invalid choice. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
            case 0: {
                return ;
            }
            case 1: {
                int length;
                bool useNumbers, useSpecialChars;

                cout << "Enter the length of the username: ";
                cin >> length;

                cout << "Do you want to include numbers in the username? (y/n): ";
                char numChoice;
                cin >> numChoice;
                useNumbers = (numChoice == 'y');

                cout << "Do you want to include special characters in the username? (y/n): ";
                char specialChoice;
                cin >> specialChoice;
                useSpecialChars = (specialChoice == 'y');

                string identifier;
                cout << "Enter an identifier (e.g., email or ID): ";
                cin.ignore();
                getline(cin, identifier);

                string username = generateUsername(length, useNumbers, useSpecialChars);
                cout << "Generated username: " << username << endl << endl;
                usernameManager.addUsername(identifier, username);

                break;
            }
            case 2: {
                string identifier;
                cout << "Enter an identifier to search: ";
                cin >> identifier;
                usernameManager.searchUsername(identifier);
                system("pause");
                system("cls");

                break;
            }
            case 3: {
                string identifier, newUsername;
                cout << "Enter an identifier to update: ";
                cin >> identifier;
                cout << "Enter a new username: ";
                cin >> newUsername;
                usernameManager.updateUsername(identifier, newUsername);
                break;
            }
            case 4: {
                usernameManager.displayUsernames();
                break;
            }
            case 5: {
                usernameManager.storeUsernamesToFile();
                return ;
            }
            case 6: {
                cout << "Exiting without saving..." << endl;
                return ;
            }
            case 28:
            {
                string filePath = "Enter your file path"; // Replace with your file's path
                openFileLocation(filePath);
                system("cls");
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return ;
}

void displayMainMenu() {
    system("cls");
    int choice;
    do {
        system("cls");
        cout << "Main Menu:" << endl;
        cout << "1. Password Manager" << endl;
        cout << "2. Phonebook Manager" << endl;
        cout << "3. To Do List" << endl;
        cout << "4. Username Manager" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid choice. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            main3();
            break;
        case 2:
            main2();
            break;
        case 3:
            main1();
            break;
        case 4:
            main4();
            break;
        case 5:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 5);
}

int main(){
    displayMainMenu();
    return 0;

}
