#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
class MyVector {
public:

    MyVector() {
        this->capacity = 20;
        this->size = 0;

        this->myArr = new T*[capacity];

        // Set all elements in the array to nullptr;
        for (unsigned int i = 0; i < this->capacity; i++) {
            this->myArr[i] = nullptr;
        }
    }

    ~MyVector() {
        // Delete the objects in the array and set the elements to nullptr.
        for (unsigned int i = 0; i < this->capacity; i++) {
            if (this->myArr != nullptr) {
                delete this->myArr[i];
                this->myArr[i] = nullptr;
            }
        }
        // Delete the actual array.
        delete [] this->myArr;
        this->myArr = nullptr;
    }

    bool removeAt(unsigned int pos) {

        if (pos >= this->size)
            return false;

        delete this->myArr[pos];

        this->myArr[pos] = this->myArr[this->size - 1];
        this->myArr[this->size - 1] = nullptr;
        this->size--;

        return true;
    }

    bool clear() {
        for (unsigned int i = 0; i < this->size; i++) {
            delete this->myArr[i];
            this->myArr[i] = nullptr;
            this->size--;
        }
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }

    void add(T *obj) {
        this->expandArray();
        this->myArr[this->size++] = obj;
    }

    void add(T &elem) {
        this->expandArray();
        this->myArr[this->size++] = new T(elem);
    }

    void update(T *obj, int pos) {
        delete this->myArr[pos];
        this->myArr[pos] = obj;
    }

    string toString() const {
        stringstream ss;

        for (unsigned int i = 0; i < this->size; i++) {
            ss << this->myArr[i]->toString() << endl;
        }

        return ss.str();
    }

    void print() {
        for (unsigned int i = 0; i < this->size; i++) {
            cout << "Position in array: " << i << endl;
            cout << this->myArr[i]->toString() << endl;
            cout << endl;
        }
    }

    // Operators..

    T& operator[](unsigned int i) {
        return *this->myArr[i];
    }

    const T& operator[](unsigned int i) const {
        return this->myArr[i];
    }

    T& elementAt(unsigned int i) const {
        return *this->myArr[i];
    }

    T*& getAt(int pos) {
        return myArr[pos];
    }


private:
    void expandArray() {
        if(size >= capacity) {
            T** temp = this->myArr;
            capacity += 10; // Should expand it more maybe..
            this->myArr = new T*[capacity];

            // copy address
            for (unsigned int i = 0; i < size; i++) {
                 this->myArr[i] = temp[i];
            }
            // set other elements to nullptr
            for (unsigned int i = size; i < capacity; i++) {
                 this->myArr[i] = nullptr;
            }
            delete [] temp;
        }
    }


    T **myArr;
    unsigned int size;
    unsigned int capacity;
};

#endif // MYVECTOR_H
