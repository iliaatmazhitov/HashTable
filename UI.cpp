//
// Created by Ilya Atmazhitov.
//

#include <iostream>
#include <limits>
#include <string>
#include "KeySpace.h"
#include "Person.h"

const string BLUE = "\033[34m";
const string GREEN = "\033[32m";
const string RED = "\033[31m";
const string YELLOW = "\033[33m";
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";



void printMenu() {
    cout << BLUE << BOLD << UNDERLINE << "Hash Table Menu:" << RESET << endl;
    cout << YELLOW << "1. " << RESET << "Insert item" << endl;
    cout << YELLOW << "2. " << RESET << "Get item" << endl;
    cout << YELLOW << "3. " << RESET << "Search key" << endl;
    cout << YELLOW << "4. " << RESET << "Delete release" << endl;
    cout << YELLOW << "5. " << RESET << "Delete key" << endl;
    cout << YELLOW << "6. " << RESET << "Print table" << endl;
    cout << YELLOW << "0. " << RESET << "Exit" << endl;
    cout << BLUE << BOLD << "Enter your choice: " << RESET;
}


void runMenu() {
    HashTable<Person> table(10);
    int menu_choice;
    while (true) {
        printMenu();
        if (!(cin >> menu_choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid input. Please enter a number." << RESET << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (menu_choice) {
            case 1: {  // Insert item
                string name, series, number, key;
                int age;

                cout << "Enter name: ";
                getline(cin, name);

                cout << "Enter age: ";
                while (!(cin >> age)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "Invalid age. Please enter a number: " << RESET;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter passport series: ";
                getline(cin, series);

                cout << "Enter passport number: ";
                getline(cin, number);

                cout << "Enter key: ";
                getline(cin, key);

                Person person(name, age, series.c_str(), number.c_str());

                try {
                    table.Insert(key.c_str(), person);
                    cout << GREEN << "Item inserted successfully." << RESET << endl;
                } catch (const invalid_argument& e) {
                    cout << RED << "Error: " << e.what() << RESET << endl;
                }
                break;
            }
            case 2: {  // Get item
                string key;
                int release;

                cout << "Enter key: ";
                getline(cin, key);

                cout << "Enter release: ";
                while (!(cin >> release)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "Invalid release. Please enter a number: " << RESET;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                try {
                    Person person = table.Get(key.c_str(), release);
                    cout << GREEN << "Item found: " << person << RESET << endl;
                } catch (const exception& e) {
                    cout << RED << "Error: Item not found." << RESET << endl;
                }
                break;
            }
            case 3: {  // Search key
                string key;
                cout << "Enter key to search: ";
                getline(cin, key);
                table.Search(key.c_str());
                break;
            }
            case 4: {  // Delete release
                string key;
                int release;

                cout << "Enter key: ";
                getline(cin, key);

                cout << "Enter release to delete: ";
                while (!(cin >> release)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "Invalid release. Please enter a number: " << RESET;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                table.DelRelease(key.c_str(), release);
                cout << GREEN << "Release deleted (if it existed)." << RESET << endl;
                break;
            }
            case 5: {  // Delete key
                string key;
                cout << "Enter key to delete: ";
                getline(cin, key);

                table.DelKey(key.c_str());
                cout << GREEN << "Key deleted (if it existed)." << RESET << endl;
                break;
            }
            case 6: {  // Print table
                table.PrintTable();
                break;
            }
            case 0: {  // Exit
                cout << "Exiting program." << endl;
                return;
            }
            default: {
                cout << RED << "Invalid choice. Please try again." << RESET << endl;
                break;
            }
        }
        cout << endl;
    }
}