//
// Created by Ilya Atmazhitov.
//

#ifndef LAB3A_KEYSPACE_H
#define LAB3A_KEYSPACE_H

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
struct Node {
    int release;
    T *info;
    Node *next;

    Node(int release, T data, Node* next = nullptr): release(release), info(new T(data)), next(next) {}

    ~Node() {
        delete info;
    }
};

template <class T>
struct KeySpace {
    char* key;
    Node<T> *node;
    KeySpace *next;

    KeySpace(const char* key, Node<T>* node = nullptr, KeySpace* next = nullptr): node(node), next(next) {
        this->key = new char[strlen(key) + 1];
        strcpy(this->key, key);
    }

    ~KeySpace() {
        delete[] key;
        Node<T>* current = node;
        while(current != nullptr) {
            Node<T>* old_node = current;
            current = current->next;
            delete old_node;
        }
        if (next != nullptr) {
            delete next;
        }
    }
};

template <class T>
class HashTable {
private:
    KeySpace<T> **ks;
    int msize; // capacity
    int csize;

public:
    HashTable(int size): msize(size), csize(0) {
        ks = new KeySpace<T> *[msize];
        for (int i = 0; i < msize; ++i) {
            ks[i] = nullptr;
        }
    }

    ~HashTable() {
        Clear();
    }

    void Clear() {
        for (int i = 0; i < msize; i++) {
            KeySpace<T>* current = ks[i];
            while (current != nullptr) {
                KeySpace<T>* old = current;
                current = current -> next;
                delete old;
            }
        }
        delete[] ks;
    }

    unsigned int Hash(const char* str) {
        unsigned long i = 0;
        for (int j=0; str[j]; j++)
            i += str[j];
        return i % msize;
    }

    void Insert(const char* data,  T & item) {
        if (data == nullptr || data[0] == '\0') {
            throw invalid_argument("Invalid key");
        }

        if ((float)csize / msize > 0.5) {
            Resize();
        }

        int index = Hash(data);
        KeySpace<T>* current = ks[index];

        while (current != nullptr) {
            if (strcmp(current->key, data) == 0) {
                Node<T>* node = current->node;
                while (node != nullptr) {
                    if (*(node->info) == item) {
                        throw invalid_argument("Item already exists");
                    }
                    node = node->next;
                }

                int new_release = 1;
                if (current -> node != nullptr) {
                    new_release = current -> node -> release + 1;
                }

                Node<T>* newNode = new Node<T>(new_release, item, current->node);
                current->node = newNode;
                return;
            }
            current = current->next;
        }

        // If we didn't find a key
        Node<T>* newNode = new Node(1, item);
        KeySpace<T>* newKS = new KeySpace<T>(data, newNode, ks[index]);
        ks[index] = newKS;
        csize++;
    }

    void Resize() {
        int newSize = msize * 2;
        KeySpace<T>** newKs = new KeySpace<T>*[newSize];
        for (int i = 0; i < newSize; ++i) {
            newKs[i] = nullptr;
        }

        for (int i = 0; i < msize; ++i) {
            KeySpace<T>* current = ks[i];
            while (current != nullptr) {
                int newIndex = 0;
                for (int j = 0; current->key[j]; j++)
                    newIndex += current->key[j];
                newIndex %= newSize;

                current->next = newKs[newIndex];
                newKs[newIndex] = current;

                current = current -> next;
            }
        }


        delete[] ks;
        ks = newKs;
        msize = newSize;
    }


    T Get(const char* data, int release) {
        int index = Hash(data);
        KeySpace<T>* current = ks[index];

        while (current != nullptr) {
            if (strcmp(current->key, data) == 0) {
                Node<T>* node = current->node;
                while (node != nullptr) {
                    if (node->release == release) {
                        return *(node->info); // Возвращаем значение
                    }
                    node = node->next;
                }
            }
            current = current->next;
        }

    }

    void Search(const char* data) {
        if (data == nullptr || data[0] == '\0') {
            throw invalid_argument("Invalid key");
        }

        int index = Hash(data);
        KeySpace<T>* current = ks[index];
        bool found = false;

        while (current != nullptr) {
            if (strcmp(current->key, data) == 0) {
                found = true;
                cout << "Key found: " << data << endl;
                Node<T>* node = current->node;
                while (node != nullptr) {
                    cout << "        Release: " << node->release << ", Value: " << *(node->info) << endl;
                    node = node->next;
                }
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Key not found: " << data << endl;
        }
    }

    void DelRelease(const char* data, int release) {
        int index = Hash(data);
        KeySpace<T>* current = ks[index];

        while (current != nullptr) {
            if (strcmp(current->key, data) == 0) {
                Node<T>* node = current->node;
                Node<T>* prevNode = nullptr;

                while (node != nullptr) {
                    if (node->release == release) {
                        if (prevNode == nullptr) {
                            current->node = node->next;
                        } else {
                            prevNode->next = node->next;
                        }
                        delete node;

                        Node<T>* updateNode = (prevNode == nullptr) ? current->node : prevNode->next;
                        while (updateNode != nullptr) {

                            updateNode = updateNode->next;
                        }

                        return;
                    }
                    prevNode = node;
                    node = node->next;
                }

            }
            current = current->next;
        }

    }

    void DelKey(const char* data) {
        int index = Hash(data);
        KeySpace<T>* current = ks[index];
        KeySpace<T>* prev = nullptr;

        while (current != nullptr) {
            if (strcmp(current -> key, data) == 0) {

                // Head node deletion
                if (current == ks[index]) {
                    ks[index] = current -> next;
                } else {
                    prev -> next = current -> next;
                }

                delete current;
                return;
            }

            prev = current;
            current = current -> next;
        }
        return;

    }

    void PrintTable() const {
        const string BLUE = "\033[34m";
        const string RESET = "\033[0m";
        const string BOLD = "\033[1m";
        const string UNDERLINE = "\033[4m";

        cout << BLUE << BOLD << UNDERLINE << "Hash Table Contents:" << RESET << endl << endl;

        for (int i = 0; i < msize; ++i) {
            cout << BLUE << "[" << setw(3) << i << "] ";

            if (ks[i] == nullptr) {
                cout << "└── " << RESET << "empty" << endl;
            } else {
                KeySpace<T>* current = ks[i];
                string prefix = "";
                while (current != nullptr) {
                    cout << RESET << prefix << BLUE << "└── " << RESET << "Key: " << current->key << endl;

                    Node<T>* node = current->node;
                    string node_prefix = prefix + BLUE + "    ";
                    while (node != nullptr) {
                        cout << RESET << node_prefix << BLUE << "├── " << RESET
                                  << "Release: " << setw(3) << node->release
                                  << ", Value: " << *(node->info) << endl;
                        node = node->next;
                    }

                    current = current->next;
                    prefix += BLUE + "    ";
                }
            }
            cout << endl;
        }
    }

};

#endif //LAB3A_KEYSPACE_H
