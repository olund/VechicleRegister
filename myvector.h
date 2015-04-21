#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <string>
#include <iostream>

using namespace std;

template<typename T>
class MyVector {
public:

    MyVector() {
        this->capacity = 20;
        this->size = 0;

        this->myArr = new T*[capacity];

        // Set all elements in the array to nullptr;
        for (int i = 0; i < this->capacity; i++) {
            this->myArr[i] = nullptr;
        }
    }

    ~MyVector() {
        // Delete the objects in the array and set the elements to nullptr.
        for (int i = 0; i < this->capacity; i++) {
            if (this->myArr != nullptr) {
                delete this->myArr[i];
                this->myArr[i] = nullptr;
            }
        }
        // Delete the actual array.
        delete [] this->myArr;
        this->myArr = nullptr;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }

    void addLast(T obj) {
        this->expandArray();
        this->myArr[this->size++] = new T(obj);
    }

    void addFirst(T obj) {
        this->expandArray();

        // Copy reference to the first element.
        T temp = *this->myArr[0];
        delete this->myArr[0];
        this->myArr[0] = new T(obj);
        this->myArr[this->size++] = new T(temp);
    }

    void print() {
        for (int i = 0; i < this->size; i++) {
            cout << "Position in array: " << i << endl;
            cout << this->myArr[i]->toString() << endl;
            cout << endl;
        }

    }

private:
    void expandArray() {
        if (this->size >= this->capacity) {

        }
    }

    T **myArr;
    int size;
    int capacity;
};

#endif // MYVECTOR_H
