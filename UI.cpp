//
// Created by Ilya Atmazhitov.
//

#include "KeySpace.h"
#include <iostream>
#include <limits>

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
    printMenu();
}