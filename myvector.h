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


    /**
     * @brief binarySearch, notice the array must be sorted.
     * @param value, the value to search for
     * @return index
     */
    int binarySearch(int value) const {
        bool found = false;

        int index = -1,
            first = 0,
            last = this->size - 1,
            middle;

        while (first <= last && !found) {
            middle = (first + last) / 2;
            if (this->myArr[middle] == value) {
                found = true;
                index = middle;
            } else if (value > arr[middle]) {
                first = middle + 1;
            } else {
                last = middle + 1;
            }
        }

        return index;
    }

    int linearSearch(T* value) {
        bool found = false;
        int index = -1;

        for (unsigned int i = 0; i < this->size && !found; i++) {
            if (this->myArr[i] == *value) {
                found = true;
                index = i;
            }
        }
        return index;
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
        //if (i < size) {
            return *this->myArr[i];
        //}
    }

    const T& operator[](unsigned int i) const {
        return this->myArr[i];
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
