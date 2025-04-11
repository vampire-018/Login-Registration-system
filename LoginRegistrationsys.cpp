#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void login();
void registration();
void forgot();

int main() {
    int choice;
    while (true) {
        cout << "\t\t\t_________________________________________\n\n\n";
        cout << "\t\t\t          Welcome to the Login Page      \n\n\n";
        cout << "\t\t\t_________        MENU        ____________\n\n\n";
        cout << "\t|  Press 1 to LOGIN                     |\n";
        cout << "\t|  Press 2 to REGISTER                  |\n";
        cout << "\t|  Press 3 if you FORGOT your PASSWORD  |\n";
        cout << "\t|  Press 4 to EXIT                      |\n";
        cout << "\n\t\t\t Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                registration();
                break;
            case 3:
                forgot();
                break;
            case 4:
                cout << "\t\t\tThank you! Goodbye.\n";
                return 0;
            default:
                cout << "\t\t\tPlease select a valid option.\n\n";
        }
    }
}

void login() {
    string userId, password, id, pass;
    bool found = false;

    // system("cls"); // Uncomment if on Windows
    cout << "\t\t\tPlease enter the username and password:\n";
    cout << "\t\t\tUSERNAME: ";
    cin >> userId;
    cout << "\t\t\tPASSWORD: ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            found = true;
            break;
        }
    }
    input.close();

    if (found) {
        cout << "\n\t\t\tLogin successful!\n";
    } else {
        cout << "\n\t\t\tLogin error! Please check your username and password.\n";
    }
}

void registration() {
    string ruserId, rpassword;

    // system("cls");
    cout << "\t\t\tEnter a username: ";
    cin >> ruserId;
    cout << "\t\t\tEnter a password: ";
    cin >> rpassword;

    ofstream out("records.txt", ios::app);
    out << ruserId << " " << rpassword << endl;
    out.close();

    // system("cls");
    cout << "\n\t\t\tRegistration successful!\n";
}

void forgot() {
    int option;
    // system("cls");
    cout << "\t\t\tForgot Password Menu\n";
    cout << "\tPress 1 to search your password by username\n";
    cout << "\tPress 2 to return to main menu\n";
    cout << "\t\t\tEnter your choice: ";
    cin >> option;

    if (option == 1) {
        string suserId, id, pass;
        bool found = false;

        cout << "\n\t\t\tEnter your remembered username: ";
        cin >> suserId;

        ifstream input("records.txt");
        while (input >> id >> pass) {
            if (id == suserId) {
                found = true;
                break;
            }
        }
        input.close();

        if (found) {
            cout << "\n\t\t\tAccount found!\n";
            cout << "\t\t\tYour password is: " << pass << "\n";
        } else {
            cout << "\n\t\t\tSorry, account not found!\n";
        }
    } else if (option == 2) {
        return;
    } else {
        cout << "\t\t\tInvalid choice. Try again.\n";
    }
}
