//
// Created by Ilya Atmazhitov.
//

#ifndef LAB3B_PERSON_H
#define LAB3B_PERSON_H

#include <string>
#include <stdexcept>
#include <cstring>
#include "iostream"

struct Passport {
    char* series;
    char* number;

    Passport(const char* series = nullptr, const char* number = nullptr) {
        const char* defaultValue = "UNDEFINED";

        if (series) {
            this->series = new char[strlen(series) + 1];
            strcpy(this->series, series);
        } else {
            this->series = new char[strlen(defaultValue) + 1];
            strcpy(this->series, defaultValue);
        }

        if (number) {
            this->number = new char[strlen(number) + 1];
            strcpy(this->number, number);
        } else {
            this->number = new char[strlen(defaultValue) + 1];
            strcpy(this->number, defaultValue);
        }
    }

    ~Passport() {
        delete[] series;
        delete[] number;
    }
};

using namespace std;

class Person {
public:
    string name;
    int age;
    Passport* ID;

    Person(string name, int age, const char* ser = nullptr, const char* num = nullptr): name(name), age(age) {
        ID = new Passport(ser, num);
    }

    ~Person() {
        delete ID;
    }

    Person(const Person& other): name(other.name), age(other.age) {
        ID = new Passport(other.ID->series, other.ID->number);
    }

    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
            delete ID;
            ID = new Passport(other.ID->series, other.ID->number);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& c) {
        os << "(Name, Age): " << "{" << c.name << ", " << c.age << "}" << "; (Passport): " << "{" << c.ID->series << ", " << c.ID->number << "}";
        return os;
    }

    bool operator==(const Person& other) const {
        return (other.age == age && other.name == name &&
                strcmp(ID->series, other.ID->series) == 0 &&
                strcmp(ID->number, other.ID->number) == 0);
    }
};

#endif //LAB3B_PERSON_H